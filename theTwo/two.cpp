#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include <queue>
#include <cstring>
using namespace std;
int N,K;
int result[100001];
int main()
{
	freopen("F:/input.txt","r",stdin);
	int min=1;

	while (cin>>N>>K)
	{
		int sum = 0;
		int remain = 0;
		int hi,ho;
		hi=ho=0;
		for (int i = 1; i <= N; i++)
		{
			cin>>result[i];
			sum+=0;
		}
		int min=sum/2;

		while (true)
		{
			hi=ho=0;
			remain = 0;
			
			for(int i =1;i<=N;++i)
			{
				if((min+remain)<=result[i])
				{
					hi++;
					remain = 0;
				}
				else
				{
					ho++;
					remain=(min+remain)-result[i];
				}
			}
			if(ho>hi)
			{
				cout<<min;
				break;
			}
			min++;
		}

	}
	return 0;
}