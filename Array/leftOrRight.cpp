// ///////////////////
// #include<iostream>
// using namespace std;
// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

//     int n,q;
// 	cin>>n>>q;
// 	int a[n][2];
// 	for(int i=0;i<n;i++){
// 		a[i][0] = i;
// 		cin>>a[i][1];
// 	}
// 	// for(int i=0;i<n;i++){
// 	// 	for(int j=0;j<2;j++){
// 	// 		cout<<a[i][j];
// 	// 	}
// 	// 	cout<<endl;
// 	// }

// // 	while(q--){
// 		int y,z,count=0;
// 		char d;
// 		cin>>y>>z>>d;

// 		while(a[y][1] != z){
// 			count++;
// 			if(d==76){
// 				cout<<"done";
// 				y = ((y- 1+ n)%n);
// 			}
// 			else
// 				y = ((y+ 1+ n)%n);	
// 		}
// 		cout<<count<<"\n";
// 		cout<<"done";
// // 	}
// }


// //// If we enter a character in int, it will not read it. It won't just automatically take its ASCII value.
// //// But if we put a integer in character it will take the ASCII value of the integer.