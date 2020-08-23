#include<bits/stdc++.h> 
using namespace std; 
int R = 1001;
int C = 1001;
const long long int mod=pow(10,9)+7;
int maze[1001][1001];
  
int countPaths() { 
    
    if (maze[0][0]==-1) 
        return 0; 
  
    for (int i=0; i<R; i++) 
    { 
        if (maze[i][0] == 0) 
            maze[i][0] = 1; 
  
        // If we encounter a blocked cell in leftmost row, 
        // there is no way of visiting any cell directly below it. 
        else
            break; 
    } 
  
    // Similarly initialize the topmost row 
    for (int i=1; i<C; i++){

        if (maze[0][i] == 0) 
            maze[0][i] = 1; 
  
        // If we encounter a blocked cell in bottommost row, 
        // there is no way of visiting any cell directly below it. 
        else
            break; 
    } 
  
    for (int i=1; i<R; i++) 
    { 
        for (int j=1; j<C; j++) 
        { 
            // If blockage is found, ignore this cell  
            if (maze[i][j] == -1) 
                continue; 
  
            if (maze[i-1][j] > 0) 
                maze[i][j] = (maze[i][j]%mod + maze[i-1][j]%mod)%mod; 
  
            if (maze[i][j-1] > 0) 
                maze[i][j] = (maze[i][j]%mod + maze[i][j-1]%mod)%mod; 
        } 
    } 
  
    return (maze[R-1][C-1] > 0)? maze[R-1][C-1] : 0; 
} 

int main() {
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>R>>C>>k;
        memset(maze,0,sizeof(maze));
        int x,y;
        for(int i=0;i<k;i++){
            cin>>x>>y;
            maze[x-1][y-1] = -1;
        }
        cout<<countPaths()<<endl;        
    }
    return 0;
}_