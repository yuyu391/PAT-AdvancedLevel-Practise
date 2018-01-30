/******************************************************************************
* Filename  : 
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

class SpellitRight {
private:
	string mNum;
	int mSum;
public:
	SpellitRight(string m) {
		mNum = m;
		mSum = 0;
	}
public:
	void solves() {
		for (size_t i = 0; i < mNum.length(); i++)
		{
			mSum += mNum[i] - '0';
		}
	}
	void printAns() {
		bool spaceflag = true;
		string word = to_string(mSum);
		for (size_t i = 0; i < word.length(); i++)
		{
			if (spaceflag) spaceflag = false;
			else cout << " ";
			switch (word[i])
			{
			case '0':
				cout << "zero";
				break;
			case '1':
				cout << "one";
				break;
			case '2':
				cout << "two";
				break;
			case '3':
				cout << "three";
				break;
			case '4':
				cout << "four";
				break;
			case '5':
				cout << "five";
				break;
			case '6':
				cout << "six";
				break;
			case '7':
				cout << "seven";
				break;
			case '8':
				cout << "eight";
				break;
			case '9':
				cout << "nine";
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
};
void test() {
	SpellitRight *sp = NULL;
	string N;
	cin >> N;
	sp = new SpellitRight(N);
	sp->solves();
	sp->printAns();
	delete sp;
}

int main()
{
	test();
	return 0;
}
