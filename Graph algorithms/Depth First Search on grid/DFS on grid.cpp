#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

/* ********************************************************************* */
/* Algorytm DFS przeszukiwania mapy. Należy podać wymiary mapy           */
/* i jej budowę. Zmienna SEP przechowuje znak symbolizujący przeszkodę.  */
/* ********************************************************************* */

const int MAXN = 1000;   // Maksymalny rozmiar mapy
const int INF  = 100000000;
const char SEP = '#';    // Przeszkoda na mapie

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

char map[MAXN][MAXN];
int  visited[MAXN][MAXN];

bool valid(int y,int x,int height,int width)
{
     if( x>=0 && y>=0 && y<height && x<width && map[y][x] != SEP && !visited[y][x])return true;
     return false;
}

void dfs_go(int sty,int stx,int height,int width)
{
    int nx,ny;
    visited[sty][stx] = true;

    for(int i=0;i<4;i++)
    {
        nx = stx + dx[i];
        ny = sty + dy[i];

        if( valid(ny,nx,height,width))
            dfs_go(ny,nx,height,width);
    }
}

void dfs(int height,int width)
{
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
            visited[i][j] = false;

    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
            if(!visited[i][j])dfs_go(i,j,height,width);
}

int main()
{
    int h,w;

    scanf("%d%d",&h,&w);

    for(int i=0; i<h ;i++)
        scanf("%s",map[i]);

    dfs(h,w);

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
            printf("%d ",visited[i][j]);
        printf("\n");
    }
    return 0;
}
