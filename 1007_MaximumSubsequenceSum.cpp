/******************************************************************************
* Filename  : 1007. Maximum Subsequence Sum (25)
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

void test() {
	vector<int> v;
	int K;
	int tempInt;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> tempInt;
		v.push_back(tempInt);
	}
	int sum = -1;
	int tmp, start, end;
	for (int i = 0; i < K; i++)
	{
		tmp = 0;
		for (int j = i; j < K; j++)
		{
			tmp += v[j];
			if (tmp > sum)
			{
				sum = tmp;
				start = v[i];
				end = v[j];
			}
		}
	}
	if (sum < 0)
	{
		cout << "0 " << v[0] << " " << v[K - 1] << endl;;
	}
	else {
		cout << sum << " " << start << " " << end << endl;
	}
}
void test_dynamie() {
	int n, flag = 0, sum = -1, temp = 0, left = 0, right = 0, tempindex = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> *(int*)&v[i];
		if (v[i]>=0)
		{
			flag = -1;
		}
		temp = temp + v[i];
		if (temp > sum)
		{
			sum = temp;
			left = tempindex;
			right = i;
		}
		else if (temp < 0)
		{
			temp = 0;
			tempindex = i + 1;
		}
	}
	if (flag == 0)
	{
		cout << "0 " << v[0] << " " << v[n - 1] << endl;
	}
	else
	{
		cout << sum << " " << v[left] << " " << v[right] << endl;
	}
	


}

int main()
{
	test();
	return 0;
}
