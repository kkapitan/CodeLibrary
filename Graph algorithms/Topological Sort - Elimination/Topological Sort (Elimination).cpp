#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;


const int MAXN = 1000;  
const int INF  = 100000000;

vector<int>g[MAXN];
int deg[MAXN];
vector<int>res;

void Remove_Vertex(int v)
{
    deg[v]--;
    for(int i=0;i<g[v].size();i++)
        deg[g[v][i]]--;
}

bool Find_Vertex(int n)
{
    int i,newV = -1;
    for(i=n-1;i>=0;i--)
        if(deg[i] == 0)newV = i;

    if(newV == -1)return false;

    res.push_back(newV);
    Remove_Vertex(newV);
    return true;
}

void TopoSort(int n)
{
    while(Find_Vertex(n));
    if(res.size() != n)
        printf("Not a DAG\n");
    else
        for(int i=0;i<n;i++)printf("%d ",res[i]);
    printf("\n");
}

int main()
{
    int a,b,n,m;

    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)deg[i] = 0;

    while(m--)
    {
        scanf("%d%d",&a,&b);
        a--; b--;
        g[a].push_back(b);
        deg[b]++;
    }

    TopoSort(n);


    return 0;
}
