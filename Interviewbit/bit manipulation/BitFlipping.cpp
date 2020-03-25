///// We need to write something for coverting (a) into its inverted sequence, temp /////

// #include<iostream>
// #define ll long long int
// using namespace std;

// int count_one(int a);
// int right_most(int a);
// int last_move(int a);
// int flipped[1000000];

// int main()
// {
// 	int n,sum=0;
// 	cin>>n;
// 	while(n--){
// 		int a, count, temp;
// 		cin>>a;
// 		temp = a;
// 		count = count_one(temp);
// 		for(int i=sum; i<count+sum; i++){
// 			for(int j=0;j<count;j++){
// 				if(right_most(a) != flipped[j]){
// 					flipped[i] = right_most(a);
// 				}
// 			a = a&(a-1);
// 			}
			
// 		}
// 		sum = sum+ count;
// 	}
// 	if(sum%2==0){
// 		cout<<"A"<<endl;
// 	}
// 	else if (sum%2 !=0){
// 		cout<<"B"<<endl;
// 	}
// 	else
// 		cout<<"Error"<<endl;

// 	cout<<last_move(flipped[sum]) +1<<endl;
	
// }

// int count_one(int a){
// 	int count;
// 	while(a){
// 		a = a&(a-1);
// 		count++;
// 	}
// 	return count;
// }

// int right_most(int a){
// 	int r;
// 	r = a&(-a);
// 	return r;
// }

// int last_move(int a){
// 	int lm;
// 	while(a>1){
// 		a = a/2;
// 		lm++;
// 	}
// 	return lm;
// }#include<iostream>
// #define ll long long int
// using namespace std;

// int count_one(int a);
// int right_most(int a);
// int last_move(int a);
// int flipped[1000000];

// int main()
// {
// 	int n,sum=0;
// 	cin>>n;
// 	while(n--){
// 		int a, count, temp;
// 		cin>>a;
// 		temp = a;
// 		count = count_one(temp);
// 		for(int i=sum; i<count+sum; i++){
// 			for(int j=0;j<count;j++){
// 				if(right_most(a) != flipped[j]){
// 					flipped[i] = right_most(a);
// 				}
// 			a = a&(a-1);
// 			}
			
// 		}
// 		sum = sum+ count;
// 	}
// 	if(sum%2==0){
// 		cout<<"A"<<endl;
// 	}
// 	else if (sum%2 !=0){
// 		cout<<"B"<<endl;
// 	}
// 	else
// 		cout<<"Error"<<endl;

// 	cout<<last_move(flipped[sum]) +1<<endl;
	
// }

// int count_one(int a){
// 	int count;
// 	while(a){
// 		a = a&(a-1);
// 		count++;
// 	}
// 	return count;
// }

// int right_most(int a){
// 	int r;
// 	r = a&(-a);
// 	return r;
// }

// int last_move(int a){
// 	int lm;
// 	while(a>1){
// 		a = a/2;
// 		lm++;
// 	}
// 	return lm;
// }