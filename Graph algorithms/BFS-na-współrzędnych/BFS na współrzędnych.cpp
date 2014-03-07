#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

/* ********************************************************************* */
/* Algorytm BFS przeszukiwania mapy. Należy podać wymiary mapy           */
/* i jej budowę. Zmienna SEP przechowuje znak symbolizujący przeszkodę.  */
/* ********************************************************************* */

const int MAXN = 1000;   // Maksymalny rozmiar mapy
const int INF  = 100000000;
const char SEP = '#';    // Przeszkoda na mapie

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

char map[MAXN][MAXN];
int  dist[MAXN][MAXN];

bool valid(int y,int x,int height,int width)
{
     if( x>=0 && y>=0 && y<height && x<width && map[y][x] != SEP && dist[y][x] == INF)return true;
     return false;
}

void bfs(int sty,int stx,int height,int width)
{
    int tx,ty,nx,ny;
    queue<int>qx;
    queue<int>qy;

    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
            dist[i][j] = INF;

    dist[sty][stx] = 0;
    qx.push(stx); qy.push(sty);

    while(!qx.empty())
    {
        tx = qx.front(); ty = qy.front();
        qx.pop(); qy.pop();

        for(int i=0;i<4;i++)
        {
            nx = tx + dx[i];
            ny = ty + dy[i];

            if( valid(ny,nx,height,width) )
            {
                dist[ny][nx] = dist[ty][tx] +1;
                qy.push(ny);
                qx.push(nx);
            }
        }
    }
}


int main()
{
    int h,w;

    scanf("%d%d",&h,&w);

    for(int i=0; i<h ;i++)
        scanf("%s",map[i]);

    bfs(0,0,h,w);

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
            printf("%d ",dist[i][j]);
        printf("\n");
    }
    return 0;
}
