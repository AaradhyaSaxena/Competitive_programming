////// https://practice.geeksforgeeks.org/problems/topological-sort/1
//// https://practice.geeksforgeeks.org/editorial.php?pid=700255

/// Topological Sort

#include<bits/stdc++.h>
using namespace std;

vector <int> topoSort(int N, vector<int> adj[]);

bool check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

////////////////////

stack<int> st;
unordered_map<int,bool> mp;

void dfs(int s,vector<int> adj[])
{
    mp[s]=true;
    for(int i=0;i<adj[s].size();i++)
    {
        if(mp[adj[s][i]]==false)
        {
            dfs(adj[s][i],adj);
        }
    }
    st.push(s);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    for(int i=0;i<V;i++)
    {
        if(mp[i]==false)
        {
            dfs(i,adj);
        }
    }

    vector<int> v;
    while(!st.empty())
    {
        v.push_back(st.top());st.pop();
    }
    mp.clear();
    return v;
}

////////////////////////
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);
        cout << check(N, res, adj) << endl;
    }
}


//////////////////////////
//////////////////////////


#include<iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
	int V;    
	list<int> *adj;

    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);

public:
// Constructor

    Graph(int V);   
     // function to add an edge to graph
    void addEdge(int v, int w);

    // prints a Topological Sort of the complete graph
    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
}

void Graph::topologicalSortUtil( int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    // Push current vertex to stack which stores result
    Stack.push(v);
}

void Graph::topologicalSort()
{
    stack<int> Stack;

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);

    // print elements of stack
    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();

    return 0;
}
