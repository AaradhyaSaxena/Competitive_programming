// #include<iostream>
// using namespace std;
// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
	
//     int n,qn,b,c,d;
//     cin>>n>>qn;
//     int a[n];
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     while(qn--){
//        cin>>b;
//        if(b){
//            cin>>c;
//            a[c-1] = (!a[c-1]);
//        }
//        else{
//            cin>>c>>d;
//            if(a[d-1]){
//                cout<<"ODD"<<"\n";
//            }
//            else{
//                cout<<"EVEN"<<"\n";
//            }
//        }
//     }
// }
////////////
    // #include<iostream>
    // #include<stdio.h>
    // using namespace std;
    // int scan(){
    //     	register int c = getchar_unlocked();
    //         register int n = 0;
    //         for( ; (c<48 || c>57); c = getchar_unlocked() );
    //         for( ; (c>47 && c<58); c = getchar_unlocked() ){
    //             n = (n<<1) + (n<<3) +c -48;
    //         }
    //         return n;
    // }
    // int main()
    // {
    //     int n,q,temp1,temp2,r;
    //     n=scan();
    //     q=scan();
    //     int a[n+1];
    //     for(int i=1;i<=n;i++)
    //     {
    //         a[i]=scan();
    //     }
    //     while(q--)
    //     {
    //         temp1=scan();
    //         if(temp1)
    //         {
    //             temp2=scan();
    //             a[temp2]=!a[temp2];
    //         }
    //         else
    //         {
    //             scan();
    //             r=scan();
    //             if(a[r])
    //                 printf("ODD\n");
    //             else
    //                 printf("EVEN\n");
    //         }
    //     }
	// }
///////////////
// //// Here one thing is interesting that when I was using (~a[c-1]) for inverting the answer was incorrect
// //// but it was correct on using (1-a[c-1]);