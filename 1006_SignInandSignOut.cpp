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
class SignInSignOut {
public:
	string mID;
	string mSignIn;
	string mSignOut;
};
class MyCompareByIn {
public:
	bool operator()(const SignInSignOut &a, const SignInSignOut &b) {
		return a.mSignIn < b.mSignIn;
	}
};
class MyCompareByOut {
public:
	bool operator()(const SignInSignOut &a, const SignInSignOut &b) {
		return a.mSignOut > b.mSignOut;
	}
};
class DayInOut {
private:
	vector<SignInSignOut> mSign;
	int mM;
public:
	DayInOut(int M) {
		mM = M;
	}
public:
	void inputValue() {
		SignInSignOut tmpsign;
		for (int i = 0; i < mM; i++)
		{
			cin >> tmpsign.mID >> tmpsign.mSignIn >> tmpsign.mSignOut;
			mSign.push_back(tmpsign);
		}
	}
	void solves() {
		sort(mSign.begin(), mSign.end(), MyCompareByIn());
		cout << mSign.begin()->mID;
		cout << " ";
		sort(mSign.begin(), mSign.end(), MyCompareByOut());
		cout << mSign.begin()->mID;
		cout << endl;
	}

};
void test() {
	DayInOut *daySign = NULL;
	int M;
	cin >> M;
	daySign = new DayInOut(M);
	daySign->inputValue();
	daySign->solves();
	delete daySign;
}

int main()
{
	test();
	return 0;
}
