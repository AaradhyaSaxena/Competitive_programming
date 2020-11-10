///////// Geeks greedy

//////// Activity selection problem

#include <bits/stdc++.h> 
using namespace std; 
  
struct Activitiy { 
    int start, finish; 
}; 
  
bool activityCompare(Activitiy s1, Activitiy s2){ 
    return (s1.finish < s2.finish); 
} 
  
void printMaxActivities(Activitiy arr[], int n) { 
    sort(arr, arr+n, activityCompare); 
  
    int i = 0; 
    cout << "(" << arr[i].start << ", " << arr[i].finish << "), "; 
  
    for (int j = 1; j < n; j++) { 
    	if (arr[j].start >= arr[i].finish){ 
        	cout << "(" << arr[j].start << ", " << arr[j].finish << "), "; 
          	i = j; 
      	} 
    } 
} 
  
int main() 
{ 
    Activitiy arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}}; 

    int n = sizeof(arr)/sizeof(arr[0]); 
    printMaxActivities(arr, n); 
    return 0; 
} 

///////////
//////////////////

#include <bits/stdc++.h> 
using namespace std; 
  
void SelectActivities(vector<int>s,vector<int>f){ 
    vector<pair<int,int>>ans; 
  
	// Minimum Priority Queue to sort activities in ascending order of finishing time (f[i]). 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p; 
  
    for(int i=0;i<s.size();i++){ 
        // Pushing elements in priority queue where the key is f[i] 
        p.push(make_pair(f[i],s[i])); 
    } 
  
    auto it = p.top(); 
    int start = it.second; 
    int end = it.first; 
    p.pop(); 
    ans.push_back(make_pair(start,end)); 
  
    while(!p.empty()){ 
        auto itr = p.top(); 
        p.pop(); 
        if(itr.second >= end){ 
            start = itr.second; 
            end = itr.first; 
            ans.push_back(make_pair(start,end)); 
        } 
    } 
    cout << "Following Activities should be selected. " << endl << endl; 
  
    for(auto itr=ans.begin();itr!=ans.end();itr++){ 
        cout << "Activity started at: " << (*itr).first << " and ends at  " << (*itr).second << endl; 
    } 
} 
  
int main() 
{ 
    vector<int>s = {1, 3, 0, 5, 8, 5}; 
    vector<int>f = {2, 4, 6, 7, 9, 9}; 
    SelectActivities(s,f); 
  
    return 0; 
} 

/////////////////////
//////////////////////
//////// Sprinklr
/*
There are digits 1-9, each having some cost, 
need to make maximum number using these digits with given amount,
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	vector<int> arr(9,0);

	int mn=INT_MAX, ind=0, cur=0;
	for(int i=0; i<9; i++){
		cin>>arr[i];
		if(arr[i] <= mn){
			mn=arr[i];
			ind=i;
		}
	}
	string s="";
	string c=to_string(ind+1);
	
	while(n >= mn){
		s = s+c;
		n = n-mn;
		cur++;
	}
	cout<<s<<endl;
	bool flag=1;
	
	while(flag)
	{
		int temp=0;
		flag=0;
		for(int i=0;i<n;i++)
		{
			if(n+mn >= arr[i]){
				temp=i;
				flag=1;
			}
			if(flag){
				char now ='0'+temp;
				s[cur++] = now;
			}
		}
	}
	if(s=="") cout<<-1<<endl;
	cout<<s<<endl;
}

/////////////////////////////////
//////////////////////////
///// Fitting Shelves problem

// https://www.geeksforgeeks.org/fitting-shelves-problem/

#include <bits/stdc++.h> 
using namespace std; 
  
void minSpacePreferLarge(int wall, int m, int n) 
{ 
    int num_m = 0, num_n = 0, min_empty = wall; 
    int p = 0, q = 0, rem; 
  
    while (wall >= n) { 
        // place as many shelves of length m in the remaining part 
        p = wall / m; 
        rem = wall % m; 
        // update output variables if curr min_empty <= overall empty 
        if (rem <= min_empty) { 
            num_m = p; 
            num_n = q; 
            min_empty = rem; 
        } 
        // place one more shelf of length n 
        q += 1; 
        wall = wall - n; 
    } 
  
    cout << num_m << " " << num_n << " " << min_empty << endl; 
} 
  
int main(){

    int wall = 24, m = 3, n = 5; 
    minSpacePreferLarge(wall, m, n); 
  
    wall = 24, m = 4, n = 7; 
    minSpacePreferLarge(wall, m, n); 
    return 0; 
} 

//////////////////
//////////////
///////////////////////

























