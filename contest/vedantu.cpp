/////////// Vedantu

///// boxes

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll query(vector<ll> &bit,int index)
{
    ll sum=0;
    while(index > 0){
        sum += bit[index];
        index -= index&(-index);
    }
    return sum;
}
void update(vector<ll> &bit, int index, ll val, int n){
    while(index <= n){
        bit[index] += val;
        index += index&(-index);
    }
}
ll query(vector<ll> &bit1,vector<ll> &bit2,int l,int r,int n){
    ll sum_r = query(bit1,r)*r-query(bit2,r);
    return sum_r;
}
void update(vector<ll> &bit1,vector<ll> &bit2,int l,int r,ll val,int n)
{
    update(bit1,l,val,n); update(bit1,r+1,-val,n);
    update(bit2,l,val*(l-1),n); update(bit2,r+1,-val*r,n);
}

vector<ll> bit1(1000005), bit2(1000005);
int main()
{
    int n,q;
    cin>>n>>q;
    while(q--)
    {
        int flag; cin>>flag;
        if(flag){
            ll val; cin>>val;
            int first=1, last=n, mid;
            while(last>first)
            {
                mid = (last+first)>>1;
                if(query(bit1, bit2, 0, mid, n) < val)
                    first = mid+1;
                else
                    last = mid;
            }
            if(first > last) first=n+1;
            else if(first == last && query(bit1,bit2,0,first,n) <val) first=n+1;
            cout<<first<<endl;
        }
        else
        {
            int l,r,val;
            cin>>l>>r>>val;
            update(bit1,bit2,l,r,val,n);
        }
    }
    return 0;
}
////////////////////
////  profit maximization

long long solve (int N, vector<int> P_i) {
   ll dp[N+2];
   for(int i=0; i<N; i++){
      dp[i]=P_i[i];
   }
   for(int i=N-1; i>=0; i--){
      ll temp = 0;
      for(int j=i+1; j<N; j++){
         if((P_i[j]%P_i[i])==0){
            temp = max(temp, dp[j]);
         }
      }
      dp[i] += temp;
   }
   ll ans = INT_MIN;
   for(int i=0; i<N; i++){
      ans = max(ans, dp[i]);
   }
   return ans;
}

///////////////////
//////////










