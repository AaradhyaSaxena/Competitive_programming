////////https://practice.geeksforgeeks.org/problems/circle-of-strings/0

//// Circle of strings

#include <bits/stdc++.h>
using namespace std;

int check_cycle(int s,int n,vector<vector<int>> adj,vector<bool> visited, vector<int> level){
    if(s>=n) return true;
    visited[s] = true;
    for(auto to : adj[s]){
        if(level[s]==n-1 and (to == 0) and visited[to]==true) return 1;
        else if(visited[to] == false){
            level[to] = level[s] + 1;
            int result = check_cycle(to,n,adj,visited,level);
            if(result ==true) return true;
        }
    }
    return false;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n; cin>>n;
	    if(n==1) {
	        cout<<1<<endl; 
	        continue;
	    }
	    vector<string> vec;
	    vector<bool> visited(n+2,0);
	    vector<int> level(n+2,0);
	    for(int i=0; i<n; i++){
	        string s;
	        cin>>s;
	        vec.push_back(s);
	    }
	    vector<vector<int>> adj(n);
	    for(int i=0; i<n; i++){
	        for(int j=i+1; j<n ;j++){
	            int len1 = vec[i].length(), len2 = vec[j].length();
	            if(vec[i][len1-1]==vec[j][0]){
	                adj[i].push_back(j);
	            }
	            if(vec[i][0]==vec[j][len2-1]){
	                adj[j].push_back(i);
	            }
	        }
	    }
	    if(check_cycle(0,n,adj,visited,level)==1){
	        cout<<1<<endl;
	    }else{
	        cout<<0<<endl;
	    }
	}
	return 0;
}

/////////////
/////////////


// using namespace std;
// void addEdge(vector<vector<int>>&adj,int u,int v)
// {
//     adj[u].push_back(v);
// }
// void DFS(vector<vector<int > >adj,vector<bool>&visited,int x)
// {
//     visited[x]=true;
//     if(adj[x].size()!=0)
//     for(int i=0;i<adj[x].size();i++)
//     {
//         if(!visited[adj[x][i]])
//         {
//             DFS(adj,visited,adj[x][i]);
//         }
//     }
// }
// bool isStronglyConnected(vector<vector<int > >adj)
// {
//     for(int i=0;i<adj.size();i++)
//     {
//         if(adj[i].size()!=0)
//         {
//             vector<bool>visited(adj.size(),false);
//             DFS(adj,visited,i);
//             for(int j=0;j<adj.size();j++)
//             {
//                if(adj[j].size()!=0&&!visited[j])
//                  return false;
//             }
//         }
//     }
//     return true;
// }
// bool isEulerian(vector<vector<int>>adj)
// {
//     if(!isStronglyConnected(adj))   // check if the graph is a single strongly connected component
//         return false;
//     vector<int>inDegree(adj.size(),0);
//     for(int i=0;i<adj.size();i++)
//     {
//         if(adj[i].size()!=0)
//         {
//             for(int j=0;j<adj[i].size();j++)
//         {
//             inDegree[adj[i][j]]++;
//         }
//         }
//     }
//     for(int i=0;i<adj.size();i++)
//     {
//         if(adj[i].size()!=0)
//         {
//              if(inDegree[i]!=adj[i].size()) // check if inDegree equals out degree
//             return false;
//         }
//     }
//     return true;
// }
// int main()
//  {
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{
// 	    int ss;
// 	    cin>>ss;
// 	    vector<string>str(ss);
// 	    for(int i=0;i<ss;i++)
// 	    {
// 	        cin>>str[i];
// 	    }
// 	    vector<vector<int > >adj(26,vector<int>());
//     for(int i=0;i<ss;i++)
//     {
//         string word=str[i];
//         addEdge(adj,word[0]-'a',word[word.size()-1]-'a');
//     }
//     if(isEulerian(adj))
//         cout<<"1";
//     else
//         cout<<"0";
        
//     cout<<endl;
// 	}
// 	return 0;
// }

//////////	





