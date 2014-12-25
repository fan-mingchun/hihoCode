#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
//struct HeroInfo
//{
//	int expense;
//	double expenseReal;
//	int damage;
//	double cost;
//};
int result[20001];
int level[20001];
int heroDamage[31];
int curHeroDamage[31];
double heroExpense[31];
int max(int a,int b);
//#define _CRT_SECURE_NO_WARNINGS
int main()
{
	for(int i = 0;i <20001;++i)
	{
		result[i]=0;
		level[i] = 0;
	}

	freopen("F:/input.txt","r",stdin);
	int heroNum ,coinNum;
	cin>>heroNum>>coinNum;
	int damage;int expense;
	int i = 1;
	while (cin>>damage>>expense)
	{
		heroDamage[i] = damage;
		heroExpense[i] = expense;
		curHeroDamage[i] = damage;
		++i;
	}

	for(int i = 1;i <=heroNum;++i)
	{
		for(int j = 0;j <20001;++j)
		{
			
			level[j] = 0;
		}
		for(int curExpense = floor(heroExpense[i]);curExpense<=coinNum;++curExpense)
		{
			int curLevelDamage=heroDamage[i];
			double curLeverExpense = heroExpense[i];
			while (level[curExpense]--)
			{
				curLevelDamage += heroDamage[i];
				curLeverExpense *= 1.07;
			}
			if((result[curExpense-(int)floor(heroExpense[i])]+curHeroDamage[i] ) > result[curExpense])
			{
				result[curExpense] = result[curExpense-(int)floor(curLeverExpense)]+curLevelDamage;
				//heroExpense[i]*=1.07;
				//curHeroDamage[i]+=heroDamage[i];
				level[curExpense]++;
			}
			else
			{
				result[curExpense] = result[curExpense];
			}
		}
	}
	cout<<result[coinNum];
}

int max(int a,int b)
{
	if(a>b)
		return a;
	else
	{
		return b;
	}
}