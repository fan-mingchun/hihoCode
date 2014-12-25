#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main()
{
	freopen("F:/input.txt","r",stdin);
	int a,b;
	while (cin>>a>>b)
	{
		cout<<(a+b)<<endl;
	}
	return 0;
}