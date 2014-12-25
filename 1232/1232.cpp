#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include <queue>
#include <cstring>
using namespace std;
#define max_node_num  1001 
char adjacMatrix[max_node_num][max_node_num];
int unionFindSet[max_node_num];
void unionInit(int sum);
void union1(int first,int second);

int find(int p);
int main()
{
	freopen("F:/input.txt","r",stdin);
	int	N,M;
	while (scanf("%d",&N) && N !=0)
	{
		memset((char*)adjacMatrix,0,max_node_num*max_node_num);
		unionInit(N);
		scanf("%d",&M);
		int num = M;
		int one,two;
		int total = N;
		while (num--)
		{
			scanf("%d%d",&one,&two);
			adjacMatrix[one][two]=1;
			adjacMatrix[two][one]=1;
		}
		for(int i = 1;i <= N;++i)
		{
			/*if(i != unionFindSet[i])
				continue;*/
			for(int j = i+1;j <=N;++j)
			{
				if(adjacMatrix[i][j])
					union1(i,j);
			}
		}
		int cur = 1;
		int result = 0;
		for(int i = 1;i <= N;++i)
		{
			if(find(i)==i)
			{
				result++;
				
			}
		}	
		printf("%d\n",result-1);
	}	
	return 0;
}
void unionInit(int sum)
{
	for(int i = 0;i <= sum;++i)
	{
		unionFindSet[i] = i;
	}
}
void union1(int first,int second)
{
	if(find(first)!= find(second))
		unionFindSet[second]= find(first);
	
}

int find(int p)
{
	int temp = p;
	while (p != unionFindSet[p])
	{
		p = unionFindSet[p];
	}
	//unionFindSet[temp] = p;
	return p;
}