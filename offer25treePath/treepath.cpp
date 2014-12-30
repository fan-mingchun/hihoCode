#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
int path[10000];

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int weight;
};
TreeNode* insertTree(const int* preSort,int& index,TreeNode*& head);
void printPath(TreeNode*& head,int theNum,int floorIndex);
int main()
{
	freopen("F:/input.txt","r",stdin);
	int str[1000];
	int input;
	int i = 0;
	while (cin>>input)
	{
		str[i++] = input;
	}
	
	int index = 0;
	TreeNode* tree= NULL;
	insertTree(str,index,tree);
	printPath(tree,22,0);
	return 0;
}
void printPath(TreeNode*& head,int theNum,int floorIndex)
{
	if(head == NULL || theNum <0)
		throw runtime_error("invalid input!");
	if(!head->left && !head->right && theNum == head->weight)
	{
		path[floorIndex] = head->weight;
		//path[floorIndex] = '\0';
		for(int i = 0;i<=floorIndex;++i)
		{
			cout<<path[i]<<" ";
			
		}
		cout<<endl;
		
	}

	if(head->left&&(head->weight < theNum))
	{
		path[floorIndex] = head->weight;
		printPath(head->left,theNum-head->weight,floorIndex+1);
	}
	if(head->right&&(head->weight < theNum))
	{
		path[floorIndex] = head->weight;
		printPath(head->right,theNum-head->weight,floorIndex+1);
	}
}
TreeNode* insertTree(const int * preSort,int& index,TreeNode*& head)
{
	if(preSort[index] == -1)
		return head;

	head = new TreeNode;
	head->weight = preSort[index];
	head->left = NULL;
	head->right = NULL;
	++index;
	insertTree(preSort,index,head->left);
	++index;
	insertTree(preSort,index,head->right);

	return head;

}