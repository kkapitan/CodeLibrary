#include<stdio.h>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

/* ************************************************************************************ */
/*     Algorytm Dinica na znajdowanie maksymalnego przep³ywu/minimalnego przekroju.     */
/*     Nale¿y podaæ iloœæ wierzcho³ków,iloœæ krawêdzi,Ÿród³o,ujœcie i opisy krawêdzi    */
/*     wraz z przepustowoœci¹. Algorytm wykorzystuje listê incydencji.                  */
/* ************************************************************************************ */

const int MAXN = 1000;    // Maxymalna liczba wierzcho³ków
const int MAXE = 100000;  // Maxymalna liczba krawêdzi
const int INF  = 1<<10;

int flow[MAXE],cap[MAXE],next[MAXE],to[MAXE];
int dist[MAXN],fin[MAXN],start[MAXN];

int src,snk,n,nEdge;

int min(int a,int b){ return a<b?a:b;}

void Add_Edge(int u,int v,int c)
{
    to[nEdge] = v; cap[nEdge] = c; flow[nEdge] = 0; next[nEdge] = fin[u]; fin[u] = nEdge++;
    to[nEdge] = u; cap[nEdge] = c; flow[nEdge] = 0; next[nEdge] = fin[v]; fin[v] = nEdge++;
}

void Init_Flow(int _src, int _snk, int _n)
{
    src = _src; snk = _snk; n = _n; nEdge = 0;

    for(int i=0;i<=n;i++)
        fin[i] = -1;
}

bool bfs()
{
    int u,v;
    queue<int> q;

    for(int i=0;i<=n;i++)
        dist[i] = INF;

    dist[src] = 0;
    q.push(src);

    while(!q.empty())
    {
        u = q.front(); q.pop();
        if( u == snk)return true;

        for(int i=fin[u]; i>=0 ; i=next[i])
        {
            v = to[i];
            if(cap[i]>flow[i] && dist[v] == INF)
            {
                 dist[v] = dist[u] + 1;
                 q.push(v);
            }
        }
    }
    return false;
}

int dfs(int st, int aug)
{
   int v,df;

   if(st == snk)
       return aug;

   for(int &i=start[st]; i>=0; i=next[i])
   {
        v = to[i];
        if(dist[v] == dist[st] + 1 && cap[i]>flow[i])
        {
            df = dfs(v,min(aug,cap[i]-flow[i]));
            if(df>0)
            {
                flow[i] += df;
                flow[i^1] -= df;
                return df;
            }
        }
   }
   return 0;
}

long long int Max_Flow()
{
    long long int res = 0;
    int df;

    while(bfs())
    {
        for(int i=0;i<=n;i++)
             start[i] = fin[i];

        while(df = dfs(src,INF))
            res += (long long int)df;


    }
    return res;
}

int main()
{
    int wn,wm,wsrc,wsnk,wa,wb,wc;

    scanf("%d%d",&wn,&wm);
    scanf("%d%d",&wsrc,&wsnk);

    Init_Flow(wsrc,wsnk,wn);
    while(wm--)
    {
        scanf("%d%d%d",&wa,&wb,&wc);
        Add_Edge(wa,wb,wc);
    }

    printf("%lld\n",Max_Flow());


    return 0;
}
