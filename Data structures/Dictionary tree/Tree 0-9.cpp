#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct Node
{
	bool word;
	Node* parent;
	Node* child[10];

	Node(Node* _parent)
	{
		word = false;
		parent = _parent;
		for(int i=0;i<10;i++)
			child[i] = NULL;
	};
};

void Add_Word(Node *root, char word[])
{	
	Node* temp  = root; 
	int len = strlen(word);
	for(int i=0;i<len;i++)
	{	
		if(temp->child[word[i]-'0'] == NULL)
		   temp->child[word[i]-'0'] = new Node(temp);
		temp = temp->child[word[i]-'0'];
	}
	temp->word = true;
}

Node* Find_Prefix(Node *root,char word[])
{
	Node *temp = root;
	int i = 0,len = strlen(word);

	do
	{	
		temp = temp->child[word[i++]-'0'];
	}
	while(temp != NULL  && i < len);
	
	if(temp == NULL)printf("No match.\n");
	return temp;
}

void Print_Words(Node *root,char word[],int len)
{	
	if(root->word)
    {
	 	word[len] = 0;
	 	printf("%s\n",word);
	}

	for(int i=0;i<10;i++)
	{
		if(root->child[i] != NULL) 
		{
			word[len] =	i + '0';
			Print_Words(root->child[i], word, len+1);
		}
	}	
}

void Delete_Tree(Node *root)
{
	for(int i=0;i<10;i++)
		if(root->child[i] != NULL)
			Delete_Tree(root->child[i]);
	delete root;
}

int main()
{
	int n;
	char s[100];
	Node  *Tree = new Node(NULL);

	scanf("%d",&n);
	while(n--)
	{	
		scanf("%s",s);
		Add_Word(Tree,s);
	}
	Print_Words(Tree,s,0);	
	Delete_Tree(Tree);
	return 0;
}
