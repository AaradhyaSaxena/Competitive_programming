// #include<iostream>
// #include<string>
// #define ll long long
// using namespace std;

// ll bin[32];
// int binary(ll a);

// int main()
// {
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{
// 		int n,l=0,max,pos=0;
// 		for(int i=0;i<32;i++){
// 			bin[i]=0;
// 		}
// 		cin>>n;
// 		while(n--)
// 		{
// 			int num, count=0;
// 			cin>>num;
// 			count = binary(num);
// 			if(count>l){
// 				l = count;
// 			}
// 		}
// 		// for(int i=0;i<l;i++){
// 		// 	cout<<bin[i];
// 		// }
// 		// cout<<endl;
// 		max = bin[0];
// 		for(int i=1;i<l;i++){
// 			if(max<bin[i]){
// 				max = bin[i];
// 				pos = i;
// 			}
// 		}
// 	cout<<pos<<endl;
// 	}
// 	return 0;
// }

// int binary(ll a){
// 	int count =0;
// 	for(int i=0;a>0;i++){
// 		bin[i] += a%2;
// 		a= a/2;
// 		count++;
// 	}
// 	return count;
// }

