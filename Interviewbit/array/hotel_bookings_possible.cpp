https://www.interviewbit.com/problems/hotel-bookings-possible/

// bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
//     int n = arrive.size();
//     int demand[n];
//     // int demand[n] = { };
//     int last = *max_element(depart.begin(), depart.end());
//     int j;
//     for(int i=0; i<n; i++){
//         for( j=arrive[i]; j<=depart[i]; j++){
//             demand[j] = demand[j]+1 ;
//             if(demand[j]>K){
//                 // return 0;
//                 cout<<"0"<<endl;
//             }
//         }
//         for(int i=0; i<last; i++){
//             cout<<demand[i]<<" ";
//         }
//         cout<<endl;
//     }
    
//     return 1;
// }
///////////////////////////////////////////////////////////////////////
/////////////////////////         pair          ///////////////////////                    
///////////////////////////////////////////////////////////////////////

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int k) {
    vector <pair<int,int>> v;
    int n=arrive.size();
    for(int i=0;i<n;i++){
        v.push_back(make_pair(arrive[i],1));
        v.push_back(make_pair(depart[i],-1));
    }
    sort(v.begin(),v.end());
    int count=0;
    for(int i=0;i<2*n;i++){
        count+=v[i].second;
        if(count>k)
            return false;
    }
    return true;
}