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

//////////https://www.hackerrank.com/test/bs7mnmssbqo/questions/522cc2ff85742

//// Super stack
////// very nice question

/*
Make a pair for all values with their time stamp
take a time stamp for all the modifications
then when you print the final element and 
check only for modifications that came after that element was added.
use binary search for timestamp.
*/

void superStack(vector <string> operations) {
    vector<pair<int,int>> stk;
    vector< pair<int,pair<int,int>> > changes;
    int n = operations.size();
    for(int i=0; i<n; i++){
        stringstream ss(operations[i]);
        string temp; int a,b;
        if(ss>>temp){
            if(temp=="push"){
                if(ss>>a){
                    stk.push_back(make_pair(a,i));
                    cout<<a<<endl;
                }
            }
            else if(temp=="inc"){
                if(ss>>a and ss>>b){
                    changes.push_back(make_pair(i, make_pair(a,b)));
                }
                if(!stk.empty()){
                    pair<int,int> pr = stk.back();
                    int time = pr.second;
                    int val = pr.first;
                    for(int j=0; j<)
                    cout<<c<<endl;
                }else{
                    cout<<"EMPTY"<<endl;
                }
            }
            else{
                stk.pop_back();
                if(!stk.empty()){
                    int c1 = stk.back();
                    cout<<c1<<endl;
                }else{
                    cout<<"EMPTY"<<endl;
                }
            }
        }
    }
}

//tle

// void superStack(vector <string> operations) {
//     vector<int> stk;
//     int n = operations.size();
//     for(int i=0; i<n; i++){
//         stringstream ss(operations[i]);
//         string temp; int a,b;
//         if(ss>>temp){
//             if(temp=="push"){
//                 if(ss>>a){
//                     stk.push_back(a);
//                     cout<<a<<endl;
//                 }
//             }
//             else if(temp=="inc"){
//                 if(ss>>a and ss>>b){
//                     for(int i=0; i<a and i<stk.size(); i++){
//                         stk[i] += b;
//                     }
//                 }
//                 if(!stk.empty()){
//                     int c = stk.back();
//                     cout<<c<<endl;
//                 }else{
//                     cout<<"EMPTY"<<endl;
//                 }
//             }
//             else{
//                 stk.pop_back();
//                 if(!stk.empty()){
//                     int c1 = stk.back();
//                     cout<<c1<<endl;
//                 }else{
//                     cout<<"EMPTY"<<endl;
//                 }
//             }
//         }
//     }
// }








