#include<iostream>
using namespace std;

int find_GCF(int a, int b)
{
		if(a%b == 0)
				return b;
		else
				return find_GCF(b, a%b);
}
		
		
int find_LCM(int a, int b)
{
		int LCM;
		LCM = (a * b)/find_GCF(a, b);
		return LCM;
}


int main()
{
		int a, b;
		
		cout << "请输入两个数" << endl << "a:";
		cin >> a;
		cout << "b:";
		cin >> b;
		
		if(a <= 0 || b <= 0)
		{
				cerr << "bad input (both a & b should be larger than 0)" << endl;
				return -1;
		}

		int LCM = find_LCM(a, b);
		int GCF = find_GCF(a, b);
		
		cout << "最大公因数:" << GCF << endl;
		cout << "最小公倍数:" << LCM << endl;
		
		return 0;
}
