#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include <queue>
#include <cstring>
using namespace std;
int N,M;
char map[201][201];
char posMap[4][4];
char pos4map[4][4][4];
int main()
{
	freopen("F:/input.txt","r",stdin);
	while (cin>>N>>M)
	{
		for(int i =1;i<=N;++i)
		{
			for(int j = 1;j <= M;++j)
			{
				cin>>map[i][j];
			}
		}
		for(int i = 1;i <=3;++i)
		{
			for(int j = 1;j <=3;++j)
			{
				cin>>posMap[i][j];
			}
		}

		for(int i = 1;i <=3;++i)
		{
			for(int j = 1;j <=3;++j)
			{
				pos4map[0][i][j] = posMap[i][j];
			}
		}
		for(int k = 1;k<4;++k)
		{
			pos4map[k][1][1]= pos4map[k-1][3][1];
			pos4map[k][1][2]= pos4map[k-1][2][1];
			pos4map[k][1][3]= pos4map[k-1][1][1];
			pos4map[k][2][1]= pos4map[k-1][3][2];
			pos4map[k][2][2]= pos4map[k-1][2][2];
			pos4map[k][2][3]= pos4map[k-1][1][2];
			pos4map[k][3][1]= pos4map[k-1][3][3];
			pos4map[k][3][2]= pos4map[k-1][2][3];
			pos4map[k][3][3]= pos4map[k-1][1][3];
		}
		bool isBreak1;
		bool isBreak2;
		bool isFirst = true;
		for(int i = 1;i <N-1;++i)
		{
			for(int j = 1;j <M-1;++j)
			{
				isBreak1= false;
				isBreak2 = false;
				for(int posNum=0;posNum<4;++posNum)
				{
					isBreak1= false;
					
					for(int m = 1;m<=3;++m)
					{
						
						if(isBreak1)
								break;
						for(int n = 1;n<=3;++n)
						{
							if(isBreak1)
								break;
							if(map[i+m-1][j+n-1] != pos4map[posNum][m][n])
							{
								isBreak1= true;
								break;
							}
						}
					}
					if(!isBreak1)
					{
						cout<<i+1<<" "<<j+1<<endl;
						/*if(isFirst)
						{
							cout<<i+1<<" "<<j+1;
							isFirst = false;
						}
						else
						{
							cout<<""<<i+1<<" "<<j+1;
						}*/
						isBreak2 = true;
						break;
					}
				}
			}
		}
	}
	return 0;
}