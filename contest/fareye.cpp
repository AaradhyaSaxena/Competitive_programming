////// fareye

vector<int> kthPerson(int k, vector<int> p, vector<int> q) {
    int maxx = *max_element(p.begin(), p.end());
    int dp[maxx+10];
    for(int i=0; i<maxx+10; i++) dp[i]=0;
    
    int nq = q.size(), np = p.size();
    
    for(int i=0; i<np; i++){
        dp[p[i]]++;
    }
    for(int i=maxx; i>=0; i--){
        dp[i] += dp[i+1];
    }
    // for(int i=0; i<maxx+2; i++){
    //     cout<<dp[i]<<" ";
    // }cout<<endl;
    
    vector<int> ans;
    for(int i=0; i<nq; i++){
        int cnt = 0;
        if(dp[q[i]]<k){
            ans.push_back(0);
            continue;
        }
        for(int j=0; j<np; j++){
            if(p[j] >= q[i]){
                cnt++;
            }
            if(cnt==k){
                ans.push_back(j+1);
                break;
            }
        }
        if(cnt<k){
            ans.push_back(0);
        }
    }
    return ans;
}

////// Gas station

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size(), sumA =0, sumB =0;
    for(int i=0; i<n; i++){
        sumA += A[i];
        sumB += B[i];
    }
    if(sumB>sumA) return -1;
    
    int fuel = 0;
    for(int i=0; i<n; i++){
        fuel = 0;
        for(int j=i; j<n; j++){
            if(fuel<0) break;
            fuel += (A[j]-B[j]);
        }
        if(fuel>=0){
            return i;
        }
    }
    return -1;
}

//////////









