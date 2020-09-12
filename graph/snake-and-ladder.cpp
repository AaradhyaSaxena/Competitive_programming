///////// https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem/0 

//// snake and ladder


#include <bits/stdc++.h>
using namespace std;

bool inrange(int i, int n, bool visited[]){
    return (i<=n && !visited[i]);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int *ladderboard = new int[31];
	    for(int i=1;i<=30;i++) ladderboard[i] = -1;
	    while(n--)
	    {
	        int a,b;
	        cin >> a >> b;
	        ladderboard[a] = b;
	    }
	    n=30;

	    // linear ladderboard is ready make a visited array 
        bool *visited = new bool[n+1];
        for(int i=1; i<= n; i++) visited[i] = false;
        
        // now we will take a queue and we will store the value (where we go) and the moves to reach that node
        queue < pair<int,int> > q;
        q.push({1,0}); // means we are at position 1 we have taken 0 steps till now
        // we are required to reach at position 36
        visited[1] = true;
        int ans = -1;
        bool found = false;
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            if(front.first==n)
            {
                ans = front.second;
                found = true;
                break;
            }
            for(int j=front.first+1;j<=front.first+6;j++)
            {
                if(inrange(j,n,visited))
                {
                    if(ladderboard[j]==-1)
                    {
                        q.push({j,front.second+1});
                        visited[j] = true;
                    }
                    else
                    {
                        q.push({ladderboard[j],front.second+1});
                        visited[j]= true;
                    }
                }
            }
            if(found) break;
        } 
        cout << ans << endl;
	}
}


///////