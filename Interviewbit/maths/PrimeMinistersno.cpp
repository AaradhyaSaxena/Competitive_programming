// #include <bits/stdc++.h> 
// using namespace std; 
  
// int primes[1000];
// int SieveOfEratosthenes(int n) 
// { 
//     bool prime[n+1]; 
// 	int count =0;

//     memset(prime, true, sizeof(prime)); 
  
//     for (int p=2; p*p<=n; p++) 
//     { 
//         if (prime[p] == true) 
//         {  
//             for (int i=p*p; i<=n; i += p) 
//                 prime[i] = false; 
//         } 
//     } 
//     for (int p=2; p<=n; p++) {
// 		if (prime[p]){
// 		  	count++;
// 			primes[count-1] = p;
// 		} 
        	
// 	}	
// 	return count;
// } 

// int primesum(int a);

// int main() 
// { 
//     int n,count,sum=0,a;
// 	cin>>n;
// 	int pmnum[1000000];
//     count = SieveOfEratosthenes(n);
// 	for(int i=0;i<count;i++){
// 		if (primes[i]<10){
// 			cout<<primes[i]<<" ";
// 		}
// 		a = primes[i];
// 		while(a != 0){
// 			sum = sum + a%10;
// 			a/10;
// 		}
// 		if (primesum(sum)){
// 			cout<<sum<<" ";
// 		}
// 		// cout<<primes[i]<<' ';
// 	}
//     return 0; 
// }

// int primesum(int a){
// 	bool flag = true;
// 	for (int j = 3; j*j<= a; j++){
//     	if(a%j ==0){
//       		flag = false;
//       		break;
//     	}
// 	}
//   	return flag;
// }