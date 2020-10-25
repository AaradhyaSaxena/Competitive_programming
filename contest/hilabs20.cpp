////// hilabs20

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,x; cin>>n>>x;
	vector<int> vec(2*n);
	for(int i=0; i<n; i++) cin>>vec[i];
	for(int i=n; i<2*n; i++) vec[i] = vec[i-n];

	vector<int> cost(n, INT_MAX);
	for(int i=0; i<n; i++){
		cost[i] = vec[i];
	}

	int maxx = 0;
	for(int i=1; i<=n; i++){
		for(int j=0; j<n; j++){
			if(vec[j+i] + x*(i-maxx) < cost[j]){
				cost[j] = vec[j+i] + x*(i-maxx);
				maxx = i;	
			}
		}
	}

	int sum = 0;
	for(int i=0; i<n; i++){
		sum += cost[i];
	}
	cout<<sum<<endl;
}

//////////////


