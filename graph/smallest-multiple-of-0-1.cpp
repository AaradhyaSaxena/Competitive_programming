/// https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/

/////Smallest Multiple With 0 and 1

#define pp pair<int, int>
#define MAX 1000001

queue<int> q;

string Solution::multiple(int A) {  

    while(!q.empty()) {
    	q.pop();
    }
    
    int mat[A];
    for(int i=0; i<A; i++)
    	mat[i] = -1;

    mat[ 1%A ] = -2;
    q.push( 1%A );
    while( !q.empty() ) {
        int curr = q.front(); q.pop();
        
        if(!curr) break;

        int x = (curr*10) % A;
        if(mat[x] == -1) {
            mat[x] = curr;
            q.push(x);
        }
        
        x = ( (curr*10) + 1) % A;
        if(mat[x] == -1) {
            mat[x] = curr;
            q.push(x);
        }
    }
    
    string result;
    int curr = 0;
    while(curr != -2) {
        int x = mat[curr];

        char ch = '1';
        if((x != -2) && ((x*10) % A) == curr) ch = '0';
        
        result += ch;
        curr = x;
    }
    reverse(result.begin(), result.end());
    
    return result;
}


//////////////////////////////////
string Solution::multiple(int N) {
    if(N==1) return "1";
    vector<int> p(N,-1); //parent state
    vector<int> s(N,-1); //step from parent to current
    //BFS
    int steps[2] = {0,1};
    queue<int> q;
    q.push(1);
    while (q.front() != 0)
    {
        int curr = q.front();
        q.pop();
        if(curr==0) break;
        for(int step: steps)
        {
            int next = (curr*10+step)%N;
            if(p[next]==-1)
            {
                p[next]=curr;
                s[next]=step;
                q.push(next);
            }
        }
    }
    
    //build reversed string
    deque<char> number;
    for (int state = 0; state != 1; state = p[state]) 
        number.push_front('0' + s[state]);
    number.push_front('1');
    return string(number.begin(), number.end());
}


///////////////
/// this won't work

// string helper(int A, string s1){
//     cout<<s1<<endl;
//     if(stoi(s1) %A == 0){
//         return s1;
//     }
//     string s2 = helper(A, s1+"0");
//     string s3 = helper(A, s1+"1");
    
//     return (s2.length()>=s3.length())? s2: s3;
// }
// string Solution::multiple(int A) {
//     string s1 = "1";
//     return helper(A,s1);
// }






