// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     //freopen("input.txt","r",stdin);
// 	//freopen("output.txt","w",stdout);
//     int n;
//     scanf("%d",&n);
//     bitset<40> b(n);
//     string s=b.to_string();
//     int r=0;
//     vector<int> v;
//     int p=0;
//     for(int i=0;i<s.size();i++)
//     {
//         if(s[i]=='0'&&r==0){
//             continue;
//         }
//         else
//             r=1;
//         v.push_back(p^(s[i]-'0'));
//         p=p^(s[i]-'0');
//     }
//     int ans=0,val=1;
//     for(int i=v.size()-1;i>=0;i--)
//     {
//         ans=ans+val*v[i];
//         val=val*2;
//     }
//     cout<<ans;
//     return 0;
// }
/////////////


// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// int main(){
// 	ios_base::sync_with_stdio(false); cin.tie(NULL);
// 	ll y;
// 	cin>>y;
// 	if(y==0){
// 		cout<<0;
// 	}
// 	else
// 	{	ll pos1 = floor(log2(y));
// 		ll ans = 1<<pos1;
// 		pos1--;
// 		while(pos1>=0)
// 		{
// 			ll temp1,temp2;
// 			temp1 = ((y)&(1<<pos1));temp1 = (temp1>>pos1);
// 			temp2 = (((ans)&(1<<(pos1+1)))>>(pos1+1));
// 			ll temp3 = temp1^temp2;
// 			temp3 = (temp3<<pos1);
// 			ans = ans|temp3;pos1--;
// 		}
// 		cout<<ans;
// 	}
// 	return 0;
// }

/////////////

// #include<iostream>
// using namespace std;
// int main(){
// 	long long int n,x=0;
// 	cin >> n;
// 	while(n>0)
// 		{x=x^n;
// 		n=n/2;}
// cout << x << endl;
// return 0;}

////////////