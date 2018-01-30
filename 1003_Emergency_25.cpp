/******************************************************************************
* Filename  : 1003_Emergency_25.cpp
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
#include <climits>
#include <cstring>
#include <cstdio>
using namespace std;

class Dijkstra {
public:
	Dijkstra(int numofcity, int mountofroad, int mstart, int mend)
	{
		mNumOfcity = numofcity;
		mMountOfRoad = mountofroad;
		mStart = mstart;
		mEnd = mend;
	}
public:
	void setValuse()
	{
		for (int i=0; i<mNumOfcity; i++)
		{
			cin >> teams[i];
		}
		for (int i=0; i<mNumOfcity; i++)
		{
			dist[i] = MAXINF;
			for (int j=0; j<mNumOfcity; j++)
			{
				mp[i][j] = MAXINF;
			}
		}
		for (int i=0; i<mMountOfRoad; i++)
		{
			int c1, c2, L;
			cin >> c1 >> c2 >> L;
			mp[c1][c2] = L;
			mp[c2][c1] = L;
		}
	}
	void solves()
	{
		amount[mStart] = teams[mStart];
		dist[mStart] = 0;
		pathcount[mStart] = 1;
		
		while (true) {
			int u, dmin = MAXINF;
			for (int i=0; i<mNumOfcity; i++)
			{
				if (v[i]==0 && dist[i]<dmin) 
				{
					dmin = dist[i];
					u = i;
				}
			} 
			if (dmin == MAXINF || u == mEnd) 
			{
				break;
			}
			v[u] = 1;
			for (int i=0; i<mNumOfcity; i++)
			{
				if (v[i] == 0) 
				{
					if (dist[i] > dist[u] + mp[u][i]) 
					{
						dist[i] = dist[u] + mp[u][i];
						amount[i] = amount[u] + teams[i];
						pathcount[i] = pathcount[u];
					}
					else if (dist[i] == dist[u] + mp[u][i])
					{
						pathcount[i] += pathcount[u];
						if (amount[i] < amount[u] + teams[i]) 
						{
							amount[i] = amount[u] + teams[i];
						}
					}
				}
			}
		} 
	}
	void printAns()
	{
		cout << pathcount[mEnd] << " " << amount[mEnd] << endl;
	}
private:
	enum  { MX=501, MAXINF=0x3f3f3f3f};
	int mp[MX][MX];
	int v[MX];
	int dist[MX];
	int amount[MX];
	int teams[MX];
	int pathcount[MX];
	int mNumOfcity;
	int mMountOfRoad;
	int mStart;
	int mEnd;
};
void test() 
{
	Dijkstra * dijkstra = NULL;
	int N, M, start, end;
	cin >> N >> M >> start >> end;
	dijkstra = new Dijkstra(N, M, start, end);
	dijkstra->setValuse();
	dijkstra->solves();
	dijkstra->printAns();
}

int main()
{
	test();
	return 0;
}
/*
As an emergency rescue team leader of a city, you are given a special map of your 
country. The map shows several scattered cities connected by some roads. Amount of
rescue teams in each city and the length of each road between any pair of cities
are marked on the map. When there is an emergency call to you from some other 
city, your job is to lead your men to the place as quickly as possible, and at the
mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case. For each test case, the first line contains
4 positive integers: N (<= 500) - the number of cities (and the cities are numbered 
from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are 
currently in and that you must save, respectively. The next line contains N integers,
where the i-th integer is the number of rescue teams in the i-th city. Then M lines 
follow, each describes a road with three integers c1, c2 and L, which are the pair of
cities connected by a road and the length of that road, respectively. It is guaranteed
that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest 
paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra 
space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4

*/

/*
题目描述：

抽象出来就是给你一张图，给你起点终点，着到起点到终点的所有最短路径，每个点上有一个数，
代表这个点上的搜救队的数量，要求输出这些最短路径中你能召集到的最大的搜救队的数量。

算法分析：

思路1、dijsktra

简单题，最短路径算法(e.g. Dijastra)，但是要稍微变化一下，要记录所有的的最短路径，所以
从终点回溯上去可能有多于一个的parent。那么就在每个node上面挂一个 list好了，记录所有的
parents. 得到后可以从终点DFS到起点，记录下每条最短路径上的搜救队的数量和。保存最大的那
个输出即可。

思路2、DFS

注意点：

这个题目其实就是最短路径的小小变形，注意最原始的最短路径算法通过记录每个node最短路径上
的parent来保存一条这样的最短路径，这里话就 是相当于，要多点判断，当新的路径和当前路径
相同长度时，也要记录下来，但是后面如果找到更短的，那么之前的路径就要清空，记录路径的代
码稍微注意一点就 没问题了。

*/
