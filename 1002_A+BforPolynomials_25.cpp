/******************************************************************************
* Filename  : 1002_A+BforPolynomials_25.cpp
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
#include <map>
using namespace std;

void test() 
{
	int K;
	int kn;
	double an;
	bool flag;
	map<int, double, greater<int>> A;
	map<int, double, greater<int>> B;
	map<int, double, greater<int>> C;
	cin >> K;
	for (int i=0; i<K; i++)
	{
		cin >> kn >> an;
		A.insert(map<int, double>::value_type(kn, an));
		C.insert(map<int, double>::value_type(kn, an));
	}
	cin >> K;
	for (int i=0; i<K; i++)
	{
		cin >> kn >> an;
		B.insert(map<int, double>::value_type(kn, an));
		flag = false;
		for (auto &item : C)
		{
			auto &x = item.first;
			if (x == kn)
			{
				C[kn] += an;
				flag = true;
				break;
			}
		}
		if (!flag) 
			C.insert(map<int, double>::value_type(kn, an));
	}
	int size = C.size();
	for (auto &item : C) {
		auto &x = item.second;
		if (x == 0)
			size--;
	}
	cout << size;
	for (auto &item : C) 
	{
		auto &x = item.second;
		if (x == 0) continue;
		cout << " " << item.first << " " << fixed << setprecision(1) << item.second;
	}
	cout << endl;
	
}

int main()
{
	test();
	return 0;
}
/*
This time, you are supposed to find A+B where A and B are two polynomials.

Input

Each input file contains one test case. Each case occupies 2 lines, and each 
line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, 
where K is the number of nonzero terms in the polynomial, 
Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. 
It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.

Output

For each test case you should output the sum of A and B in one line, with the 
same format as the input. Notice that there must be NO extra space at the end 
of each line. Please be accurate to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 2 1.5 1 2.9 0 3.2
*/
