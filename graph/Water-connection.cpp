////// https://www.geeksforgeeks.org/water-connection-problem/

///// water-connection-problem

#include <bits/stdc++.h> 
using namespace std; 
  
int n, p; 
  
int rd[1100]; //  ending vertex of pipe 
int wt[1100]; // diameters between two pipes 
int cd[1100]; // starting end of pipe 
  
// Vector a, b, c are used to store the final output 
vector<int> a; 
vector<int> b; 
vector<int> c; 
  
int ans; 
  
int dfs(int w) 
{ 
    if (cd[w] == 0) 
        return w; 
    if (wt[w] < ans) 
        ans = wt[w]; 
    return dfs(cd[w]); 
} 
  
void solve(vector<vector<int>> adj){

    int i = 0; 
    while (i < p) 
    {     
        int q = arr[i][0], h = arr[i][1], t = arr[i][2];      
        cd[q] = h; 
        wt[q] = t; 
        rd[h] = q; 
        i++; 
    } 
      
    a.clear(); 
    b.clear(); 
    c.clear(); 
      
    for (int j = 1; j <= n; ++j) 
      
        // If a pipe has no ending vertex but has starting vertex i.e is  
        // an outgoing pipe then we need to start DFS with this vertex.
        if (rd[j] == 0 && cd[j]) { 
            ans = 1000000000; 
            int w = dfs(j); 
              
            // We put the details of component in final output array 
            a.push_back(j); 
            b.push_back(w); 
            c.push_back(ans); 
        } 
          
    cout << a.size() << endl; 
    for (int j = 0; j < a.size(); ++j){
    	cout<<a[j]<<" "<<b[j]<<" "<<c[j]<<endl; 
    } 
} 
  
int main() 
{  	
	int t;
	cin>>t;
	while(t--){
	    cin>>n>>p;
	    memset(rd, 0, sizeof(rd)); 
	    memset(cd, 0, sizeof(cd)); 
	    memset(wt, 0, sizeof(wt)); 
	    vector<vector<int> > adj(n+1);
	    for(int i=0; i<p; i++){
	        int x,y,z;
	        cin>>x>>y>>z;
	        adj[i].push_back(x);
	        adj[i].push_back(y);
	        adj[i].push_back(z);
	    }
		solve(adj);   
	}  
    return 0; 
}

//////
//////////// 	