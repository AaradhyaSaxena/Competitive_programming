///////

//// path finder with pathholes







//// two strings subsequence

/*
Two strings S and T (T is a subsequence of S) are given and an array of indices is given. 
Find the maximum number of characters at the index 
(given by each array element) can be removed such that T is still a subsequence of S.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int n = s1.length(), m = s2.length();
	int arr[n+1];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int ans = 0;
	int start = 0, end = n;
	while(start<end){
		int mid = start + (end-start)/2;
		string s = s1;
		int p1=0,p2 =0;
		for(int i=0; i<mid; i++){
			s[arr[i]-1] = '#';
		}
		while(p1<n and p2<m){
			if(s[p1]==s2[p2]){
				p1++; p2++;
			}
			else p1++;
		}
		if(p2==m){
			start = mid+1;
			ans = mid;
		}
		else end = mid-1;
	}
	cout<< ans<<endl;
}

//// GCD from root to leaf number of ways



