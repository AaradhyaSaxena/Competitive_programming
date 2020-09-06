///////// https://www.interviewbit.com/problems/valid-path/

//// Valid Path

bool isvalid(int x,int y,int L,int B,int N,int R,vector<int> &E,vector<int> &F){
    if(x>L or x<0 or y>B or y<0){
    	return false;
    }
    for(int i=0; i<N; i++){
    	int xx = E[i], yy = F[i];
    	if((xx-x)*(xx-x) + (yy-y)*(yy-y) < R*R){
    		return false;
    	}
    }
    return true;
}

int flag = 0;
bool visited[100][100] = {0};

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {1,-1,0,1,-1,1,-1,0};

void bfs(int x,int y,int L,int B,int N,int R,vector<int> &E,vector<int> &F){
	stack<pair<int,int>> st;
	st.push({x,y});

	visited[x][y] = 1;
	for(int i=0; i<8; i++){
		int X = x+dx[i], Y = y+dy[i];
		if( visited[X][Y]==0 and isvalid(x,y,L,B,N,R,E,F) ){
			if (X==L and Y==B){
				flag = 1;
				return;
			}
			st.push({X,Y});
			visited[X][Y] = true;
		}
	}
}


string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
	int flag = 0;
	bfs(0,0, A,B,C,D,E,F);

	if(flag){
		return "YES";
	}else{
		return "NO";
	}
}








