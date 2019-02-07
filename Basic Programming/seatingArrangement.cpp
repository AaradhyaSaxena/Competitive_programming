// #include <iostream>
// using namespace std;

// int oppo(int a);
// string pos(int a);

// int main(){
//   int t,a;
//   cin>>t;
//   while(t--){
//     cin>>a;
//     cout<<oppo(a)<<" "<<pos(a)<<endl;
//   }
//   return 0;
// }

// int oppo(int a){
//   int o;
//   int m = a%12;
//   int d = a/12;

//   if (m ==0){
//     m = 12;
//     d = d-1;   
//   }

//   o = 13- m + d*12; 
//   return o;
// }

// string pos(int a){
//   string s;
//   string s1 = ("AS");
//   string s2 = ("MS");
//   string s3 = ("WS");

//   if(a%6==0 || (a-1)%6==0){
//     s = s3;
//   }
//   else if((a%3 == 0 && a%6 !=0 )||((a-1)%3 == 0 && (a-1)%6 !=0 )){
//     s = s1;
//   }
//   else
//     s = s2;
//   return s;
// }