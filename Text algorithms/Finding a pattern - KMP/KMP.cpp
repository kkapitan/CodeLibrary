#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAXN = 2000;

void PrefixSufix(char text[],int P[])
{
    int t = 0,len = strlen(text);
    P[0] = 0;

    for(int i=1;i<len;i++)
    {
      while(t > 0 && text[i] != text[t])t = P[t-1];

      if(text[i] == text[t])t++;
      P[i] = t;
    }
}

void KMP(char text[],char pattern[])
{
    int len = strlen(text),len2 = strlen(pattern),P[ len + len2 + 2];
    char temp[len + len2 + 2];

    strcpy(temp,pattern);
    temp[len2] = '#';
    strcpy(temp+len2+1,text);

    PrefixSufix(temp,P);

    for(int i=len2+1;i<len2+len+1;i++)
        if(P[i] == len2)printf("%d\n",i-2*len2);
}

int main()
{
    char text[MAXN],pattern[MAXN];
    int t,n;

    scanf("%s",pattern);
    scanf("%s",text);
    KMP(text,pattern);

    return 0;
}

