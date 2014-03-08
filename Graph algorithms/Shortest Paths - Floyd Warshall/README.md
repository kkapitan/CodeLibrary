###Description

An implementation of a Floyd-Warshall's approach for finding shortest paths between all vertices in a weighted graph.

###Usage

####Input

<b>n, m</b> - number of vertices and number of edges respectively. <br>
Then m lines, each line describing an undirected edge (<b>a</b>, <b>b</b>) with weight <b>c</b>. <br> 

However it is easy to change that implementation to accept direct edges.

Vertices starts with 0.

####Output

An array <b>dist</b> containing pairwise distance for all vertices (i.e. <b>dist[a][b]</b> is equal to the distance between vertex <b>a</b> and vertex <b>b</b>).

####Additional comments

<b>MAXN</b> - maximal number of vertices. <br>
<b>INF</b>  - any big enough number. <br>

###Solved problems
[Einbahnstrasse](http://www.spoj.com/problems/ANARC08F/)
