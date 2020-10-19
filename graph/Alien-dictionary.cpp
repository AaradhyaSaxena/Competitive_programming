////// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

/// Alien dictionary

//// solution

vector<vector<int>> adj(26);
vector<bool> vis(26);
stack<int> st;

void dfs(int s){
	vis[s] = true;

	for(int i=0; i<adj[s].size(); i++){
		if(vis[adj[s][i]]==0){
			dfs(adj[s][i]);
		}		
	}
	st.push(s);
}

string findOrder(string dict[], int N, int K) {
    
    for(int i=0; i<26; i++){
    	adj[i].clear();
    	vis[i] = false;
    }
    // st.clear();

    for(int i=0; i<N-1; i++){
        string s1 = dict[i], s2 = dict[i+1];
        int len1 = dict[i].length(), len2 = dict[i+1].length();
        for(int j=0; j<min(len1,len2); j++){
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        } 
    }

    for(int i=0; i<26; i++){
    	for(int j =0; j< adj[i].size(); j++){
    		if(vis[adj[i][j]]==false){
    			dfs(adj[i][j]);
    		}
    	}
    }
    
    string res;
    while(st.empty() == false)
    {
        res += st.top() + 'a';
        st.pop();
    }
    if(res.length()>K){
        res = res.substr(0,K);
    }
    
    return res;
}

// what is your first index does not matter in topo sort
// and don't forget to reverse your stack


///// first attempt solution
vector<vector<int>> adj(26);
vector<bool> vis(26);
stack<int> st;

void dfs(int s){
	vis[s] = true;

	for(int i=0; i<adj[s].size(); i++){
		if(vis[adj[s][i]]==0){
			dfs(adj[s][i]);
		}		
	}
	st.push(s);
}

string findOrder(string dict[], int N, int K) {
    
    for(int i=0; i<26; i++){
    	adj[i].clear();
    	vis[i] = false;
    }
    // st.clear();

    for(int i=0; i<N-1; i++){
        string s1 = dict[i], s2 = dict[i+1];
        int len1 = dict[i].length(), len2 = dict[i+1].length();
        for(int j=0; j<min(len1,len2); j++){
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        } 
    }

    vector<int> start(26);
    for(int i=0; i<26; i++){
    	if(adj[i].size() != 0){
    		start[i] = 1;
    	}
    	start[i] = 0;
    }
    for(int i=0; i<26; i++){
    	for(int j=0; j<adj[i].size(); j++){
    		start[adj[i][j]]--;
    	}
    }
    int index = 0;
    for(int i=0; i<26; i++){
    	if(start[i]==1){
    		index = i;
    	}
    }
    for(int i=0; i<k; i++){
    	for(int j =0; j< adj[i].size(); j++){
    		if(vis[adj[i][j]]==false){
    			dfs(adj[i][j]);
    		}
    	}
    }
    // dfs(index);
    
    string res;
    while(st.empty() == false)
    {
        res += st.top() + 'a';;
        
        st.pop();
    }
    if(res.length()>K){
        res = res.substr(0,K);
    }
    
    return res;
}

//////////////
//////////////////////
//////////

void DFSRec(vector<int> adj[], int u, stack<int> &st, vector<bool> &visited)
{
    visited[u] = true;
    
    for(auto v: adj[u])
    {
        if(visited[v] == false)
        {
            DFSRec(adj, v, st, visited);
        }
    }
    
    st.push(u);
}

string topologicalSort(vector<int> adj[], int V)
{
    stack<int> st;
    vector<bool> visited(V, false);
    
    for(int v=0; v < V; v++)
    {
        if(adj[v].size())
        {
            for(auto u: adj[v])
            {
                if(visited[u] == false)
                { 
                	DFSRec(adj, u, st, visited);
                }
            }
        }
    }
    
    string res;
    while(st.empty() == false)
    {
        res += st.top() + 'a';;
        
        st.pop();
    }
    
    return res;
}

string findOrder(string dict[], int N, int K) 
{
    vector<int> adj[K];
    
    for(int i = 0; i < N-1; i++)
    {
        string word1 = dict[i];
        string word2 = dict[i+1];
        for(int j = 0; j < min(word1.size(), word2.size()); j++)
        {
            if(word1[j] != word2[j])
            {
                int index1 = word1[j] - 'a';
                int index2 = word2[j] - 'a';
                
                adj[index1].push_back(index2);
                
                break;
            }
        }
    }
    
    return topologicalSort(adj, K);
}
        

//////////
///////

