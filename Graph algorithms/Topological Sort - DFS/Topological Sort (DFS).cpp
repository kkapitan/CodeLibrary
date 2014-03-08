#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

const int MAXN = 1000; 
const int INF  = 100000000;

vector<int>g[MAXN];
int visited[MAXN];
bool cycle = false;
vector<int>res;

void dfs_go(int st)
{
    visited[st] = 1;

    for(int i=0;i<g[st].size();i++)
        if(!visited[g[st][i]])dfs_go(g[st][i]);
        else if(visited[g[st][i]] == 1)cycle = true;

    visited[st] = 2;
    res.push_back(st);
}

void TopoSort(int n)
{
    for(int i=0;i<n;i++)visited[i] = 0;
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
        a--; b--;
        g[a].push_back(b);
    }

    TopoSort(n);
    if(!cycle)
    {
        for(int i = res.size()-1;i>=0;i--)
            printf("%d ",res[i]);
    }else printf("Not a DAG!\n");

    return 0;
}
