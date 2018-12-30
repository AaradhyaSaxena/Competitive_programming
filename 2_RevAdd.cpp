#include <iostream>
#include <cmath>
using namespace std;

int revDigit(int a);
int len (int a);

int main(){
  int a,b,c,d,e,f,n;
  cin>>n;
  while(--n>=0){
    cin>>a>>b;
    c = revDigit(a);
    d = revDigit(b);
    e = c+d;
    f = revDigit(e);
    cout<<f<<endl;
  }
  
  return 0;
}

int revDigit (int a){
  int rev = 0;
  int len (int a);
  int l = len(a);
  for (int i=0; a>0; i++){
    rev += (a%10)*pow(10,l-i-1);
    a = a/10;
    }
  return rev; 
}