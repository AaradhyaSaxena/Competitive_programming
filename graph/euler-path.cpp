///////https://practice.geeksforgeeks.org/problems/euler-circuit-and-path/1

//// Euler path euler circuit

#include<bits/stdc++.h>
#include <list>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V)   {this->V = V; adj = new list<int>[V]; }
    ~Graph() { delete [] adj; }
    void addEdge(int v, int w);
    int isEulerian();
    bool isConnected();
    void DFSUtil(int v, bool visited[]);
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
void test(Graph &g)
{
    int res = g.isEulerian();
    if (res == 0)
        cout << "0\n";    //none
    else if (res == 1)
        cout << "1\n";    //Euler path
    else
        cout << "2\n";    //Euler cycle
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int v,e;
		cin>> v>>e;
		Graph g1(v);
		for(int i=0;i<e;i++){
			int a,b;
			cin>>a>>b;
		g1.addEdge(a, b);
		}
		test(g1);
	}
    return 0;
}

int Graph::isEulerian()
{
	int odd_vertex=0,even_vertex=0,sum=0;
	for(int i=0;i<V;i++)
	{
	    if(!adj[i].empty()) sum++;
	    if(!adj[i].empty()&&adj[i].size()%2==0)
	    	even_vertex++;
	    else if(!adj[i].empty()&&adj[i].size()%2!=0)
	    	odd_vertex++;
	}
	if(odd_vertex==0) return 2;
	if(odd_vertex==2) return 1;
	return 0;
}

bool Graph::isConnected(){}

/*
Undirected graphs with an Eulerian path and cycle.
To find whether a graph is Eulerian or not.

Eulerian Cycle
An undirected graph has Eulerian cycle if following two conditions are true.
 All vertices have even degree.

Eulerian Path
An undirected graph has Eulerian Path if following two conditions are true.
	If zero or two vertices have odd degree and all other vertices have even degree. 
	Note that only one vertex with odd degree is not possible in an undirected graph 
	(sum of all degrees is always even in an undirected graph)

Note that a graph with no edges is considered Eulerian because there are no edges to traverse.

*/
