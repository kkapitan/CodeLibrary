#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 1000;      

struct Tedge{
    int a,b,w;
    Tedge(int _a,int _b,int _w){ a = _a; b = _b; w = _w; }
    bool operator<(const Tedge &t)const{ return w<t.w;}
};

vector<Tedge>Edges;
int rank[MAXN],p[MAXN];

void Make_Set(int x)
{
    rank[x] = 0;
    p[x] = x;
}

int Find_Rep(int x)
{
    if(x != p[x])
        p[x] = Find_Rep(p[x]);
    return p[x];
}

void Union(int x,int y)
{
    x = Find_Rep(x);
    y = Find_Rep(y);
    if(rank[x]<rank[y])
        p[x] = y;
    else
    {
        p[y] = x;
        if(rank[x] == rank[y])rank[x]++;
    }
}

int MTS_Kruskal(int n)
{
    int res = 0;

    for(int i=0;i<=n;i++)
        Make_Set(i);

    sort(Edges.begin(),Edges.end());

    for(int i=0;i<Edges.size();i++)
    {
        if(Find_Rep(Edges[i].a) != Find_Rep(Edges[i].b) )
        {
            res += Edges[i].w;
            Union(Edges[i].a,Edges[i].b);
        }
    }
    return res;
}

int main()
{
    int a,b,n,m,w;

    scanf("%d%d",&n,&m);

    while(m--)
    {
        scanf("%d%d%d",&a,&b,&w);
        Edges.push_back(Tedge(a,b,w));
    }

    printf("%d\n",MTS_Kruskal(n));

    return 0;
}
