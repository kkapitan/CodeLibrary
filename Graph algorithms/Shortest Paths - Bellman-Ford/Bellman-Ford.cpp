#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

const int MAXN = 1000;  
const int INF  = 100000000;

vector<int>g[MAXN];
int dist[MAXN];
int weight[MAXN][MAXN];

void Init_Single_Source(int src,int n)
{
    for(int i=0;i<n;i++)
         dist[i] = INF;
    dist[src] = 0;
}

bool Relax(int u,int v)
{
    if(dist[v] > dist[u] + weight[u][v])
    {
        dist[v] = dist[u] + weight[u][v];
        return true;
    }return false;
}

bool Bellman_Ford(int src,int n)
{
    Init_Single_Source(src,n);

    for(int k=1;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<g[i].size();j++)
                Relax(i,g[i][j]);

    for(int i=0;i<n;i++)
        for(int j=0;j<g[i].size();j++)
            if(Relax(i,g[i][j]))return false;
    return true;
}

int main()
{
    int a,b,n,m,w,src;

    scanf("%d%d%d",&n,&m,&src);

    while(m--)
    {
        scanf("%d%d%d",&a,&b,&w);
        g[a].push_back(b);
        g[b].push_back(a);
        weight[a][b] = w;
        weight[b][a] = w;
    }

    if(Bellman_Ford(src,n))
        for(int i=0;i<n;i++)
            printf("%d\n",dist[i]);
    else
        printf("Negative cycle\n");

    return 0;
}
