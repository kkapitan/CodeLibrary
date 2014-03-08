#include<stdio.h>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

const int MAXN = 1000;
const int INF  = 1<<10;

struct Node
{
    int id,w;
    Node(int _id, int _w){id = _id; w = _w;}
    bool operator< (const Node &t)const{return w>t.w;} 
};

vector<int>g[MAXN],wei[MAXN];
int dist[MAXN];

void Init_Single_Source(int src, int n)
{
    for(int i=0;i<n;i++)
        dist[i] = INF;
    dist[src] = 0;
}

bool Relax(int u,int v,int wei)
{
    if( dist[v] > dist[u] + wei)
    {
        dist[v] = dist[u] + wei;
        return true;
    }
    return false;
}

void Dijkstra(int st,int n)
{
    int v,u;
    priority_queue<Node>pq;

    Init_Single_Source(st,n);
    pq.push(Node(st,0));

    while(!pq.empty())
    {
        u = pq.top().id; pq.pop();
        for(int i=0;i<g[u].size();i++)
        {
            v = g[u][i];
            if(Relax(u,v,wei[u][i]))
                pq.push(Node(v,dist[v]));
        }
    }
}

int main()
{
    int n,m,a,b,w,src;
    scanf("%d%d%d",&n,&m,&src);
    while(m--)
    {
        scanf("%d%d%d",&a,&b,&w);
        g[a].push_back(b);
        g[b].push_back(a);
        wei[a].push_back(w);
        wei[b].push_back(w);
    }

    Dijkstra(src,n);

    for(int i=0;i<n;i++)
        printf("%d ",dist[i]);
    printf("\n");
    return 0;
}
