//// 
// #include<iostream>
// #include<cstring>

// using namespace std;

// int main(){
//// // 	string s;

// 	int n,n1,n2,n3,l,temp;
// 	cin>>s>>n;
// 	l = s.length();
// 	for(int i=0;i<l;i++){
// 		if(s[i]>=48 && s[i]<=57){
// 			n1 = n%10;
// 			temp = (s[i] + n1);
// 			while(temp>57){
// 				temp = (temp -10);
// 			}
// 			s[i] = char(temp);
// 		}
// 		else if(s[i]>=65 && s[i]<=90){
// 			n2 = n%26;
// 			temp = (s[i] + n2);
// 			while(temp>90){
// 				temp = (temp -26);
// 			}
// 			s[i] = char(temp);
// 		}
// 		else if(s[i]>=97 && s[i]<=122){
// 			n3 = n%26;
// 			temp = (s[i] + n3);
// 			while(temp>122){
// 				temp = (temp -26);
// 			}
// 			s[i] = char(temp);
// 		}
// 	}
// 	cout<<s<<endl;
// 	return 0;
// }


/////Remember that if we directly performed operations on s[i], and at any point the value of s[i] exceeds 127, then we might get an error, so it is better to operate on a temporary vairable and then put that value equal to s[i].