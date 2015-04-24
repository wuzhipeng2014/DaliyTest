// Ch6.54.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int fun(int a, int b)
{
	return  a + b;
}
int addf(int a, int b)
{
	return a + b;
}
int minusf(int a, int b)
{
	return a - b;
}
int mutif(int a, int b)
{
	return a*b;
}
int devidef(int a, int b)
{
	return a / b;
}

//typedef int pfun(int, int);
using pfun = int(*)(int, int);
using pfun1 = decltype(fun)*;
typedef int(*pfun)(int, int);

struct ops
{
	ops(){ lhs = 0; rhs = 0; op = '\0'; }
	ops(int l, int r, char o):lhs(l),rhs(r),op(o){}
	int lhs, rhs;
	char op;
};

ops getvalues()
{
	
		cout << "please input s expression ..." << endl;
		string s;
		cin >> s;
		if (s=="quit")
		{
			system("exit");
		}
		int i = 0;
		while (i++ < s.length())
		{
			if (!isdigit(s[i]))
				break;
		}
		char opr = s[i];
		int lhs = atoi(s.substr(0, i).c_str());
		int rhs = atoi(s.substr(i+1).c_str());
		return ops(lhs, rhs, opr);
	
		
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*vector<int(*)(int,int)> pv;
	int(*ptemp)(int, int) = fun;
	pv.push_back(ptemp);
	pfun1 p2 = fun;
	vector<pfun1> pv1;
	pv1.push_back(ptemp);
	auto re=pv[0](3,5);
	pv1.push_back(p2);*/


	pfun1 f1 = addf, f2 = minusf, f3 = mutif;
	pfun f4 = devidef;
	vector<pfun1> fsv = { f1, f2, f3, f4 };
	while (true)
	{
		auto re = getvalues();
		int result = 0;
		char temp = re.op;
		switch (temp)
		{
		case'+':
			result = fsv[0](re.lhs, re.rhs);
			break;
		case'-':
			result = fsv[1](re.lhs, re.rhs);
			break;
		case '*':
			result = fsv[2](re.lhs, re.rhs);
			break;
		case '/':
			result = fsv[3](re.lhs, re.rhs);
			break;
		default:
			result = -1;
			cout << "input error, do you want to exit? \t press y to exit " << endl;
			string stmp;
			cin >> stmp;
			if (stmp=="y")
			{
				return 0;
			}
			else
			{
				break;
			}
				
		}
		cout << "result= " << result << endl;
	}
	


		return 0;
}

