#include <iostream>
#include <stdio.h>

using namespace std;

int prime( int a);
int main(){
  int n;
  int a,b,c,d;
  cin>>n;
  while(n--){
    cin>>a>>b;
    int i = a;

    if(i==1){
      cout<<i+1<<endl;
      i += 2;
    }

    if(i==2){
      cout<<i<<endl;
      i +=1;
    }

    if(i>2){
      // for even numbers
      while(i%2==0){
        i +=1;
      }
      while(i<=b){
        if( prime(i)){
          cout<<i<<endl;}
        i +=2;
      } 

    }
    cout<<endl;
  } 
  return 0;
}


int prime(int a){
  bool flag = true;
  for (int j = 3; j*j<= a; j++){
    if(a%j ==0){
      flag = false;
      break;
    }

  }
  return flag;
}