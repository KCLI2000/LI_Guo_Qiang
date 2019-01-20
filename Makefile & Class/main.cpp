/*
#include<iostream>
#include<stdio.h>

using namespace std;
*/

#include"class.hpp"

/*class Rectangle
{
		int width;
		int height;
public:
		Rectangle (int, int);

		int area()
		{
				int a = width*height;
				return a;
		}
};

Rectangle::Rectangle (int a, int b)
{
		width = a;
		height = b;
}
*/
int main(int argc, char*argv[])
{
		int m, n;
		cin >> m >> n;
		
		Rectangle rect (m,n);
		Rectangle rectb (m+2,n+2);

		cout << "rect area:" << rect.area() << endl;
		cout << "rectb area:" << rectb.area() << endl;
		
		return 0;
}
