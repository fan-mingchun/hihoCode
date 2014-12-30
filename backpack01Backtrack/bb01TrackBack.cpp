#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include <queue>
#include <cstring>
using namespace std;
class BackPack01
{
public:
	BackPack01(int v,int num):
		volume(v),
		backPackNum(num)
	{
		solusion = new char[backPackNum+1];
		valueArray = new int[backPackNum+1];
		weightArray = new int[backPackNum+1];
		curValue = 0;
		maxValue = 0;
		curWeight = 0;
	}
	void input(int index,int weight,int value)
	{
		weightArray[index] = weight;
		valueArray[index]  = value;
	}
	~BackPack01()
	{
		delete []solusion;
		delete []valueArray;
		delete []weightArray;
	}
	void dfs(int index)
	{
		if(index == backPackNum)
		{
			/*curWeight = 0;
			for(int i = 1;i <index;++i)
			{
				if(solusion[i])
					curWeight+=weightArray[i];
			}
			curValue = 0;
			for(int i = 1;i <index;++i)
			{
				if(solusion[i])
					curValue+=valueArray[i];
			}*/
			if((curWeight + weightArray[index]) <= volume)
			{
				if((curValue+valueArray[index])>maxValue)
					maxValue = curValue+valueArray[index];
			}
			else
			{
				if((curValue)>maxValue)
					maxValue = curValue;
			}
		}
		else
		{
			/*curWeight = 0;
			for(int i = 1;i <index;++i)
			{
				if(solusion[i])
					curWeight+=weightArray[i];
			}*/
			if((curWeight + weightArray[index]) <= volume)
			{
				solusion[index] = 1;
				curValue+=valueArray[index];
				curWeight+=weightArray[index];
				dfs(index+1);
				curValue-=valueArray[index];
				curWeight-=weightArray[index];
				//curValue+=valueArray[index];
			}
			solusion[index] = 0;
			dfs(index+1);
		}
	}
	int getMaxValue()
	{
		return maxValue;
	}
private:
	int backPackNum;
	int volume;
	int maxValue;
	char* solusion;
	int* valueArray;
	int* weightArray;
	int curValue;
	int curWeight;
};


int main()
{
	freopen("F:/input.txt","r",stdin);


	int N;int M;

	while (cin>>N>>M)
	{
		BackPack01 backPack01(M,N);
		int weight,value;
		int i = 1;
		while (i<=N)
		{
			cin>>weight>>value;
			backPack01.input(i,weight,value);
			++i;
		}
		backPack01.dfs(1);
		cout<<backPack01.getMaxValue()<<endl;

	}
	return 0;
}