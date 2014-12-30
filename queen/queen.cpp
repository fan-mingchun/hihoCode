#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include <queue>
#include <cstring>
using namespace std;
bool isOK(int * result,int index,int pos);
void queen(int index,int max,int& resultNum,int * result);
int main()
{
	//freopen("F:/input.txt","r",stdin);
	int num;
	while(cin>>num)
	{
		int * result = new int[num+1];
		int resultNum = 0;
		queen(0,num-1,resultNum,result);
		cout<<resultNum<<endl;
		//delete []result;
	}

	return 0;
}
void queen(int index,int max,int& resultNum,int * result)
{
	if(index == max)
	{
		for(int i = 0;i <=max;++i)
		{
			if(isOK(result,index,i))
			{
				resultNum++;
			}
		}
		return;
	}
	else
	{
		for(int i = 0;i <=max;++i)
		{
			if(isOK(result,index,i))
			{
				result[index] = i;
				queen(index+1,max,resultNum,result);
			}
		}
	}
}
bool isOK(int * result,int index,int pos)
{
	for(int i = 0;i <index;++i)
	{
		if(result[i]== pos || abs(result[i]- pos) == abs(i-index))
			return false;

	}
	return true;
}