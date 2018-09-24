#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int main()
{
	int i,j;

	srand((unsigned)time(NULL));

	for (i=1; i<=10; i++)
	{
		j=rand();
		std::cout<<"the"<<i<<"number is:"<<j<<endl;
        }

	return 0;
}

