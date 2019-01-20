#ifndef class_hpp
#define class_hpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Rectangle{
		int width, height;
public:
		Rectangle(int,int);
		int area()
		{
				int a = width*height;
				return a;
		}
};

#endif /*class_hpp*/
