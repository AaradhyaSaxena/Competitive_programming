// // #include<stdio.h>
// #include<iostream>
// // #include<cstring>
// // #include<cmath>
// using namespace std;

// int vovel(char a);
// int vov[10] = {'a','e','i','o','u','A','E','I','O','U'};
// int main()
// {
// 	int t, count=0;
// 	cin>>t;
// 	while(t--)
// 	{
// 	string s;
//     cin>>s;
// 	int len = s.length();
// 	cout<<len;
// 	for(int i=0;i<s.length();i++)
// 	{
// 		for(int j=i;j<s.length();j++)
// 		{
			
// 			while(vovel(s[j]))
// 			{
// 				count++;
// 				cout<<endl<<count;
// 			}
// 		}
// 	}
// 	cout<<count<<endl;
// 	}
// 	return 0;

// }

// int vovel(char a)
// {
// 	for(int i=0;i<10;i++)
// 	{
// 		if(a==vov[i])
// 		{
// 			return 1;
// 		}
// 	}
// 	return 0;
// }