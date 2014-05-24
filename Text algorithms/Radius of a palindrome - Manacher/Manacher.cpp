#include<stdio.h>
#include<stdlib.h>
#include<string.h>


const int MAXN = 4000;
int R[MAXN];

int min(int a,int b)
{
    return a < b ? a : b;
}

int max(int a,int b)
{
    return a < b ? b : a;
}

bool Inside(int i,int t,int len,bool even)
{
    return ( 0 <= i - t &&  i + even + t < len);
}

void Manacher(char s[],bool even)
{
    int t = 0,i = 0,len = strlen(s);

    while(i < len)
    {
        while(Inside(i,t,len,even) && s[i-t] == s[i+even+t])t++;

        R[i] = t;

        int k = 1;
        while(k < R[i] && R[i-k] != R[i]-k )
            R[i+k] = min(R[i-k],R[i]-k),k++;

        i+= k; t = max(0,t-k);
    }
}


int main()
{
    char s[MAXN];
    int len;

    scanf("%s",s);
    len = strlen(s);

    Manacher(s,true);
    for(int i=0;i<len;i++)
        printf("%d",R[i]);
    printf("\n");

    Manacher(s,false);
    for(int i=0;i<len;i++)
        printf("%d",R[i]);
    printf("\n");

    return 0;
}

