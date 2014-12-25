#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include <queue>
#include <cstring>
using namespace std;
struct Node
{
	Node(int a,int b):nodeNum(a),weights(b)
	{

	}
	Node(){}
	int nodeNum;
	int weights;
};
list<Node*>* testListArray[10];
int main()
{
	int num,num1;
	while(cin>>num>>num1)
	{
		for(int i =0;i < 10;++i)
		{
			testListArray[i] = new list<Node*>();
			//testListArray[i]->push_back(new Node(0,0));

		}
		for (int i = 1; i < 10; i++)
		{
			auto templist = testListArray[i];
			typedef list<Node*>::iterator iter;
			for(iter it= templist->begin();it!=templist->end();++it)
			{
				delete *it;
				*it = 0;
			}
			delete templist;
			templist=0;
		}
	}

	return 0;
}