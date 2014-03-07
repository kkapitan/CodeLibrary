#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

/* ********************************************************************* */
/* Algorytm znajdowania silnie spójnych składowych. Należy podać liczbę  */
/* wierzchołków oraz krawędzi, a następnie ich opisy. Implementacja      */
/* wykorzystuje listę sąsiedztwa. Wierzchołki indeksowane są od 0.      */
/* ********************************************************************* */

const int MAXN = 1000;   // Maksymalna liczba wierzchołków
const int INF  = 100000000;

vector<int>g[MAXN],gt[MAXN],res[MAXN];
vector<int>pstord;;
int visited[MAXN];

void dfs_go(int st)
{
    visited[st]=true;
    for(int i=0;i<g[st].size();i++)
        if(!visited[g[st][i]])dfs_go(g[st][i]);
    pstord.push_back(st);
}

void dfs(int n)
{
    for(int i=0;i<n;i++)
        visited[i] = false;
    for(int i=0;i<n;i++)
        if(!visited[i])dfs_go(i);
}

void SCC_go(int st,int num)
{
    visited[st]=true;
    for(int i=0;i<gt[st].size();i++)
        if(!visited[gt[st][i]])SCC_go(gt[st][i],num);
    res[num].push_back(st);
}

void SCC(int n)
{
    int num = 0; dfs(n);
    for(int i=0;i<n;i++)visited[i] = false;

    for(int i=pstord.size()-1;i>=0;i--)
        if(!visited[pstord[i]])SCC_go(pstord[i],num++);
}

int main()
{
    int a,b,n,m;

    scanf("%d%d",&n,&m);

    while(m--)
    {
        scanf("%d%d",&a,&b);
        a--;b--;
        g[a].push_back(b);
        gt[b].push_back(a);
    }

    SCC(n);

    int k = 0;
    while(res[k].size())
    {
        for(int i=0;i<res[k].size();i++)
            printf("%d ",res[k][i]);
        printf("\n");
        k++;
    }

    return 0;
}
