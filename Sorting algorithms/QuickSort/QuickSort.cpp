#include<iostream>
#include<stdio.h>
using namespace std;


void QuickSort(int tab[],int B,int E)
{
	int i = B, j = E, M = tab[(B+E)/2];
	
	while(i <= j)
	{
		while(tab[i] < M)i++;
		while(tab[j] > M)j--;
		
		if(i <= j)swap(tab[i++],tab[j--]);
	}
	
	if(i < E)QuickSort(tab,i,E);
	if(B < j)QuickSort(tab,B,j);
}

int main()
{
	int n;
	scanf("%d",&n);
	int tab[n];
	
	for(int i=0;i<n;i++)
		scanf("%d",tab+i);
	
	QuickSort(tab,0,n-1);

	for(int i=0;i<n;i++)
		printf("%d ",tab[i]);
	printf("\n");

	return 0;
}
