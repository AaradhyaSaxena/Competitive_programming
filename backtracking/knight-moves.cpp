/// https://practice.geeksforgeeks.org/problems/steps-by-knight/0

//// knight moves

int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {-1,1,-2,2,2,-2,1,-1};
bool vis[501][501];
int level[501][501];
int flag, cnt;
#define f first
#define s second

bool isValid(int A,int B,int C,int D){
    if(C<1 || C>A || D<1 || D>B){
        return false;
    }return true;
}

void initialize(int A,int B){
    for(int i=0; i<=A; i++){
        for(int j=0; j<=B; j++){
            vis[i][j] = false;
            level[i][j] = 0;
        }
    }
}

void bfs(int A,int B,int C,int D,int E, int F){
    vis[C][D] = true;
    level[C][D] = 0;
    queue<pair<int,int>> qt;
    qt.push({C,D});
    while(!qt.empty()){
        pair<int,int> tmp = qt.front();
        qt.pop();
        int ct = tmp.f, dt = tmp.s;
        for(int k=0; k<8; k++){
            int i = ct + dx[k];
            int j = dt + dy[k];
            if(!flag && isValid(A,B,i,j)){
                if(vis[i][j]==false){
                    level[i][j] = level[ct][dt] + 1;
                    qt.push({i,j});
                    vis[i][j] = true;
                    if(i==ct && j==dt) return;
                }
            }
        }
    }
}


int main(){
	int t; cin>>t;
	while(t--){
		int N;
		cin>>N;
		int x,y,u,v;
		cin>>x>>y>>u>>v;
		flag = 0; cnt = 0;
    	initialize(N,N);
    	bfs(N,N,x,y,u,v);
    	if(vis[u][v]){
    	    cout<<level[u][v]<<endl;
    	}
	}
}

//////