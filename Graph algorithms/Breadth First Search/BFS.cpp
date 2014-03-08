#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

const int MAXN = 1000;   
const int INF  = 100000000;

vector<int>g[MAXN];
int dist[MAXN];

void bfs(int st,int n)
{
    int u,v;
    queue<int>q;

    for(int i=0;i<n;i++)
        dist[i] = INF;
    dist[st] = 0;
    q.push(st);

    while(!q.empty())
    {
        u = q.front(); q.pop();
        for(int i=0;i<g[u].size();i++)
        {
           v = g[u][i];
           if(dist[v] == INF)
           {
                dist[v] = dist[u] +1;
                q.push(v);
           }
        }
    }
}


int main()
{
    int a,b,n,m,w,src;

    scanf("%d%d%d",&n,&m,&src);

    while(m--)
    {
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs(src,n);

    for(int i=0;i<n;i++)
        printf("%d ",dist[i]);
    printf("\n");

    return 0;
}
