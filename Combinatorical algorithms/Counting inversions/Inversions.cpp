#include<iostream>
#include<stdio.h>
using namespace std;

int Count(int tab[],int B,int M,int E)
{
	int res = 0,i = B, j = M+1, k = 0;
	int temp[E-B+1];

	while(i <= M && j <= E)
	{
		if(tab[i] < tab[j])
			temp[k++] = tab[i++];
		else
		{
			temp[k++] = tab[j++];
			res += (M-i+1);
		}
	}

	while(i <= M)temp[k++] = tab[i++];
	while(j <= E)temp[k++] = tab[j++];
	
 	for(int i=0;i<E-B+1;i++)
		tab[B+i] = temp[i]; 
	return res;
}


int InvCount(int tab[],int B,int E)
{
	if(B == E)return 0;
	return InvCount(tab,B,(B+E)/2) + InvCount(tab,(B+E)/2+1,E) + Count(tab,B,(B+E)/2,E);
}

int main()
{
	int n;
	scanf("%d",&n);
	int tab[n];
	
	for(int i=0;i<n;i++)
		scanf("%d",tab+i);
	
	printf("%d\n",InvCount(tab,0,n-1));
	return 0;
}
