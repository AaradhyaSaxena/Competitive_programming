///// jpmc

#include<bits/stdc++.h>
using namespace std;
int main(){
    int i, n, m, j, k, temp, team;
    cin>>n>>m>>team;
    vector<int> a;
    for(i=0;i<n;i++){
        cin>>temp;
        a.push_back(temp);
    }
    priority_queue<pair<int, int> > pq;
    i = 0;
    while(i<n&&i<m){
        pq.push(make_pair(a[i], -i));
        i++;
    }
    j = n-1;
    while(j>=0&&j>=n-m){
        if(j>=i) pq.push(make_pair(a[j], -j));
        else break;
        j--;
    }
    int ans = 0;
    while(!pq.empty()&&team--){
        cout<<pq.top().first<<" "<<-pq.top().second<<"\n";
        ans+=pq.top().first;
        int idx = -pq.top().second;
        pq.pop();
        if(idx<i){
            if(i<=j){
                pq.push(make_pair(a[i], -i));
                i++;
            }
        }
        else if(idx>j){
            if(j>=i){
                pq.push(make_pair(a[j], -j));
                j--;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}


























