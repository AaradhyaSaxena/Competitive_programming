////// Postman //////////

////// Tourist city
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

// Feel free to copy this class for later reuse!

class UnionFind {
    vector<int> parent, size;
public:
    UnionFind(int n) {
        parent.resize(n); size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i; size[i] = 1;
        }
    }
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]); // Path compression
    }
    bool Union(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (size[pu] > size[pv]) { // Union by larger size
            size[pu] += size[pv];
            parent[pv] = pu;
        } else {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> connectedCities(int n, int threshold, vector<int> origin, vector<int> dest) {
        UnionFind uf(n+1);
        for (int i = 1; i <= n; i++)
            for (int j = i * 2; j <= n; j += i)
                if (i > threshold)
                    uf.Union(i, j);
        vector<int> ans;
        for (int i =0; i<origin.size(); i++) 
        {
            int pa = uf.find(origin[i]);
            int pb = uf.find(dest[i]);
            ans.push_back(pa == pb);
        }
        return ans;
    }
};

//////////////////////////
//// Cartridge recycle

#include<bits/stdc++.h>
using namespace std;

int main() 
{ 
    int c=9,d=10,r=2,p=2;
    int count=0;
    while(c!=0){
    if(c>=1 && d>=p){count++;c=c-1; d=d-p;}
    if(c>=1 && d<p){c=c-1;d=d+r;}
    }
    cout<<"   "<<count;
    return 0; 
}

////////////////////
//////////////////////////////
//// Pagination

#include <bits/stdc++.h>
using namespace std;


bool cmp0A(vector <string> a, vector <string> b)
{
    return ( a[0] < b[0] );
}
bool cmp0D(vector <string> a, vector <string> b)
{
    return a[0]>b[0];
}
bool cmp1A(vector <string> a, vector <string> b)
{
    return stoi(a[1]) < stoi(b[1]);
}
bool cmp1D(vector <string> a, vector <string> b)
{
    return stoi(a[1]) > stoi(b[1]);
}
bool cmp2A(vector <string> a, vector <string> b)
{
    return stoi(a[2]) < stoi(b[2]);
}
bool cmp2D(vector <string> a, vector <string> b)
{
    return stoi(a[2]) > stoi(b[2]);
}
vector<string> fetchItems(vector<vector<string>>items,int sortParameter,int sortOrder,int itemsPerPage,
    int PageNumber)
{
    switch(sortParameter){
        case 0:
            switch(sortOrder){
                case 0:
                    sort(items.begin(),items.end(),cmp0A);
                    break;
                default:
                    sort(items.begin(),items.end(),cmp0D);
            }
            break;
        case 1:
            switch(sortOrder){
                case 0:
                    sort(items.begin(),items.end(),cmp1A);
                    break;
                default:
                    sort(items.begin(),items.end(),cmp1D);
            }
            break;

        default:
            switch(sortOrder){
                case 0:
                    sort(items.begin(),items.end(),cmp2A);
                    break;
                default:
                    sort(items.begin(),items.end(),cmp2D);
            }
    }

    int first=PageNumber*itemsPerPage;
    vector<string>res;
    if(first>=items.size())
    {
        return res;
    }

    int last;
    if(items.size()%itemsPerPage!=0)
        last = first + (items.size() % itemsPerPage) -1;
    else
        last = first + itemsPerPage - 1;

    for(int i = first; i <= last; i++)
        res.push_back(items[i][0]);

    return res;
}

////////////////////
// Postman SDE Questions
// Almost Equivalent Strings

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solve(vector<string> s, vector<string> t){
    vector<string> res;

    for(int i = 0; i < s.size(); i++){
        unordered_map< char, int> mp;

        for(int j = 0; j < s[i].length(); j++)
            mp[s[i][j]]++;

        for(int j = 0; j < t[i].length(); j++)
            mp[t[i][j]]--;

        int ans = 1;
        for(auto it = mp.begin(); it != mp.end(); it++){

               if( abs(mp[it->first]) > 3){
                   ans = 0;
                   break;
               }
        }

        if(ans)
            res.push_back("YES");
        else
            res.push_back("NO");
    }

    return res;
}
int main()
{
   int n;
   cin>>n;

    vector<string> s(n,"");

    for(int i = 0; i < n; i++)
        cin>>s[i];

    vector<string> t(n,"");

    for(int i = 0; i < n; i++)
        cin>>t[i];

    vector<string> res = solve(s, t);

    for(int i = 0; i < n; i++)
        cout<< res[i]<< " ";

    cout<<endl;

   return 0;
}

/////////////////////////
// Postman SDE problems
// Tourist on the move
#include <iostream>
#include <vector>

using namespace std;

class DSU {
public:
    vector<int> parent;
    DSU(int numCities) {
        parent.resize(numCities, -1);
    }
    int getParent(int a) {

        if(parent[a] == -1){
            return a;
        }

        return parent[a] = getParent(parent[a]);
    }
    void merge(int a, int b) {
        a = getParent(a);
        b = getParent(b);

        if(a != b){
            parent[b] = a;
        }
    }
};

vector<int> connectedCities(int numCities, int threshold, vector<int> originCities, vector<int> destinationCities) {
    DSU dsu(numCities + 1);

    for(int i = threshold + 1; i <= numCities; i++)
        for(int mul = 2; i * mul <= numCities; mul++)
            dsu.merge(i, i * mul);

    vector<int> res;
    for(int i = 0; i < originCities.size(); i++)
        res.push_back( (dsu.getParent(originCities[i]) == dsu.getParent(destinationCities[i]))? 1 : 0);

    return res;
}


int main(){
    int numCities, threshold;
    cin>> numCities >> threshold;

    int q;
    cin>>q;

    vector<int> originCities(q, 0),  destinationCities(q, 0);

    for(int i = 0; i < q; i++)
        cin >> originCities[i];

    for(int i = 0; i < q; i++)
        cin >> destinationCities[i];

    vector<int> res =  connectedCities(numCities, threshold, originCities, destinationCities);

    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<"\n";

    return 0;
}
////////////////////////
//////////////////////////

////https://leetcode.com/discuss/interview-question/406138/IBM-or-OA-2019-or-Large-Responses-or-Backend
////https://leetcode.com/discuss/interview-question/892579/paint-the-ceiling-swe-hackerrank-test

///////////////////////
/// large responses

int main()
{
	string s;
	int count = 0;
	int countOfExceed = 0;
	int TotalBytes = 0;
	
	ifstream ifstream;
	ofstream ofstream;
	ifstream.open("input.txt");

	while (!ifstream.eof()) {
		count++;
		ifstream >> s;
		if (count % 7 == 0) {
			if (stoi(s) > 5000) {
				countOfExceed++;
				TotalBytes += stoi(s);
			}
		}
	}
	ifstream.close();

	ofstream.open("output.txt");
	ofstream << to_string(countOfExceed) << endl;
	ofstream << to_string(TotalBytes) << endl;
	ofstream.close();
}

//////////

























