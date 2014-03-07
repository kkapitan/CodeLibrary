#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

/* ********************************************************************* */
/* Algorytm Hopcrofta-Karpa wyszukiwania maksymalnego skojarzenia        */
/* w grafie dwudzielnym. Nale¿y podaæ liczbê wierzcho³ków z obu grup     */
/* oraz krawêdzie miêdzy nimi. Wierzcho³ki indeksowane s¹ od 1.          */
/* ********************************************************************* */

const int MAXN = 100000;   // Sumaryczna liczba wierzcho³ków z obu grup
const int INF  = 100000000;

vector<int>g[MAXN];
int match[MAXN],dist[MAXN];
bool visited[MAXN];

int n,m,p;

void bfs()
{
    queue<int>q;
    int u,v;

    for(int i=1;i<=n;i++)
    {
        if( !match[i] )
        {
            q.push(i);
            dist[i] = 0;
        }
        else dist[i] = INF;
    }

    while(!q.empty())
    {
        u = q.front(); q.pop();
        for(int i=0; i<g[u].size();i++)
        {
            v = g[u][i];
            if(dist[match[v]] == INF && match[v])
            {
                dist[match[v]] = dist[u] + 1;
                q.push(match[v]);
            }
        }
    }
}

bool dfs(int st)
{
    int v;
    visited[st] = true;

    for(int i=0;i<g[st].size();i++)
    {
        v = g[st][i];
        if( !match[v] || ( !visited[match[v]] && dist[match[v]] == dist[st] + 1 && dfs(match[v])))
        {
            match[v] = st;
            match[st] = v;
            return true;
        }
    }
    return false;
}

int Hopcroft_Karp()
{
    int matching, res;
    res = matching = 0;
    while(true)
    {
        bfs();
        matching = 0;
        for(int i=1;i<=n;i++)
            visited[i] = false;
        for(int i=1;i<=n;i++)
            if(!match[i] && dfs(i))matching++;
        if(matching)res += matching;else break;
    }
    return res;
}

int main()
{
    int a, b;
    scanf("%d%d%d", &n, &m,&p);
    while(p--)
    {
        scanf("%d%d",&a,&b);
        g[a].push_back(b+n);
        g[b+n].push_back(a);
    }
    printf("%d\n", Hopcroft_Karp());

    return 0;
}
