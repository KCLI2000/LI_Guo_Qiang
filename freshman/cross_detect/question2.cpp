#include<iostream>
#include<math.h>
using namespace std;

double find_delta(double a, double b, double c)
{
		double delta = (b*b) - (4*a*c);
		return delta;
}

bool check_input(double a)
{
		if(a == 0)
		{
				return false;
		}
		else
				return true;
}

bool if_exist(double a, double b, double c)
{
		double delta = find_delta(a, b, c);
		if(delta < 0)
				return false;
		else
				return true;
}

double find_x1(double a, double b, double c)
{
		double delta = find_delta(a, b, c);
		double x1;
		x1 = (-b + sqrt(delta)) / (2*a);
		return x1;
}

double find_x2(double a, double b, double c)
{
		double delta = find_delta(a, b, c);
		double x2;
		x2 = (-b - sqrt(delta)) / (2*a);
		return x2;
}

int main()
{
		double a, b, c;
		cout << "请输入三个系数" << endl;
		cout << "二次项系数（非0）:";
		cin >> a;
		cout << "一次项系数:";
		cin >> b;
		cout << "常数项:";
		cin >> c;

		if(!check_input(a) || !if_exist(a, b, c))
		{
				cerr << "bad input" << endl;
				if(!check_input(a))
				{
						cerr << "a must not be 0" << endl;
						return -1;
				}
				else
				{
						cerr << "answer do not exist" << endl;
						return -1;
				}
		}
		
		// cout << "delta= " << find_delta(a, b, c) << endl;
		cout << "x1= " << find_x1(a, b, c) << endl;
		cout << "x2= " << find_x2(a, b, c) << endl;

		return 0;
}


		


