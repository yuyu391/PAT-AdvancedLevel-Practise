/******************************************************************************
* Filename  : 1004. Counting Leaves.cpp
* author    : yuyu391
* tools     : UltraEdit 24.10.0.32
* compile   : gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.4)
* time      : 2018.01
******************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>         //cout << fixed << setprecision(1);//小数点保留一位
#include <functional>      //greater<int>() less<int>()
#include <vector>
#include <stack>
#include <cmath>
#include <map>
#include <queue>
using namespace std;

class CountLeaves {
private:
	int mNumNode;
	int mNonLeafNode;
	int mID;
	int mK;
	map<int, vector<int>> mMap;
	queue<int> mQueue;
public:
	CountLeaves(int n, int m){
		mNumNode = n;
		mNonLeafNode = m;
		initVmap();
	}
private:
	void initVmap() {
		vector<int> tmp;
		tmp.push_back(0);
		for (int i=1; i<=mNumNode; i++)
		{
			mMap.insert(map<int, vector<int>>::value_type(i, tmp));
		}
	}
public:
	void inputValue() {
		for (int i=0; i<mNonLeafNode; i++)
		{
			cin >> mID >> mK;
			int tmpId;
			vector<int> tmpVectorId;
			for (int j=0; j<mK; j++)
			{
				cin >> tmpId;
				tmpVectorId.push_back(tmpId);
			}
			mMap[mID] = tmpVectorId;
		}
	}
	void solves() {
		mQueue.push(1);//把根节点插入队列
		bool spaceflag = true;
		while (mQueue.size()) {
			int tar = mQueue.size();
			int cnt = 0;
			while (tar--) {
				int idNode = mQueue.front();
				if(*mMap[idNode].begin()==0)cnt++;
				else 
					for (vector<int>::iterator it = mMap[idNode].begin();it!=mMap[idNode].end();++it)
						mQueue.push(*it);
				mQueue.pop();
			}
			if(spaceflag)spaceflag=false;
			else cout << " ";
			cout << cnt; 
		}
	}
};


void test() 
{
	CountLeaves *familytree = NULL;
	int N, M;
	cin >> N >> M;
	familytree = new CountLeaves(N, M);
	familytree->inputValue();
	familytree->solves();
	delete familytree;
}

int main()
{
	test();
	return 0;
}
