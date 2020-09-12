//////// https://practice.geeksforgeeks.org/problems/negative-weight-cycle/0

/////// Check-negative weight cycle

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int v,e,x,y,w;
	    cin>>v>>e;
	    int gr[e][3];
	    for(int i=0; i<e; i++){
	        cin>>x>>y>>w;
	        gr[i][0] = x, gr[i][1] = y, gr[i][2] = w;
	    }
	    int dis[v];
	    for(int i=0; i<v; i++){
	        dis[i] = 1000000;
	    }
	    dis[0] = 0;
	    for(int i=0; i<v; i++){
	        for(int j=0; j<e; j++){
	            if(dis[gr[j][0]] + gr[j][2] < dis[gr[j][1]]){
	                dis[gr[j][1]] = dis[gr[j][0]] + gr[j][2];
	            }
	        }
	    }
	    int flag = 0;
	    for(int i=0; i<e; i++){
	        if(dis[gr[i][0]] + gr[i][2] < dis[gr[i][1]]){
	            flag = 1;
	        }
	    }
	    if(flag==1){
	        cout<<1<<endl;
	    }else{
	        cout<<0<<endl;
	    }
	}
	return 0;
}

///////

/////////////