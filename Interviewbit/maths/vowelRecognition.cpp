// #include<iostream>
// #include<string>
// using namespace std;

// int vovel(char a);
// int vov[10] = {'a','e','i','o','u','A','E','I','O','U'};
// int main()
// {
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{
// 	string s,s1,temp;
// 	int count=0;
//     cin>>s;
// 	int len = s.length();
// 	for(int i=0;i<s.length();i++)
// 	{	
// 		int inc =0;
// 		for(int j=i;j<s.length();j++)
// 		{
// 			temp = s.substr(i,j);
// 			s1.append(temp);
// 			if(!s1.find(temp))
// 			{
// 				while(vovel(s[j]))
// 				{
// 				inc ++;
// 				break;
// 				}
// 			}
// 			count = count + inc;
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

// ////////////
// #include<iostream>
// #include<string>
// using namespace std;

// int vowel(string a);
// int vov[10] = {'a','e','i','o','u','A','E','I','O','U'};
// int main()
// {
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{
// 	string s, temp, s1;
// 	int count=0;
// 	cin>>s;
// 	// s1 = s.substr(0,2);
// 	for(int i=0; i<s.length();i++)
// 	{
// 		int incr = 0;
// 		for(int j=i; j<s.length();j++)
// 		{
// 			temp = s.substr(i,j);
// 			s1.append(temp);
// 			if(!s1.find(temp))
// 			{
// 				while(vowel(temp))
// 				{
// 					incr++;
// 					break;
// 				}
				
// 			}
// 			count = count + incr;

// 		}
// 	}
// 	cout<<count<<endl;
// 	}
// 	return 0;

// }

// int vowel(string a)
// {
// 	for(int i=0;i<10;i++)
// 	{
// 		if(a.find(vov[i]))
// 		{
// 			return 1;
// 		}
// 	}
// 	return 0;
// }