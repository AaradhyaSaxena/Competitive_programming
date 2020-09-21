////// https://practice.geeksforgeeks.org/problems/minimum-swaps/1

//// min swaps to sort

vector<int> adj[100001];
bool visited[100001];

int dfs(int N, int i){
	visited[i] = true;
	for(int j=0; j<adj[i].size(); j++){
		if(visited[adj[i][j]] == false){
			dfs(N,adj[i][j]);
		}
	}
}

int minSwaps(int arr[], int N){

    int newarr[N];
    for(int i=0; i<N; i++){
        newarr[i] = arr[i];
    }
    sort(newarr, newarr+N);
    
    for(int i=0; i<N; i++){
    	adj[newarr[i]].push_back(arr[i]);
    	adj[arr[i]].push_back(newarr[i]);
    }

    int cnt = 0;
    for(int i=0; i<N; i++){
    	if(visited[arr[i]] != true){
    		dfs(N,arr[i]);
    		cnt++;
    	}
    }
    return N-cnt;
}

////////

int minSwaps(int arr[], int N){
    pair<int,int> temp[N];
 
    for(int i=0; i<N; i++){
        temp[i].first=arr[i];
        temp[i].second=i;
    }
    
    sort(temp,temp+N);

    bool* visited = new bool[N]();
    int ans=0;
    
    for(int i=0; i<N; i++)
    {       
    	if(visited[i] || temp[i].second == i)
        continue;
        
        int j = i;
        int cycle_size = 0;
        
        while(!visited[j])
        {
            visited[j] = true;
            
            j = temp[j].second;
            cycle_size++;
        }
        ans += cycle_size-1;
    }
    
    return ans;
}

///////////