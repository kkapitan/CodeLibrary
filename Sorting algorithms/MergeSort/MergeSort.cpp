#include<iostream>
#include<stdio.h>
using namespace std;

void Merge(int tab[],int B,int M,int E)
{
	int i = B, j = M+1, k = 0;
	int temp[E-B+1];

	while(i <= M && j <= E)
		temp[k++] = tab[i] < tab[j] ? tab[i++] : tab[j++];

	while(i <= M)temp[k++] = tab[i++];
	while(j <= E)temp[k++] = tab[j++];
	
 	for(int i=0;i<E-B+1;i++)
		tab[B+i] = temp[i]; 
}


void MergeSort(int tab[],int B,int E)
{
	if(B == E)return;

	MergeSort(tab,B,(B+E)/2);
	MergeSort(tab,(B+E)/2+1,E);
	Merge(tab,B,(B+E)/2,E);
}

int main()
{
	int n;
	scanf("%d",&n);
	int tab[n];
	
	for(int i=0;i<n;i++)
		scanf("%d",tab+i);
	
	MergeSort(tab,0,n-1);

	for(int i=0;i<n;i++)
		printf("%d ",tab[i]);
	printf("\n");

	return 0;
}
