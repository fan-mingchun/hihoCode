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
struct DisToS
{
	DisToS(){}
	DisToS(int a,int b):nodeNum(a),distance(b)
	{
	}
	int nodeNum;
	int distance;
};
//class Function
//{
//public:
//	Function(Node* a=0):_n(a)
//	{}
//
//	~Function();
//
//private:
//	Node* _n;
//};


#define max_node_num 100001
list<Node*>* adjacencyList[max_node_num];
bool nodeFlag[max_node_num];
int main()
{
	freopen("F:/input.txt","r",stdin);
	int N,M,S,T;
	int nnn=1;
	cin>>N>>M>>S>>T;
	{
		//cin>>N>>M>>S>>T;
		memset(adjacencyList,0,sizeof(list<Node>*)*max_node_num);
		memset(nodeFlag,0,sizeof(bool)*max_node_num);
		for (int i = 0; i <= N; i++)
		{
			adjacencyList[i] = new list<Node*>();

		}
		int u_i,v_i,lenth;
		int index = M;
		while (index--)
		{
			cin>>u_i>>v_i>>lenth;

			adjacencyList[u_i]->push_back(new Node(v_i,lenth));
			adjacencyList[v_i]->push_back( new Node(u_i,lenth));
		}
		queue<DisToS> result;
		int minDistance = 9000000000;
		DisToS first(S,0);
		result.push(first);
		while (!result.empty())
		{
			DisToS topNode = result.front();
			result.pop();
			/*if(topNode.nodeNum == T)
				continue;*/
			if(nodeFlag[topNode.nodeNum])
				continue;
			
			list<Node*>* link = adjacencyList[topNode.nodeNum];
			typedef list<Node*>::iterator iter;
			for (iter i = link->begin(); i != link->end(); i++)
			{
				Node* temp = *i;
				DisToS tempDisToS;
				/*if(nodeFlag[temp->nodeNum])
					continue;*/
				/*if(topNode.nodeNum == temp->nodeNum )
					continue;*/
				tempDisToS.nodeNum = temp->nodeNum;
				tempDisToS.distance = temp->weights+topNode.distance;
				result.push(tempDisToS);
				if(tempDisToS.nodeNum==T && tempDisToS.distance<minDistance)
				{
					minDistance = tempDisToS.distance;
				}
			}
			nodeFlag[topNode.nodeNum] = true;
			
		}
		for(int i=0;i <=N;++i)
		{
			list<Node*>* tempList = adjacencyList[i];
			typedef list<Node*>::iterator iter;
			for (iter j = tempList->begin(); j != tempList->end(); j++)
			{
				delete *j;
				*j = 0;
				
			}
			
			delete tempList;
			adjacencyList[i]=0;
		}
		cout<<minDistance<<endl;
		//break;
	}
	return 0;
}