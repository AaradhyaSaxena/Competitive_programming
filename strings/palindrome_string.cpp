// /// https://www.interviewbit.com/problems/palindrome-string/

// bool isAlphabet(char c){
//     if((c>='0'&&c<='9')||(c>='a'&&c<='z')||(c>='A'&&c<='Z'))
//         return true;
//     return false;
// }
// int Solution::isPalindrome(string A) {
//     int N = A.length();
//     int i = 0, j = N-1;
//     int left = i, right= j;
    
//     int cnt=0;
//     for(int i=0; i<N; i++){
//         if(isAlphabet(A[i])){
//             cnt++;
//         }
//     }
//     if(cnt==0){
//         return 1;
//     }
    
//     while(i<=j){
//         while(!isAlphabet(A[i])){
//             i++;
//             // cout<<i<<endl;
//         }   
//         while(!isAlphabet(A[j])){
//             j--;
//             // cout<<i<<endl;
//         }
//         left = A[i]; right = A[j];
//         i++; j--;
//         if((left != right) && abs(left-right)!=32){
//             // cout<<"lol"<<endl;
//             return 0;
//         }
//     }
//     return 1;
// }
///////////////////////////////////////////////
bool isPalindrome(string s) {
    int i = 0, j = (int)s.size() - 1;
    while(i < j){
        while(i < j && !isalnum(s[i])) i++;
        while(i < j && !isalnum(s[j])) j--;
        if (toupper(s[i]) != toupper(s[j])) return false; 
        i++;
        j--;
    }
    return true;
}