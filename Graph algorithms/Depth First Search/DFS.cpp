#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

/* ********************************************************************* */
/* Algorytm DFS przeszukiwania grafu. Należy podać liczbę wierzchołków   */
/* oraz krawędzi, a następnie ich opisy. Implementacja wykorzystuje      */
/* listę sąsiedztwa. Wierzchołki indeksowane są od 0.                    */
/* ********************************************************************* */

const int MAXN = 1000;   // Maksymalna liczba wierzchołków
const int INF  = 100000000;

vector<int>g[MAXN];
int visited[MAXN];

void dfs_go(int st)
{
    visited[st]=true;
    for(int i=0;i<g[st].size();i++)
        if(!visited[g[st][i]])dfs_go(g[st][i]);
}

void dfs(int n)
{
    for(int i=0;i<n;i++)
        visited[i] = false;
    for(int i=0;i<n;i++)
        if(!visited[i])dfs_go(i);
}

int main()
{
    int a,b,n,m;

    scanf("%d%d",&n,&m);

    while(m--)
    {
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(n);

    for(int i=0;i<n;i++)
        printf("%d ",visited[i]);
    printf("\n");

    return 0;
}
