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

///// nference

from collections import defaultdict
string = "abaab"
curr = 0
elements = []
for char in string:
  curr_char = ord(char) - ord('a')
  curr = curr^(1<<curr_char)
  elements.append(curr)
MAP = defaultdict(lambda : 0)

result = 0;
for element in elements:
  for val in range(-1,26):
    if val == -1:
      curr = 0
    else:
      curr = (1<<val)
    curr_xor = curr^element;
    result += MAP[curr_xor];
  MAP[element] +=1 ;
print(result)

///////////////////

#include <bits/stdc++.h>
using namespace std;

int main(){
	string s = "abaab";
	int curr =0;
	int n = s.length();
	vector<char> elements;
	for(auto ch : s){
		int curr_char = ch-'a';
		curr = curr^(1<<curr_char);
		elements.push_back(curr);
	}
	unordered_map<int,int> mp;
	int result = 0;
	for(int i=0; i<elements.size(); i++){
		int curr = 0;
		for(int j=0; j<26; j++){
			curr = (1<<j);
			int curr_xor = curr^elements[i];
			result += mp[curr_xor];
		}
		mp[elements[i]]++;
	}
	cout<<result<<endl;
}

///////////////
///////////////

//////////////////
