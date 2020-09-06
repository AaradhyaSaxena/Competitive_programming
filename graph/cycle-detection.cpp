///////https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/

//// Topological sort / cycle-detection

/*
There are a total of A courses you have to take, labeled from 1 to A.

Some courses may have prerequisites, 
for example to take course 2 you have to first take course 1, which is expressed as a pair: [1,2].
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
Return 1 if it is possible to finish all the courses, or 0 if it is not possible to finish all the courses.

Input Format:
The first argument of input contains an integer A, representing the number of courses.
The second argument of input contains an integer array, B.
The third argument of input contains an integer array, C.
*/

#define MAXN 100005

vector<int> g[MAXN];

void check_cycle(int u, int visited[], bool &f) {
  visited[u] = 1;
  for(auto v : g[u]) {
    if(visited[v] == 0) {
      check_cycle(v, visited, f);
    } else if(visited[v] == 1) {
      //cycle found
      f = true;
    }
  }
  visited[u] = 2;
}

int Solution::solve(int N, vector<int> &B, vector<int> &C) {
    bool f = false;
    int visited[MAXN] = {0};
    for(int i = 1;i <= N; i++) {
      g[i].clear();
    }
    for(int i=0; i<B.size(); i++) {
      g[B[i]].push_back(C[i]);
    }
    for(int i = 1; i <= N; i++) {
      if(visited[i] == 0) {
        check_cycle(i, visited, f);
        if(f) {
          break;
        }
      }
    }
    return !f;
}

/////////////////////







