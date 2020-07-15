//////////ERRORS////////////

// #include<cstring>
// #include<iostream>
// #include<cmath>

// using namespace std;

// int main(){
//     int t;
//     cin>>t;
//     while(t--)
//     {
//     string a,temp;
//     cin >>a;
//     string b;
//     cin>>b;
//     ////// We need a to initialiize them in character array as a.length() <=100;

//     int p[26]={0},q[26]={0}, r[26]={0};
  
//     for(int i=0;i<a.length();i++){
//         p[a[i]-97]++;}
//     for(int i=0;i<b.length();i++){
//         q[b[i]-97]++;}
 
//     int sum =0;
//     for(int i=0;i<26;i++){
//       r[i]= abs(p[i]-q[i]);
//       sum += abs(p[i]-q[i]);
//     }

//     int length=0,even=0;
//     for(int i=0;i<26;i++){
//       if (r[i] !=0){
//         length++;}
      
//       if (r[i]%2 ==0){
//         even++;
//       }
//     }
    

//     for(int i=0;i<26;i++){
//       if(r[i] != 0 && temp[i]==0){
//         if(r[i]%2 ==0){
//           temp[i] = i+97;
//           temp[sum-i-1] = i+97;
//           r[i] = r[i]/2;
//           i++;
//         }
//         else 
//           temp[sum/2] = i+97;  
//       } 
//     }


//     if (sum ==0){
//       cout<<"YES"<<endl;
//     }

//     else if(length-even<=1){
//       for(int i=0;i<sum;i++){
//         cout<<char(temp[i]);}
//     }
//     else
//       cout<<"NO LUCK"<<endl;

//     }
//     return 0;
// }

// //// When we I/p number having characters repeating more than 2 times
// //// then the program does accepts the 2nd i/p.