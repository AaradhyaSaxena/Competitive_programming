//////https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/
/////practice-problems/algorithm/help-ashu-1/editorial/

///// Fenwick tree


#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
    
int BIT[MAX];

void upd(int idx, int val)
{
    for(int i=idx; i<MAX; i += i& ~(i-1)){
    	BIT[i] += val;
    }
}

int query(int val)
{
    int ret = 0;
    while(val){
        ret += BIT[val];
        val -= val&~(val-1);
    }
    return ret;
}

int a[MAX];

int main()
{
    int n,i;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(a[i]%2 == 0)
        upd(i,1);
    }
    int q,l,r,ch;
    cin>>q;
    while(q--){
        cin>>ch>>l>>r;
        if(ch==0){
            if(r%2==1 && a[l]%2==0)
            	upd(l,-1);
            if(r%2==0 && a[l]%2==1)
            	upd(l,1);
            a[l]=r;
        }
        else if(ch==1){
            int cnt = query(r)-query(l-1);
            cout<<cnt<<endl;
        }
        else{
            int cnt = query(r)-query(l-1);
            cout<<(r-l+1)-cnt<<endl;
        }
    }
	//   fclose(stdout);
    return 0;
}

//////////////////
//////////

/*
Sorted container

At everytime we have to calculate number of elements greater than
and smaller than given element. (logn)
*/

    #include <bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
    #define MAX 100005
    int BIT[MAX];
    int n;

    void initialize(){
        for(int i=0; i<MAX; i++){
            BIT[i] = 0;
        }
    }
     
    void update(int i, int val){
        while(i<MAX){
            BIT[i] += val;
            i += i&(-i);
        }
    }
     
    int sum(int i){
        int res = 0;
        while(i>0){
            res += BIT[i];
            i -= i&(-i);
        }
        return res;
    }
     
     
    int main() {
        n=0;
        cin>>n;
        vector<int> vec;
        initialize();
        for(int i=0; i<n; i++){
            int x; cin>>x;
            vec.push_back(x);
        }
        int res = 0;
        for(int i=0; i<n; i++){
            update(vec[i],1);
            int large = i+1-sum(vec[i]);
            int small = sum(vec[i]-1);
            res += 2*1ll*min(large,small)+1;
        }
        cout<<res<<endl;
        return 0;
    }

///////////////////
///////
///////////////
