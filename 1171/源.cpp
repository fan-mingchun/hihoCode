#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define max_pach_volume 1000001
#define max_facilities 10001
//generating function
int amountArray[max_facilities];
int valueArray[max_facilities];
int collection[max_pach_volume];
int temp[max_pach_volume];
int main()
{


	freopen("F:/input.txt","r",stdin);
	int num;
	int value;int amount;
	while(cin>>num  )
	{
		if (num < 0) return 0;
		
		for(int i = 0;i <max_pach_volume;++i)
		{
			collection[i] = 0;
			temp[i] = 0;
		}
		int facilityNum = num;
		
		int sumSum = 0;
		int i =1;
		while (num--)
		{
			cin>>value>>amount;
			sumSum+=value*amount;
			amountArray[i] = amount;
			valueArray[i] = value;
			++i;
		}
		double half = sumSum/2.0;
		for(int i = 0;i <=amountArray[1]*valueArray[1];i+=valueArray[1])
		{
			collection[i] = 1;
		}
		int len = amountArray[1]*valueArray[1];
		for(int i = 2;i <=facilityNum;++i)
		{
			for(int j = 0;j <=len;++j)
			{
				for(int k = 0;k <=amountArray[i]*valueArray[i];k+=valueArray[i])
				{
					temp[k+j]+=collection[j];
				}
			}
			len+=amountArray[i]*valueArray[i];
			for(int j = 0;j <=len;++j)
			{
				collection[j] = temp[j];
				temp[j] = 0;
 			}
		}
		for(int i = half;i>=0;--i)
		{
			if(collection[i]!=0)
			{
				cout<<sumSum-i<<" "<<i<<endl;
				break;
			}
				
			
		}

	}
	return 0 ;
}


//int main()
//{
//
//	int collection[max_pach_volume];
//	freopen("F:/input.txt","r",stdin);
//	int num;
//
//
//	int value;int amount;
//	
//	while(cin>>num && num>=0)
//	{
//	
//		
//	
//		int index = 0;
//		int sum = 0;
//		int sumSum = 0;
//		while (num--)
//		{
//			cin>>value>>amount;
//			sumSum+=value*amount;
//			while (amount--)
//			{
//				collection[index++]=value;
//			}
//			
//		}
//		double half = sumSum/2.0;
//		sort(collection,collection+index);
//		for(int i =index-1;i >=0;--i)
//		{
//			
//			if((sum+ collection[i])>half)
//			{
//				continue;
//				
//				
//			}
//			sum+=collection[i];
//		}
//		cout<<sumSum-sum<<" "<<sum<<endl;
//		
//	}
//
//	//cout<<result[volume];
//	return 0 ;
//}
