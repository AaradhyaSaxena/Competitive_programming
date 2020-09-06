//////////https://www.interviewbit.com/problems/black-shapes/

///// black shapes

nt dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N;
int M;
bool is_valid(int x, int y) {
    if(x < 0 || x >= N || y < 0 || y >= M)
        return false;
    return true;
}

void bfs(int i, int j, vector<string> &Vec) {
    queue<pair<int, int> > Que;
    Que.push(make_pair(i, j));

    while(!Que.empty()) {
        pair<int, int> P = Que.front();
        Que.pop();
        Vec[P.first][P.second] = 'O';
        for(int i = 0; i < 4; ++i) {
            int x = P.first + dx[i];
            int y = P.second + dy[i];
            if(is_valid(x, y) && Vec[x][y] == 'X') {
                Que.push(make_pair(x, y));
            }
        }
    }    
}       

int Solution::black(vector<string> Vec) {
    N = Vec.size();
    M = Vec[0].size();
    int cnt = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(Vec[i][j] == 'X') {
                cnt++;
                bfs(i, j, Vec);
            }
        }
    }
    return cnt;
}







