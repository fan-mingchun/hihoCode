#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define max_things_num 501
#define max_pach_volume 100001
int result[max_pach_volume];
int valueArray[max_things_num];
int weightArray[max_things_num];
int thingsNum ,volume;


void backpack01(int weight,int value);
void backpackComplete(int weight,int value);
void backpackMulti(int weight,int value,int amount);
int main()
{
	//init
	for(int i = 0;i <max_pach_volume;++i)
	{
		result[i]=0;
		
	}
	for(int i = 0;i < max_things_num;++i)
	{
		valueArray[i]=0;
		weightArray[i]=0;
	}

	freopen("F:/input.txt","r",stdin);
	
	cin>>thingsNum>>volume;
	int value;int weight;
	int i = 1;
	while (cin>>weight>>value)
	{
		valueArray[i] = value;
		weightArray[i] = weight;
		++i;
	}

	for(int i = 1;i <=thingsNum;++i)
	{
		//backpack01(weightArray[i],valueArray[i]);
		//backpackComplete(weightArray[i],valueArray[i]);
		backpackMulti(weightArray[i],valueArray[i],1);
	}
	cout<<result[volume];
}
void backpack01(int weight,int value)
{
	for(int curVolume = volume;curVolume >= weight;--curVolume)
	{
		if((result[curVolume-weight]+value) > result[curVolume])
		{
			result[curVolume] = result[curVolume-weight]+value;
		}
	}
}
void backpackComplete(int weight,int value)
{
	for(int curVolume = weight;curVolume <= volume;++curVolume)
	{
		if((result[curVolume-weight]+value) > result[curVolume])
		{
			result[curVolume] = result[curVolume-weight]+value;
		}
		else
		{
			result[curVolume] = result[curVolume];
		}
	}
}
void backpackMulti(int weight,int value,int amount)
{
	if(weight*amount >= volume)
	{
		backpackComplete(weight,value);
		return;
	}
	else
	{
		int k = 1;
		while (k<amount)
		{
			backpack01(k*weight,k*value);
			amount = amount-k;
			k*=2;
		}
		if(amount>0)
		{
			backpack01(amount*weight,amount*value);
		}
	}
}