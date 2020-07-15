https://www.interviewbit.com/problems/prime-sum/

// vector<int> Solution::primesum(int A) {
    
//     vector<int> pr;
//     vector<int> ans;
//     bool if_prime(int A);
//     pr.push_back(2);
    
//     for(int i=3; i <= A/2; i+=2){
//         if(if_prime(i)){
//             pr.push_back(i);
//         }
//     }
    
//     for(int i=0;i<pr.size(); i++){
//         if(if_prime(A-pr[i])){
//             ans.push_back(pr[i]);
//             ans.push_back( A - pr[i] );
//             return ans;
//         }
//     }
    
//     return ans;
// }

// bool if_prime(int A){
//     int flag = 1;
//     if(A==2){
//         return flag;
//     }
//     if(A%2==0){
//         flag=0;
//         return flag;
//     }
    
//     for (int p=2; p*p<=n; p++) 
//     { 
//         // If prime[p] is not changed, then it is a prime 
//         if (prime[p] == true) 
//         { 
//             // Update all multiples of p greater than or  
//             // equal to the square of it 
//             // numbers which are multiple of p and are 
//             // less than p^2 are already been marked.  
//             for (int i=p*p; i<=n; i += p) 
//                 prime[i] = false; 
//         } 
//     } 

//     for(int i=3; i*i<A; i +=2){
//         if(A%i==0){
//             flag = 0;
//             return flag;
//         }
//     }
//     return flag;
// }

////////////////////////////////////////
// int kk =10;
enum cat{ temp=7 };
vector<int> Solution::primesum(int n) {
    vector<bool> isprime(n+1);
    //memset(isprime,1,sizeof(isprime));
    
    // int i = 0128;
    // printf("%d", i);
    // cout<<endl;
    
    // int kk=20;
    // {
    // int kk =30.;
    // cout<< kk << :: kk ;
    // }
    // cout<<endl;
    
    int age = 14;
    age /= temp;
    cout<<age;
    
    cout<<endl;
    ///////////////////
    
    for(int i=0;i<=n;i++)
        isprime[i]=1;
    isprime[0]=0;
    isprime[1]=0;
    for(int i=2;i*i<=n;i++){
        if(isprime[i]){
            for(int j=i*2;j<=n;j+=i)
                isprime[j]=0;
        }
    }
    vector<int>ans(2);
    for(int i=2;i<=n/2;i++){
        if(isprime[i]&&isprime[n-i]){
            ans[0]=i;
            ans[1]=n-i;
            return ans;
        }
    }
}