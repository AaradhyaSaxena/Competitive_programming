//////////////////////////////
//////Stairs//////////////////

//////////////long_solution///
// #include<iostream>
// using namespace std;

// int factorial(int n){
// 	int value =1;
// 	if(n==1||n==0){
// 		return value;
// 	}
// 	else{
// 		value = n*factorial(n-1);
// 		return (value);
// 	}			
// }

// int main(){
// 	int n,count=0;
// 	cin>>n;
// 	for(int i=0;i<=n;i++){
// 		for (int j=0;j<=n/2;j++){
// 			for(int k=0;k<=n/3;k++){
// 				if(i + 2*j + 3*k ==n){
// 					count += ((factorial(i+j+k))/(factorial(i)*factorial(j)*factorial(k)));
// 				}
// 			}
// 		}
// 	}
// 	cout<<count<<'\n';
// 	return 0;
// }

/////////////////RECURSION

// #include<iostream>
// using namespace std;

// int canplace(int a, int b){
// 	if(b<=a)
// 		return true;
// 	return false;
// }

// int stairs(int n,int pos,int count){
// 	if((n-pos)==0){
// 		count++;
// 	}
// 	int move[] = {1,2,3};
// 	for(int i=0;i<2;i++){
// 		pos = move[i] + pos;
// 		if(canplace(n,pos)){
// 			stairs(n,pos,count);
// 		}
// 	}
// 	return count;
// }

// int main(){
// 	int n,count=0,pos=0;
// 	cin>>n;
// 	count = stairs(n,pos,count);
// 	cout<<count<<"\n";
// }

//////////AUTHORS SOLUTION/////

    // #include<bits/stdc++.h>
    // using namespace std;
    // int a[40]={0};
    // //tested pseudo Code : SS
    // int recursion(int n)
    // {
    //     if(n<=2)
    //     return a[n] = n;
    //     if(n==3)
    //     return a[n] = 4;
    //      if(a[n])
    //      return a[n];
    //      return a[n] = recursion(n-1)+recursion(n-2)+recursion(n-3);
    // }
    // int main()
    // {
    //     ios_base::sync_with_stdio(0);
    //     cin.tie(0);
    //     cout.tie(0);
    //     int n;
    //     cin>>n;
    //     cout<<recursion(n);
    // }

////////////////////
