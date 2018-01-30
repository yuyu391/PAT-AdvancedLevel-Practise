/******************************************************************************
* Filename  : 1001_A+B_Format_20 1001_A+B_Format_20.cpp
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
using namespace std;

void test() 
{
    stack<int> s;
    int A, B, sum;
    int flag;

    cin >> A >> B;
    sum = A + B;
    flag = (sum>=0?1:0);
    sum = abs(sum);
    
    if (sum == 0) 
    {
        cout << "0" << endl;
        return;
    }
    
    while(sum > 0)
    {
        int temp = sum % 10;
        s.push(temp);
        sum = sum / 10;
    }
    
    int len = s.size();
    int point = len % 3;
    
    if (!flag)
    {
        cout << "-";
    }
    
    int k = 0;
    while(s.size() != 0)
    {
        k++;
        cout << s.top();
        s.pop();
        if ((abs(k-point))%3 == 0 && k != len) 
        {
            cout << ",";
        }
    }
    cout << endl;
}

int main()
{
	test();
	return 0;
}
/*
Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input
-1000000 9
Sample Output
-999,991
*/