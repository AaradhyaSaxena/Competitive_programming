// Anagrams
/ #include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    string a,temp;
    cin >>a;
    string b;
    cin>>b;
    
    int p[26]={0},q[26]={0}, r[26]={0};
  
    for(int i=0;i<a.length();i++){
        p[a[i]-97]++;}
    for(int i=0;i<b.length();i++){
        q[b[i]-97]++;}
 
    int sum =0;
    for(int i=0;i<26;i++){
      r[i]= abs(p[i]-q[i]);
      sum += abs(p[i]-q[i]);
    }

    int length=0,even=0;
    for(int i=0;i<26;i++){
      if (r[i] !=0){
        length++;}
      
      if (r[i]%2 ==0){
        even++;
      }
    }
    

    for(int i=0;i<26;i++){
      if(r[i] != 0 && temp[i]==0){
        if(r[i]%2 ==0){
          temp[i] = i+97;
          temp[sum-i-1] = i+97;
          r[i] = r[i]/2;
          i++;
        }
        else 
          temp[sum/2] = i+97;  
      } 
    }


    if (sum ==0){
      cout<<"YES"<<endl;
    }

    else if(length-even<=1){
      for(int i=0;i<sum;i++){
        cout<<char(temp[i]);}
    }
    else
      cout<<"NO LUCK"<<endl;

    }
    return 0;
}

///// BitSubset
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		long long int z,n,i,flag=0,res;
		cin>>z>>n;
		int a[1000005];
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		res= z&a[0];
		for(i=1;i<n;i++){
			if(res==0){
				flag=1;
				break;
			}
			else{
				res=res&a[i];
				if(res==0){
					flag=1;
					break;
				}
			}

		}
		if(flag==1){
			cout<<"Yes"<<"\n";
		}
		else{
			cout<<"No"<<"\n";
		} 
	}
}

////// BitFlipping

#include<iostream>
#define ll long long int
using namespace std;

int count_one(int a);
int right_most(int a);
int last_move(int a);
int flipped[1000000];

int main()
{
	int n,sum=0;
	cin>>n;
	while(n--){
		int a, count, temp;
		cin>>a;
		temp = a;
		count = count_one(temp);
		for(int i=sum; i<count+sum; i++){
			for(int j=0;j<count;j++){
				if(right_most(a) != flipped[j]){
					flipped[i] = right_most(a);
				}
			a = a&(a-1);
			}
			
		}
		sum = sum+ count;
	}
	if(sum%2==0){
		cout<<"A"<<endl;
	}
	else if (sum%2 !=0){
		cout<<"B"<<endl;
	}
	else
		cout<<"Error"<<endl;

	cout<<last_move(flipped[sum]) +1<<endl;
	
}

int count_one(int a){
	int count;
	while(a){
		a = a&(a-1);
		count++;
	}
	return count;
}

int right_most(int a){
	int r;
	r = a&(-a);
	return r;
}

int last_move(int a){
	int lm;
	while(a>1){
		a = a/2;
		lm++;
	}
	return lm;
}#include<iostream>
#define ll long long int
using namespace std;

int count_one(int a);
int right_most(int a);
int last_move(int a);
int flipped[1000000];

int main()
{
	int n,sum=0;
	cin>>n;
	while(n--){
		int a, count, temp;
		cin>>a;
		temp = a;
		count = count_one(temp);
		for(int i=sum; i<count+sum; i++){
			for(int j=0;j<count;j++){
				if(right_most(a) != flipped[j]){
					flipped[i] = right_most(a);
				}
			a = a&(a-1);
			}
			
		}
		sum = sum+ count;
	}
	if(sum%2==0){
		cout<<"A"<<endl;
	}
	else if (sum%2 !=0){
		cout<<"B"<<endl;
	}
	else
		cout<<"Error"<<endl;

	cout<<last_move(flipped[sum]) +1<<endl;
	
}

int count_one(int a){
	int count;
	while(a){
		a = a&(a-1);
		count++;
	}
	return count;
}

int right_most(int a){
	int r;
	r = a&(-a);
	return r;
}

int last_move(int a){
	int lm;
	while(a>1){
		a = a/2;
		lm++;
	}
	return lm;
}

/////// BitFast

#include<iostream>
#define ll long long
using namespace std;

ll countbits(ll n){
    ll count =0;
    while(n){
        n = n&(n-1);
        count++;
    }
    return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    ll x;
    while(!cin.eof())
//   
    {
        cin>>x;
        cout<<countbits(x)<<"\n";
    }
    return 0;   
}

/////FASTER////////
add cin.tie(NULL) below ios_base::sync_with_stdio(false)
also use "\n" instead of endl

//////////////////
 /// MYSTERY/////
//////////////////
#include<iostream>
#define ll long long
using namespace std;

int main(){
    ll n,a;
    while(!cin.eof()){
        cin>>n;
        a = n&(n-1);
        a = n^a;
        cout<<a<<"\n";
    }
    
}

////////// Divide Overflow

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000005];
int main()
{
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","wb",stdout);
    
    for(ll i=1;i<=1000000;i++){
        ll r=1;
        for(ll j=1;j<=20;j++){
            r=r*2;
            if(r>i){
                break;
            }
        }
        ll z= (i*r)-1;
        a[i]=z;
        //cout<<a[i]<<endl;
    }
    ll t,x;
    cin>>t;
    while(t--)
    {
        cin>>x;
        ll id = lower_bound(a+1,a+1000000+1,x)-a;
        cout<<(x-id+1)<<endl;
    }
}
///////////////////////////////

// EXPLANATION:
// We can precompute the maximum value of valid X for each divisor D. For each integer i, from 1 to 10^6, find the lowest integer which has no. of bits in its binary representation 1 greater than that of i. Let this integer be r. So we have int (log2(r)) = int (log2(i)) +1. This r is our quotient, to find the number X, multiply r and i. Thus r*i gives us the lowest invalid value for our divisor D. So the required value is (r*i-1) for each divisor D in our precomputed array.
// Now for each test case we have to find maximum value of D which has value in the precomputed array lower than X. All other possible integers greater than this D and less than X are valid divisors. This count gives us our answer.

///////////////////////////////

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define irep(i,a,b) for (int i=a;i>=b;i--)
#define pii pair <int, int>
#define pll pair <ll,ll>

using namespace std;
const int ma = 1e5+5;

int bit(ll x)
{
  int ans=0;
  while(x)
  {
    x/=2;
    ans++;
  }
  return ans;
}
bool check(ll d, ll x)
{
  if(bit(x/d)<=bit(d))
    return true;
  return false;
}

ll solve(ll x)
{
  ll l =1, r = sqrt(x);
  while(l<r)
  {
    ll m = (l+r)/2;
    if(check(m,x))
      r = m;
    else
      l = m+1;
  }
  if(!check(l,x))
    return l+1;
  else
    return l;
}

int main(int argc, char* argv[])
{
  if(argc == 2 or argc == 3) 
     freopen(argv[1], "r", stdin);
  if(argc == 3) 
     freopen(argv[2], "w", stdout);
  ios::sync_with_stdio(false);
  int t;
  cin>>t;
  assert(1<=t and t<=1e6);
  rep(i,1,t)
  {
    ll x,ans=0;
    cin>>x;
    assert(1<=x and x<=1e12);
    ll tp = solve(x);
    
    cout<<x-tp+1<<endl;
  }
  
  return 0;
}

////////////////FastScan

int scan(){
    register int c = getchar_unlocked();
    register int n = 0;
    for( ; (c<48 || c>57); c = getchar_unlocked() );
    for( ; (c>47 && c<58); c = getchar_unlocked() ){
        n = (n<<1) + (n<<3) +c -48;
    }
    return n;
}

void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
} 

////////// FactArray

#include<iostream>
using namespace std;

int main() {
int t;
  cin>>t;
  while(t--) {
    int a[200],rem,i=0,n,m=0,flag;
    cin>>n;
    flag = n; 
 
///////(m++, here we are measuring the length og the array)///////

    while(flag!=0)  {
      rem = flag%10;
      a[i] = rem;
      flag = flag/10;
      i++;  
      m++;
    } 
 
    int temp,x=0,index=0;
    for(i=2;i<n;i++)  {
      temp = 0;
      for(index=0;index<m;index++) {
        x = a[index]*i + temp;
        a[index] = x%10;
        temp = x/10;
      }
  
      while(temp!=0) {
        a[index] = temp % 10;
        temp = temp/10;
        index++;
        m++;
      }
    }
 
    for(i=m-1;i>=0;i--) {cout<<a[i];}
      cout<<"\n";
  }
  return 0;
}

// The value of 'm' is the number of digits in the current array.

/////////// Prime Minister
#include <bits/stdc++.h> 
using namespace std; 
  
int primes[1000];
int SieveOfEratosthenes(int n) 
{ 
    bool prime[n+1]; 
	int count =0;

    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        {  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=2; p<=n; p++) {
		if (prime[p]){
		  	count++;
			primes[count-1] = p;
		} 
        	
	}	
	return count;
} 

int primesum(int a);

int main() 
{ 
    int n,count,sum=0,a;
	cin>>n;
	int pmnum[1000000];
    count = SieveOfEratosthenes(n);
	for(int i=0;i<count;i++){
		if (primes[i]<10){
			cout<<primes[i]<<" ";
		}
		a = primes[i];
		while(a != 0){
			sum = sum + a%10;
			a/10;
		}
		if (primesum(sum)){
			cout<<sum<<" ";
		}
		// cout<<primes[i]<<' ';
	}
    return 0; 
}

int primesum(int a){
	bool flag = true;
	for (int j = 3; j*j<= a; j++){
    	if(a%j ==0){
      		flag = false;
      		break;
    	}
	}
  	return flag;
}

/////////BYTELANDIAN////
/////Some err///////
#include <iostream>
#define ll long long int
using namespace std;

ll memoi[100000000] ={0};

ll byte(ll n){
	if(n<100000000){
		if(memoi[n] !=0)
			return memoi[n];
		else
			if(n<12)
				return n;
			else
				memoi[n] = (byte(n/2)+ byte(n/3)+ byte(n/4));
				return memoi[n];	
	}
	else{
		return (byte(n/2)+ byte(n/3)+ byte(n/4));
		}
	return 0;
	}

int main() {
	ll n;
	while(!cin.eof()){
		cin>>n;
		cout<<byte(n)<<"\n";
	}
}

////RUNNING SOLUTION/////

#include <iostream>
#define ll long long int
using namespace std;

ll byte(ll n){
	if(n<12)
		return n;
	else
		return (byte(n/2)+ byte(n/3)+ byte(n/4));
}

int main() {
	ll n;
	while(!cin.eof()){
		cin>>n;
		cout<<byte(n)<<"\n";
	}
	return 0;
}

//////////Knights_MOve

#include<iostream>
using namespace std;

const int size=10;
long int count=0;

void print_board(int board[size][size]){
    for(int i=0;i<size;i++){
    	for(int j=0;j<size;j++)
    		cout<<board[i][j]<<" ";
    	cout<<"\n";
    }
}

bool canplace(int board[size][size],int x,int y){
    if(x<0||y<0||x>=size||y>=size) return false;
    return true;
}

void knightmove(int board[size][size],int x,int y,int n){
    if(n==0){
    	if(board[x][y]==0)
    	{
    		board[x][y]=1;
    		count++;
    	}
    	return;
    }
    int move_x[]={-2,-1,1,2,2,1,-1,-2};
    int move_y[]={1,2,2,1,-1,-2,-2,-1};
    for(int i=0;i<8;i++){
    	int movex = move_x[i]+x;
    	int movey = move_y[i]+y;
    	if(canplace(board,movex,movey)) {
    		//board[movex][movey]=1;
    		knightmove(board,movex,movey,n-1);
    		//board[x][y]=0;
    	}
    	//board[movex][movey]=0;
    }
}

int main(){
    int board[10][10]={0};
    int x,y,n;
    cin>>x>>y>>n;
    knightmove(board,x-1,y-1,n);
    //print_board(board);
    	cout<<count;
    return 0;
}

///////////// Stairs //////////
////////////long_solution///
#include<iostream>
using namespace std;

int factorial(int n){
	int value =1;
	if(n==1||n==0){
		return value;
	}
	else{
		value = n*factorial(n-1);
		return (value);
	}			
}

int main(){
	int n,count=0;
	cin>>n;
	for(int i=0;i<=n;i++){
		for (int j=0;j<=n/2;j++){
			for(int k=0;k<=n/3;k++){
				if(i + 2*j + 3*k ==n){
					count += ((factorial(i+j+k))/(factorial(i)*factorial(j)*factorial(k)));
				}
			}
		}
	}
	cout<<count<<'\n';
	return 0;
}

///////////////RECURSION

#include<iostream>
using namespace std;

int canplace(int a, int b){
	if(b<=a)
		return true;
	return false;
}

int stairs(int n,int pos,int count){
	if((n-pos)==0){
		count++;
	}
	int move[] = {1,2,3};
	for(int i=0;i<2;i++){
		pos = move[i] + pos;
		if(canplace(n,pos)){
			stairs(n,pos,count);
		}
	}
	return count;
}

int main(){
	int n,count=0,pos=0;
	cin>>n;
	count = stairs(n,pos,count);
	cout<<count<<"\n";
}

////////AUTHORS SOLUTION/////

    #include<bits/stdc++.h>
    using namespace std;
    int a[40]={0};
    //tested pseudo Code : SS
    int recursion(int n)
    {
        if(n<=2)
        return a[n] = n;
        if(n==3)
        return a[n] = 4;
         if(a[n])
         return a[n];
         return a[n] = recursion(n-1)+recursion(n-2)+recursion(n-3);
    }
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n;
        cin>>n;
        cout<<recursion(n);
    }

//////////////////
////Seive of Eratosthenes
////////
#include <bits/stdc++.h> 
using namespace std; 
  
void SieveOfEratosthenes(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          cout << p << " "; 
} 
  
// // Driver Program to test above function 
int main() 
{ 
    int n = 30; 
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl; 
    SieveOfEratosthenes(n); 
    return 0; 
}

////////Z_bitInverse
/////////////////////
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    bitset<40> b(n);
    string s=b.to_string();
    int r=0;
    vector<int> v;
    int p=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0'&&r==0){
            continue;
        }
        else
            r=1;
        v.push_back(p^(s[i]-'0'));
        p=p^(s[i]-'0');
    }
    int ans=0,val=1;
    for(int i=v.size()-1;i>=0;i--)
    {
        ans=ans+val*v[i];
        val=val*2;
    }
    cout<<ans;
    return 0;
}
///////////


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll y;
	cin>>y;
	if(y==0){
		cout<<0;
	}
	else
	{	ll pos1 = floor(log2(y));
		ll ans = 1<<pos1;
		pos1--;
		while(pos1>=0)
		{
			ll temp1,temp2;
			temp1 = ((y)&(1<<pos1));temp1 = (temp1>>pos1);
			temp2 = (((ans)&(1<<(pos1+1)))>>(pos1+1));
			ll temp3 = temp1^temp2;
			temp3 = (temp3<<pos1);
			ans = ans|temp3;pos1--;
		}
		cout<<ans;
	}
	return 0;
}

///////////HoneyComb////

//// Manhattan Distance
#include <bits/stdc++.h>
using namespace std;

int manhattan_distance(int i, int j, int x, int y)
{
    return abs(i- (x * 2 + y % 2)) + abs(j - y);
}

int arr[1000][1000];

int main()
{
    int t, n, m, q, type, x, y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                cin >> arr[i][j];

        cin >> q;
        while(q--)
        {
            int sum = 0;
            cin >> type;
            if(type == 1)
            {
                cin >> x >> y;
                for(int i = 0 ; i < 2 * n ; i++)
                    for(int j = 0 ; j < m ; j++)
                    {
                        if(manhattan_distance(i, j, x, y) == 2 && i != x * 2 + y % 2)
                            sum += arr[(i - j%2) / 2][j];
                    }
                cout << sum << endl;
            }
            else
            {
                cin >> x >> y;
                for(int i = 0 ; i < 2 * n ; i++)
                    for(int j = 0 ; j < m ; j++)
                    {
                        if(i!= x*2 + y%2)
                        {
                            if(manhattan_distance(i, j, x, y) == 4 && abs(j - y) <= 2)
                                sum += arr[(i - j%2) / 2][j];
                        }
                        else
                        {
                            if(manhattan_distance(i, j, x, y) == 2 && abs(j - y) <= 2)
                                sum += arr[(i - j%2) / 2][j];
                        }
                    }
                cout << sum << endl;
            }
        }
    }
    return 0;
}

////////////leftOrRight
///////////////////
#include<iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n,q;
	cin>>n>>q;
	int a[n][2];
	for(int i=0;i<n;i++){
		a[i][0] = i;
		cin>>a[i][1];
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<2;j++){
	// 		cout<<a[i][j];
	// 	}
	// 	cout<<endl;
	// }

// 	while(q--){
		int y,z,count=0;
		char d;
		cin>>y>>z>>d;

		while(a[y][1] != z){
			count++;
			if(d==76){
				cout<<"done";
				y = ((y- 1+ n)%n);
			}
			else
				y = ((y+ 1+ n)%n);	
		}
		cout<<count<<"\n";
		cout<<"done";
// 	}
}


//// If we enter a character in int, it will not read it. It won't just automatically take its ASCII value.
//// But if we put a integer in character it will take the ASCII value of the integer. 

///////Symmetric////////
#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int r,flag=1;
        cin>>r;
/////// The next line is important
        char mat[r][r];
/////// int mat[r][r];

        for(int i=0;i<r;i++){
            for(int j=0;j<r;j++){
                cin>>mat[i][j];
            }
        }
        //// along vertical axis
		for(int i=0;i<r;i++){
			for(int j=0;j<r/2;j++){
				if(mat[i][j] != mat[i][r-1-j]){
					flag =0;
					break;
				}
			}
			if(flag==0){
				break;
			}
		}
		// along horizontal axis
		for(int j=0;j<r;j++){
			for(int i=0;i<r/2;i++){
				if(mat[i][j] != mat[r-1-i][j]){
					flag =0;
					break;
				}
			}
			if(flag==0){
				break;
			}
		}
		if(flag==0){
			cout<<"NO\n";
		}
		else
			cout<<"YES\n";   
    }
    return 0;
}

// In the question, the input does not have spaces in between different numbers of the array
// so when we use int mat[][] then it takes the whole first line as a single entry, but when we use char mat[][] the different letters of each line are taken as single entries

//////////Transpose
#include<iostream>
#include<stdio.h>
using namespace std;


int scan(){
    register int c = getchar_unlocked();
    register int n = 0;
    for( ; (c<48 || c>57); c = getchar_unlocked() );
    for( ; (c>47 && c<58); c = getchar_unlocked() ){
        n = (n<<1) + (n<<3) +c -48;
    }
    return n;
}

int main(){
    int r,c;
    r = scan();
    c = scan();
    // cin>>r>>c;
    int mat[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            mat[i][j] = scan();
            // cin>>mat[i][j];
        }
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            cout<<mat[j][i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

///////////////a.cpp
// #include<stdio.h>
#include<iostream>
// #include<cstring>
// #include<cmath>
using namespace std;

int vovel(char a);
int vov[10] = {'a','e','i','o','u','A','E','I','O','U'};
int main()
{
	int t, count=0;
	cin>>t;
	while(t--)
	{
	string s;
    cin>>s;
	int len = s.length();
	cout<<len;
	for(int i=0;i<s.length();i++)
	{
		for(int j=i;j<s.length();j++)
		{
			
			while(vovel(s[j]))
			{
				count++;
				cout<<endl<<count;
			}
		}
	}
	cout<<count<<endl;
	}
	return 0;

}

int vovel(char a)
{
	for(int i=0;i<10;i++)
	{
		if(a==vov[i])
		{
			return 1;
		}
	}
	return 0;
}

//////////////AlphaCode

#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int temp1, temp2, tempn, l, count =1;
	int temp[5];
	int a[5000];
	// for(int i=0;i)
	// cin>>a[i];

	for(int i=0;i<l;i++){

		
		int j=0;
		temp[j] = a[0];

		if(temp[j]>2){
			continue;
		}

		else if (temp[j]==1){
			count++;
			temp[j+1] = a[i+1];
			
			if(temp[j+1]>2){
				continue;
			}
			else if(temp[j+1]==1){
				count++;
				continue;}	
		}
		else if(temp[j]==2){
			temp[j+1] = a[i+1];
			if (temp[j+1]>6){
				continue;
			}
			else if(temp[j+1]>2 && temp[j+1]<7){
				count++;
				continue;
			}
			else if (temp[j+1]==1)
				
		}
	}
}

//////////////BinaryFormAdd
#include<iostream>
#include<string>
#define ll long long
using namespace std;

ll bin[32];
int binary(ll a);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,l=0,max,pos=0;
		for(int i=0;i<32;i++){
			bin[i]=0;
		}
		cin>>n;
		while(n--)
		{
			int num, count=0;
			cin>>num;
			count = binary(num);
			if(count>l){
				l = count;
			}
		}
		// for(int i=0;i<l;i++){
		// 	cout<<bin[i];
		// }
		// cout<<endl;
		max = bin[0];
		for(int i=1;i<l;i++){
			if(max<bin[i]){
				max = bin[i];
				pos = i;
			}
		}
	cout<<pos<<endl;
	}
	return 0;
}

int binary(ll a){
	int count =0;
	for(int i=0;a>0;i++){
		bin[i] += a%2;
		a= a/2;
		count++;
	}
	return count;
}

///////////BinaryQueries
#include<iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int n,qn,b,c,d;
    cin>>n>>qn;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    while(qn--){
       cin>>b;
       if(b){
           cin>>c;
           a[c-1] = (!a[c-1]);
       }
       else{
           cin>>c>>d;
           if(a[d-1]){
               cout<<"ODD"<<"\n";
           }
           else{
               cout<<"EVEN"<<"\n";
           }
       }
    }
}
//////////
    #include<iostream>
    #include<stdio.h>
    using namespace std;
    int scan(){
        	register int c = getchar_unlocked();
            register int n = 0;
            for( ; (c<48 || c>57); c = getchar_unlocked() );
            for( ; (c>47 && c<58); c = getchar_unlocked() ){
                n = (n<<1) + (n<<3) +c -48;
            }
            return n;
    }
    int main()
    {
        int n,q,temp1,temp2,r;
        n=scan();
        q=scan();
        int a[n+1];
        for(int i=1;i<=n;i++)
        {
            a[i]=scan();
        }
        while(q--)
        {
            temp1=scan();
            if(temp1)
            {
                temp2=scan();
                a[temp2]=!a[temp2];
            }
            else
            {
                scan();
                r=scan();
                if(a[r])
                    printf("ODD\n");
                else
                    printf("EVEN\n");
            }
        }
	}
/////////////
//// Here one thing is interesting that when I was using (~a[c-1]) for in/verting the answer was incorrect
//// but it was correct on using (1-a[c-1]);

////////BitAllSUbSetSum
#include<iostream>
using namespace std;

int main(){
	int t;
	int a[15];
	cin>>t;
	while(t--){
		int n,s,flag=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cin>>s;
		////allPossibleSubSet///
		for(int i=0;i<(1<<n);i++){
			int sum=0;
			for(int j=0;j<n;j++){
				if(i & (1<<j)){
					sum = sum +a[j];
				}
			}
			if(sum==s){
				flag =1;
				break;
			}
		}
		if(flag == 1)
			cout<<"YES\n";
		else if(flag==0)
			cout<<"NO\n";
	}
}

////////BitMinAdd
#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n, count =1;
		cin>>n;
		while((n>>1)>0){
			if(n%2 !=0){
				count++;
			}
			n = n>>1;	
		}
		cout<<count<<endl;
	}
}

//////////Cypher
#include<iostream>
#include<cstring>

using namespace std;

int main(){
// // 	string s;

	int n,n1,n2,n3,l,temp;
	cin>>s>>n;
	l = s.length();
	for(int i=0;i<l;i++){
		if(s[i]>=48 && s[i]<=57){
			n1 = n%10;
			temp = (s[i] + n1);
			while(temp>57){
				temp = (temp -10);
			}
			s[i] = char(temp);
		}
		else if(s[i]>=65 && s[i]<=90){
			n2 = n%26;
			temp = (s[i] + n2);
			while(temp>90){
				temp = (temp -26);
			}
			s[i] = char(temp);
		}
		else if(s[i]>=97 && s[i]<=122){
			n3 = n%26;
			temp = (s[i] + n3);
			while(temp>122){
				temp = (temp -26);
			}
			s[i] = char(temp);
		}
	}
	cout<<s<<endl;
	return 0;
}


///Remember that if we directly performed operations on s[i], and at any point the value of s[i] exceeds 127, then we might get an error, so it is better to operate on a temporary vairable and then put that value equal to s[i].

////////Electricity
#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	int d[t], m[t], y[t], c, sum=0;
	for(int i=0;i<t;i++){
		cin>>d[i]>>m[i]>>y[i]>>c;
	}
	for(int i=0;i<t;i++){
		if(y[i]==y[i+1] && m[i]==m[i+1] && d[i]==d[i+1]-1){
			
		}
	}
}

//////////Fact
#include<iostream>
using namespace std;
 
int main()
{
 int t,n,count;
 scanf("%d",&t);
 while(t--)
  {
  count=0;
  scanf("%d",&n);
  while(n>=5)
  {
    count += n/5;
    n /= 5;
  }
  printf("%d\n",count);
  }
 return 0;
}

// // //// Find product

#include<iostream>
using namespace std;

int main() {
int t;
	cin>>t;
    int a[10],b[10],rem,i=0,m=0,flag;
    for (int j=0; j<t; j++){
		cin>>b[j];
		//// Dealing with zeros
		if(b[j]==0){
			b[j]=1;
		}
	}
    flag = b[0];
	
	while(flag!=0)  {
    	rem = flag%10;
    	a[i] = rem;
    	flag = flag/10;
    	i++;  
    	m++;
    } 
 
    int temp,x=0,index=0;
    for(i=1;i<t;i++)  {
    	temp = 0;
    	for(index=0;index<m;index++) {
        	x = a[index]*b[i] + temp;
        	a[index] = x%10;
        	temp = x/10;
        }
  
    	while(temp!=0) {
        	a[index] = temp % 10;
        	temp = temp/10;
        	index++;
        	m++;
    	}
    }
 
	while(m--){
		int j =0;
		cout<<a[j];
		j++;
		}
    cout<<"\n";
  
	return 0;
}

//////////////////

#include<iostream>
using namespace std;
 
int main(){
  long long int n, pr =1;
  cin>>n;
  long long int b[1000] = {0};
  for(int i=0; i<n; i++){
    cin>>b[i];
	//// Dealing with zeros
	if(b[i]==0){
	    b[i]=1;
	}
    pr = pr*b[i];
  }
  cout<<pr;
  return 0;
}
//////////////

#include <stdio.h>

int main(){
    long int ans;
    int n;
    scanf("%d",&n);
    int a[n];
    int i;
    for(i=0;i<n;i++)
    {
    	scanf("%d",&a[i]);
    }
    ans=1;
    for(i=0;i<n;i++)
    {
    	ans = (ans*a[i]) % (1000000007);
    }
    printf("%ld",ans);
    return 0;
}

////////JustLargerBIts
#include<iostream>
#define ll long long
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--)
	{
		ll int n,temp;
		int count=0;
		cin>>n;
		if(n%2==0){
			n = n+1;
			cout<<n<<endl;
			continue;
		}
		else
			temp = n;
			while(temp%2 != 0)
			{
			temp = temp>>1;
			count++;
			}
			n = n + (1<<count);
			cout<<n<<endl;
	}
}

///////////LoneINteger
#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n, a, count =0;
		cin>>n;
		int A[n];
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		if(n%2==0){
			cout<<"-1"<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			if(A[i]>0){
				for(int j=i+1;j<n;j++){
					if((A[i]>0 && A[j]>0) && (A[i] == A[j])){
					A[i] = -1;
					A[j] = -1;
					count = count+2;
					}	
 
				}
			}
			
		}
		for(int i=0;i<n;i++){
			if(A[i]>0){
				cout<<A[i]<<endl;
			}
		}
		if(count == n)
            cout<<"-1"<<endl;
	}
}

//////////////MagicalWords
#include<iostream>
#include<cmath>
using namespace std;

int prime(int a);
int convert(int a);
// int main(){
// 	int t,n;
// 	string s;
// 	cin>>t;
// 	while(t--){
// 		cin>>n;
// 		cin>>s;
// 		int a[500] ={0};
// 		for (int i=0;i<n;i++){
// 			a[i] = int(s[i]);
// 			if(!prime(a[i])){
// 				a[i] = convert(a[i]);
// 			}
// 		}
// 		for(int i=0;i<n;i++){
// 			cout<<char(a[i]);
// 		}
// 	}
// }
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(prime(a)){
		cout<<"ddsfd";
	}
}

int prime(int a){
	int n,r =0;
	for(int i=2;i*i<n;i++){
		if(a%i==0){
			r= 1;
		}
	}
	return r;
}

int convert(int a){
	int clone,bigger,smaller;
	for(int i=0;i<20;i++){
		if(prime(a+i)){
			bigger = a+i;
			break;
		}
	}
	for(int i=0;i<20;i++){
		if(prime(a-i)){
			smaller = a-i;
			break;
		}
	}
	if(abs(a-smaller)<=abs(bigger-a)){
		clone = smaller;
	}
	else 
		clone = (bigger);
	return clone;
}

///////MaximizeTheEarning
#include<iostream>
#include<stdio.h>
using namespace std;

int scan(){
    register int c = getchar_unlocked();
    register int n = 0;
    for( ; (c<48 || c>57); c = getchar_unlocked() );
    for( ; (c>47 && c<58); c = getchar_unlocked() ){
        n = (n<<1) + (n<<3) +c -48;
    }
    return n;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int s;
	s = scan();
	while(s--){
		int n,r;
		n = scan(); r = scan();
		int h[n];
		for(int i=0;i<n;i++){
			h[i] = scan();
		}
		int max = h[0];
		int count=1;
		for(int i=0;i<n;i++){
			if(h[i]>max){
				max=h[i];
				count++;
				// cout<<count<<"\n";
			}
		}
		cout<<count*r<<"\n";
	}

}

//////////MinUpdate
#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
		int min=k;
        for(int i=0;i<n;i++){
            cin>>a[i];
			if(a[i]<min){
				min = a[i];
			}
        }
		
		cout<<k-min<<endl;
    }
}

//////OddFreqNum
#include<iostream>
#define ll long long
using namespace std;

int main(){
	int num[100000] = {0};
	ll a[100000];
	int t;
	cin>>t;
	for(int i=0;i<2*t+1;i++){
		cin>>a[i];
	}

	for(int i=0;i<2*t+1;i++){
		num[a[i]]++;
	}
	// for(int i=0;i<10;i++){
	// 	cout<<num[i]<<"\t";
	// }

	for(int i=0;i<1000000;i++){
		if(num[i]%2 !=0){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}

///////Palindrome

#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int main(){
  int l, flag;
  string s;
  cin>>s;
  l = s.length();
  flag=1;
  for(int i=0;i<l/2;i++){
    if(s[i] != s[l-i-1]){
      flag = 0;
      break;
    }
  }
  if (flag==1){
    cout<<"YES"<<endl;
  }
  else
    cout<<"NO"<<endl;
}

/////Permute The Array

// Incomplete
#include<iostream>
using namespace std;

void bubble_sort( int A[ ], int n ) {
    int temp;
    for(int k = 0; k< n-1; k++) {
        // (n-k-1) is for ignoring comparisons of elements which have already been compared in earlier iterations

        for(int i = 0; i < n-k-1; i++) {
            if(A[ i ] > A[ i+1] ) {
                // here swapping of positions is being done.
                temp = A[ i ];
                A[ i ] = A[ i+1 ];
                A[ i + 1] = temp;
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		if(n%k==0){
			for(int i=0;i<n;i++){
				cin>>a[i];
			}
			bubble_sort(a, n);
			for(int i=0;i<n/2;i++){
				a[i] = a[i] + a[n-1-i];
				cout<<a[i];
			}
		}
		else{
			cout<<"NO\n";
		}
	}
}

////////Prime

#include <iostream>
#include <stdio.h>

using namespace std;

int prime( int a);
int main(){
  int n;
  int a,b,c,d;
  cin>>n;
  while(n--){
    cin>>a>>b;
    int i = a;

    if(i==1){
      cout<<i+1<<endl;
      i += 2;
    }

    if(i==2){
      cout<<i<<endl;
      i +=1;
    }

    if(i>2){
      // for even numbers
      while(i%2==0){
        i +=1;
      }
      while(i<=b){
        if( prime(i)){
          cout<<i<<endl;}
        i +=2;
      } 

    }
    cout<<endl;
  } 
  return 0;
}


int prime(int a){
  bool flag = true;
  for (int j = 3; j*j<= a; j++){
    if(a%j ==0){
      flag = false;
      break;
    }

  }
  return flag;
}

////RevADD

#include <iostream>
#include <cmath>
using namespace std;

int revDigit(int a);
int len (int a);

int main(){
  int a,b,c,d,e,f,n;
  cin>>n;
  while(--n>=0){
    cin>>a>>b;
    c = revDigit(a);
    d = revDigit(b);
    e = c+d;
    f = revDigit(e);
    cout<<f<<endl;
  }
  
  return 0;
}

////////Seating Arrangement

#include <iostream>
using namespace std;

int oppo(int a);
string pos(int a);

int main(){
  int t,a;
  cin>>t;
  while(t--){
    cin>>a;
    cout<<oppo(a)<<" "<<pos(a)<<endl;
  }
  return 0;
}

int oppo(int a){
  int o;
  int m = a%12;
  int d = a/12;

  if (m ==0){
    m = 12;
    d = d-1;   
  }

  o = 13- m + d*12; 
  return o;
}

string pos(int a){
  string s;
  string s1 = ("AS");
  string s2 = ("MS");
  string s3 = ("WS");

  if(a%6==0 || (a-1)%6==0){
    s = s3;
  }
  else if((a%3 == 0 && a%6 !=0 )||((a-1)%3 == 0 && (a-1)%6 !=0 )){
    s = s1;
  }
  else
    s = s2;
  return s;
}

/////////SmallFact
#include<stdio.h>
using namespace std;

int fact(int);
int fact (int n){
  int value = 1;
  if (n==1){
    return (value);
  }
  else{
    value = n*fact(n-1);
    return (value);
  }
}

int main(){
  int t,n,f;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    f = fact(n);
    printf("%d\n",f);
  }
  return 0;
}

////////////Vowel_recognition
#include<iostream>
#include<string>
using namespace std;

int vovel(char a);
int vov[10] = {'a','e','i','o','u','A','E','I','O','U'};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	string s,s1,temp;
	int count=0;
    cin>>s;
	int len = s.length();
	for(int i=0;i<s.length();i++)
	{	
		int inc =0;
		for(int j=i;j<s.length();j++)
		{
			temp = s.substr(i,j);
			s1.append(temp);
			if(!s1.find(temp))
			{
				while(vovel(s[j]))
				{
				inc ++;
				break;
				}
			}
			count = count + inc;
		}
	}
	cout<<count<<endl;
	}
	return 0;

}

int vovel(char a)
{
	for(int i=0;i<10;i++)
	{
		if(a==vov[i])
		{
			return 1;
		}
	}
	return 0;
}

////////////
#include<iostream>
#include<string>
using namespace std;

int vowel(string a);
int vov[10] = {'a','e','i','o','u','A','E','I','O','U'};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	string s, temp, s1;
	int count=0;
	cin>>s;
	// s1 = s.substr(0,2);
	for(int i=0; i<s.length();i++)
	{
		int incr = 0;
		for(int j=i; j<s.length();j++)
		{
			temp = s.substr(i,j);
			s1.append(temp);
			if(!s1.find(temp))
			{
				while(vowel(temp))
				{
					incr++;
					break;
				}
				
			}
			count = count + incr;

		}
	}
	cout<<count<<endl;
	}
	return 0;

}

int vowel(string a)
{
	for(int i=0;i<10;i++)
	{
		if(a.find(vov[i]))
		{
			return 1;
		}
	}
	return 0;
}

////////QuickSort
#include<iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int partition( ll arr[], int start, int end){
	int i = (start-1);
	int temp;
	int piv = end;
	for(int j= start; j<= end-1; j++){
		if(arr[j] < arr[piv]){
			i++;
			temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
			// swap(&arr[i], &arr[j]);
		}
	}
	// swap(&arr[i+1], &arr[end]);
	temp = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = temp;
	return (i+1);
}

void quick_sort( ll a[], int start, int end){
	if( end > start ){
		int pvtpos = partition( a, start, end);
		quick_sort(a, start, pvtpos-1);
		quick_sort(a, pvtpos+1, end);
	}
}

int main(){
	// ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin>>n;
	ll a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	quick_sort(a,0,n-1);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
    cout<<endl;
	return 0;
}

//////////KingdomOfDreams
#include<iostream>
using namespace std;

void bubble_sort( int A[ ], int n ) {
    int temp;
    for(int k = 0; k< n-1; k++) {
        for(int i = 0; i < n-k-1; i++) {
            if(A[ i ] > A[ i+1] ) {
                temp = A[ i ];
                A[ i ] = A[ i+1 ];
                A[ i + 1] = temp;
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,min=0,min1=0;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		bubble_sort(a,n);
		
		for(int i=0; i<(n/2)-1; i++){
			if( 2*a[1] < a[0] + a[n-2-(2*i)]){
				min += a[0] + 2*a[1] + a[n-1-(2*i)];
			}
			else{
				min += 2*a[0] + a[n-1-(2*i)] + a[n-2-(2*i)];
			}
		}
		if(n%2==0){
			min += a[1];
		}
		else
			min += a[0]+ a[1]+ a[2];

		cout<<min<<"\n";
	}
}

///////Keypad_Selection
#include<iostream>
using namespace std;

void selection_sort_rev( int A[ ], int n ) {
	int max,temp;
    for(int i=0;i<n;i++){
		max = i;
		for(int j=i+1;j<n;j++){
			if(A[j]>A[max]){
				max=j;
			}
		}
		temp = A[i];
		A[i] = A[max];
		A[max] = temp;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	selection_sort_rev(a,n);
	/////////////////////
// 	for(int i=0;i<n;i++){
// 	    cout<<a[i];
// 	}
// 	cout<<endl;
	/////////////////////
	int c,count=0;
	cin>>c;
	int b[n] = {0};
	int check=0;
	for(int i=0;i<c;i++){
		cin>>b[i];
		check += b[i];
	}
// 	for(int i=0;i<c;i++){
// 	    cout<<b[i]<<"  ";
// 	}
// 	cout<<check;
    
    int flag=1;
    if(n > check){
        flag=0;
        // cout<<"flag = "<<flag<<endl;;
    }
    
    if(flag==1){
        int k=0;
	    for(int i=0;i<n;i++){
		    for(int j=0; j<n; j++){
			    if(b[j]>0 && k !=n){
				    count = count + a[k]*(i+1);
				    k++;
				    // cout<<count<<endl;
				    b[j] = b[j] -1;
				    // cout<<b[j]<<endl;
			    }
		    }	
	    }
	    cout<<count<<"\n";
    }
    else 
        cout<<"-1\n";
}

/////////Insertion_Sort

#include<iostream>
using namespace std;

// void insertion_sort ( int A[ ] , int n) {
//      for( int i = 0 ;i < n ; i++ ) {
//       int temp = A[ i ];    
//       int j = i;
//           while(  j > 0  && temp < A[ j -1]) {
//                 A[ j ] = A[ j-1];   
//                 j= j - 1;
//           }
//           A[ j ] = temp;       
//      }  
// }

void insertion_sort( int a[], int b[], int n){
    for(int i=0;i<n;i++){
        int temp = a[i];
        int j = i;
        while(j>0 && temp<a[j-1]){
            b[a[j]] = j;
            a[j] = a[j-1];
			b[a[j-1]] = j+1;
            j = j-1;
        }
        a[j] = temp;
        
    }
}

int main(){
    int n;
    cin>>n;
    int a[n],o[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
		o[i] = a[i];
    }
////////////////////    
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
////////////////////    
    int b[1000];
	for(int i=0;i<n;i++){
		b[a[i]] = i+1;
	}
//////////////////////////////////	
// 	for(int i=0;i<n;i++){
//         cout<<b[a[i]]<<" ";
//     }
//     cout<<endl;
/////////////////////////////////	

    insertion_sort(a,b,n);

///////////////////////////////////////    
//     for(int i=0;i<n;i++){
//         cout<<a[i]<<" ";
//     }
//     cout<<endl;
    
// 	for(int i=0;i<n;i++){
//         cout<<b[a[i]]<<" ";
//     }
//     cout<<endl;
    
	for(int i=0;i<n;i++){
		cout<<b[o[i]]<<" ";
	}
	cout<<"\n";
}

/////////Heap_Sort

#include<iostream>
using namespace std;

void heapify(int a[], int n, int i){
	
	int largest = i;
	int l = 2*i +1;
	int r = 2*i +2;

	if(l<n && a[l] > a[largest]){
		largest = l;
	}
	if(r<n && a[r] > a[largest]){
		largest = r;
	}
	if(largest != i){
		swap( a[i], a[largest]);
		heapify( a, n, largest);
	}
} 
  
void heapSort( int a[], int n){

	for(int i= n/2 -1; i>=0; i--){
		heapify(a, n, i);
	}
	for( int i=n-1; i>=0; i--){
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	heapSort(a,n);
	for(int i=0; i<n; i++){
		cout<<a[i];
	}
}

//////// Flipping Time

#include<iostream>
using namespace std;

int bubble_sort( int a[], int n){
	int temp;
	int flag =1;
	for(int k=0; k<n; k++){
		for(int i=0; i<n-k-1; i++){
			if(a[i] - a[i+1] > 1){
				temp = a[i];
				a[i] = a[i+1]+ 1;
				a[i+1] = temp - 1;
			}
			else if(a[i] - a[i+1] == 1){
				flag = 0;
				return flag;
			}
		}
	}
	return flag;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, flag;
		cin>>n;
		int a[n];
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		flag = bubble_sort(a, n);
		if(flag==1){
			cout<<"YES\n";
			for(int i=0; i<n; i++){
				cout<<a[i]<<" ";
			}
			cout<<"\n";
		}
		else if(flag==0){
			cout<<"NO\n";
		}
	}
}

//////////////////
//////////////////

#include<iostream>
using namespace std;

int merge( int a[], int start, int mid, int end, int flag){
    int p = start, q = mid +1;
    int arr[end - start + 1], k= 0;
    for(int i=0; i<end; i++){
        if(p>mid){
            arr[k++]= a[q++];}
        else if(q>end){
            arr[k++] = a[p++] -1;}
        else if(a[p] - a[q]>1){
            arr[k++] = a[p++];}
		else if(a[p] - a[q] == 1){
			flag = 0;
			return flag;}
        else{
            arr[k++] = a[q++] + 1;}
    }
    for(int p=0; p<k; p++){
        a[start++] = arr[p];
    }
    return flag;
}

int merge_sort( int a[], int start, int end, int f){
    if(start<end){
        int mid = (start + end)/2;
        f = merge_sort(a, start, mid, f);
        f = merge_sort(a, mid+1, end, f);
    
        f = merge(a, start, mid, end, f);
    }
    return f;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, flag=1;
		cin>>n;
		int a[n];
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		flag = merge_sort(a, 0, n-1, flag);
		if(flag==1){
			cout<<"YES\n";
			for(int i=0; i<n; i++){
				cout<<a[i]<<" ";
			}
			cout<<"\n";
		}
		else if(flag==0){
			cout<<"NO\n";
		}
	}
}
////////////////
////////////////

///////////////////
#include<iostream>
using namespace std;

int merge( int a[], int start, int mid, int end, int flag){
    int p = start, q = mid +1;
    int arr[end - start + 1], k= 0;
    for(int i=0; i<end; i++){
        if(p>mid){
            arr[k++]= a[q++];}
        else if(q>end){
            arr[k++] = a[p++] -1;}
        else if(a[p] - a[q]>1){
            arr[k++] = a[p++];}
		else if(a[p] - a[q] == 1){
			flag = 0;
			return flag;}
        else{
            arr[k++] = a[q++] + 1;}
    }
    for(int p=0; p<k; p++){
        a[start++] = arr[p];
    }
    return flag;
}

int merge_sort( int a[], int start, int end, int f){
    if(start<end){
        int mid = (start + end)/2;
        f = merge_sort(a, start, mid, f);
        f = merge_sort(a, mid+1, end, f);
    
        f = merge(a, start, mid, end, f);
    }
    return f;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, flag=1;
		cin>>n;
		int a[n];
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		flag = merge_sort(a, 0, n-1, flag);
		if(flag==1){
			cout<<"YES\n";
			for(int i=0; i<n; i++){
				cout<<a[i]<<" ";
			}
			cout<<"\n";
		}
		else if(flag==0){
			cout<<"NO\n";
		}
	}
}

////////////////////
///quick bubble_sort/////////
//////////////////////
#include<iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int partition( ll arr[], int start, int end, int flag){
	int i = (start-1);
	int temp;
	int piv = end;
	for(int j= start; j<= end-1; j++){
		if(arr[piv] - arr[j] > 1){
			i++;
			temp = arr[i];
            arr[i] = arr[j] +1;
            arr[j] = temp -1;
			// swap(&arr[i], &arr[j]);
		}
		else if(arr[piv] - arr[j] = 1){
			flag = 0;
		}
	}
	// swap(&arr[i+1], &arr[end]);
	temp = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = temp;
	return (i+1);
}

void quick_sort( ll a[], int start, int end){
	if( end > start ){
		int pvtpos = partition( a, start, end, flag);
		quick_sort(a, start, pvtpos-1);
		quick_sort(a, pvtpos+1, end);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, flag=1;
		cin>>n;
		int a[n];
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		flag = merge_sort(a, 0, n-1, flag);
		if(flag==1){
			cout<<"YES\n";
			for(int i=0; i<n; i++){
				cout<<a[i]<<" ";
			}
			cout<<"\n";
		}
		else if(flag==0){
			cout<<"NO\n";
		}
	}
}

////////////CountingSort
#include<iostream>
using namespace std;

int max(int a[], int n){
	int m = a[0];
	for(int i=1; i<n; i++){
		if(m<a[i]){
			m = a[i];
		}
	}
	return m;
}

void countingSort( int a[], int aux[], int sortA[], int n){
	int k = max(a,n);

	for(int i=0; i<=k; i++){
		aux[i] = 0;
	}

	for(int i=0; i<n; i++){
		aux[a[i]]++;
	}

	int j = 0;
	for (int i=0; i<=k; i++){
		int temp = aux[i];
		while(temp--){
			sortA[j] = i;
			j++;
		}
	}
}

int main(){
	int n;
	cin>>n;
	int a[n], sortA[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int k = max(a,n);
	int aux[k+1];
	countingSort(a, aux, sortA, n);
	int i=0;
	while(i<n){
	    cout<<sortA[i]<<" "<<aux[sortA[i]]<<endl;
	    i = i+aux[sortA[i]];
	}
	return 0;
}

/////////BubbleSort

#include<iostream>
using namespace std;

void bubble_sort( int A[ ], int n ) {
    int temp;
    for(int k = 0; k< n-1; k++) {
        // (n-k-1) is for ignoring comparisons of elements which have already been compared in earlier iterations

        for(int i = 0; i < n-k-1; i++) {
            if(A[ i ] > A[ i+1] ) {
                // here swapping of positions is being done.
                temp = A[ i ];
                A[ i ] = A[ i+1 ];
                A[ i + 1] = temp;
            }
        }
    }
}

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t;
        cin>>t;
        while(t--)
        {
            int n,m;
            cin>>n>>m;
            int a[n];
            for(int i=0;i<n;i++)
            
            {
                cin>>a[i];
            }
            bubble_sort(a, n);
            int y=n-m;
            int p=0,q=0;
            for(int i=0,j=n-1;i<n-m;i++,j--)
            {
               p+=a[i];
               q+=a[j];
            }
            cout<<q-p<<"\n";
            
        }
    }

/////Radix

#include<iostream>
using namespace std;

int max(int a[], int n){
	int m = a[0];
	for(int i=1; i<n; i++){
		if(m<a[i]){
			m = a[i];
		}
	}
	return m;
}

void countingSort( int a[], int aux[], int sortA[], int n){
	int k = max(a,n);

	for(int i=0; i<=k; i++){
		aux[i] = 0;
	}

	for(int i=0; i<n; i++){
		aux[a[i]]++;
	}

	int j = 0;
	for (int i=0; i<=k; i++){
		int temp = aux[i];
		while(temp--){
			sortA[j] = i;
			j++;
		}
	}
}

void countSort(int arr[], int n, int exp) 
{ 
    int output[n]; // output array 
    int i, count[10] = {0}; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 

void radixSort( int a[], int n){
	int mx = max(a, n);

	for( int exp=1; mx/exp>0; exp *= 10){
		countSort(a, n, exp);
		for(int i=0; i<n; i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int n, i;
	cin>>n;
	int a[n];
	for(i=0; i<n; i++){
		cin>>a[i];
	}
	radixSort(a, n);
	////Prints for all values of exp
}

//////////Merge
// Number of ordered pairs
//////////////////////////
#include<iostream>
#define ll long long int
using namespace std;

ll merge(ll A[ ] , ll start, ll mid, ll end, ll count) {
	ll p = start ,q = mid+1;
	ll Arr[end-start+1] , k=0;
	for(ll i = start ;i <= end ;i++) {
		if(p > mid)    
    		Arr[ k++ ] = A[ q++] ;
		else if ( q > end)  
    		Arr[ k++ ] = A[ p++ ];
		else if( A[ p ] <= A[ q ])   
    		Arr[ k++ ] = A[ p++ ];
		else{
		    Arr[ k++ ] = A[ q++];
			count = count + (mid- p+ 1);
		}
	}
	for (ll p=0 ; p< k ;p ++) {
    	A[ start++ ] = Arr[ p ] ;                          
	}
		
	return count;
}

ll merge_sort(ll a[], ll start, ll end, ll c){
	if(start<end){
		ll mid = (start + end)/2;

		c = merge_sort(a, start, mid, c);
		c = merge_sort(a, mid+1, end, c);

		c = merge(a, start, mid, end, c);
	}
	return c;
}
int main()
{
	ll n;
	cin>>n;
	ll a[n];
	ll c=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	c = merge_sort(a,0,n,c);
	cout<<c<<"\n";
}

///////////2d_Bubble

#include<iostream>
using namespace std;

// int a[1000000][2];

void bubble_sort(int a[][2],int n, int c){
	int temp,temp1;
	for(int k=0;k<n-1;k++){
		for(int i=0;i<n-k-1;i++){
			if(a[i][1]> a[i+1][1]){
				temp = a[i][1];
				temp1 = a[i][0];
				a[i][1] = a[i+1][1];
				a[i][0] = a[i+1][0];
				a[i+1][1] = temp;
				a[i+1][0] = temp1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int a[n][2];

	for(int i=0;i<n;i++){
		a[i][0] = i;
		cin>>a[i][1];
	}

	bubble_sort(a,n,1);
	for(int i=0;i<n;i++){
		cout<<a[i][0]<<" ";
	}
	cout<<"\n";

}

/////Partitioning
#include<iostream>
using namespace std;

void bubble_sort_mod(int b[][2],int n){
	int temp,temp1;
	for(int k=0;k<n-1;k++){
		for(int i=0;i<n-k-1;i++){
			if( (b[i][0]) > (b[i+1][0])){
				temp = b[i][0];
				b[i][0] = b[i+1][0];
				b[i+1][0] = temp;
				temp1 = b[i][1];
				b[i][1] = b[i+1][1];
				b[i+1][1] = temp1;
			}
			if(b[i][0] == b[i+1][0]){
			    b[i][1] += b[i+1][1];
			    b[i+1][1] = 0;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,flag=0;
		cin>>n;
		int a[n][3], b[n][2];
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++){
		    b[i][0] = a[i][0] - a[i][1];
		    b[i][1] = a[i][2];
		}
		
		bubble_sort_mod(b,n);
// 		for(int i=0;i<n;i++){
// 		    cout<<b[i][1];
// 		}
		int sum, tsum=0;
		for(int i=0;i<n;i++){
		    tsum += b[i][1];
		}

		for(int i=0;i<n;i++){
		    sum=0;
			for(int j=0;j<i;j++){
				sum += b[j][1];
			}

			//// Dealing with the collinear points

			// int l=1; coll=b[i][1];
			// if( i-l>=0 && (b[i][1] == b[i-l][1])){
			// 	coll += b[i-l][1];
			// 	l++;
			// }
			// l=1;
			// if( i+l<=n && (b[i][1] == b[i+l][1])){
			// 	coll += b[i+l][1];
			// 	l++;
			// }

			// if( (sum == tsum - sum ) || (sum == tsum - sum - coll)) {
			// 	flag=1;
			// 	break;
			// }

			if( (sum == tsum - sum ) || (sum == tsum - sum - b[i][1])) {
				flag=1;
				break;
			}
		}
		if(flag==0){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
		}
	}
	return 0;
}
//////////////chess
#include<iostream>
using namespace std;

const int size=10;
long int count=0;

void print_board(int board[size][size]){
    for(int i=0;i<size;i++){
    	for(int j=0;j<size;j++)
    		cout<<board[i][j]<<" ";
    	cout<<"\n";
    }
}

bool canplace(int board[size][size],int x,int y){
    if(x<0||y<0||x>=size||y>=size) return false;
    return true;
}

void knightmove(int board[size][size],int x,int y,int n){
    if(n==0){
    	if(board[x][y]==0)
    	{
    		board[x][y]=1;
    		count++;
    	}
    	return;
    }
    int move_x[]={-2,-1,1,2,2,1,-1,-2};
    int move_y[]={1,2,2,1,-1,-2,-2,-1};
    for(int i=0;i<8;i++){
    	int movex = move_x[i]+x;
    	int movey = move_y[i]+y;
    	if(canplace(board,movex,movey)) {
    		//board[movex][movey]=1;
    		knightmove(board,movex,movey,n-1);
    		//board[x][y]=0;
    	}
    	//board[movex][movey]=0;
    }
}

int main(){
    int board[10][10]={0};
    int x,y,n;
    cin>>x>>y>>n;
    knightmove(board,x-1,y-1,n);
    //print_board(board);
    	cout<<count;
    return 0;
}

//////////////AlphaCode

#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int temp1, temp2, tempn, l, count =1;
	int temp[5];
	int a[5000];
	// for(int i=0;i)
	// cin>>a[i];

	for(int i=0;i<l;i++){

		
		int j=0;
		temp[j] = a[0];

		if(temp[j]>2){
			continue;
		}

		else if (temp[j]==1){
			count++;
			temp[j+1] = a[i+1];
			
			if(temp[j+1]>2){
				continue;
			}
			else if(temp[j+1]==1){
				count++;
				continue;}	
		}
		else if(temp[j]==2){
			temp[j+1] = a[i+1];
			if (temp[j+1]>6){
				continue;
			}
			else if(temp[j+1]>2 && temp[j+1]<7){
				count++;
				continue;
			}
			else if (temp[j+1]==1)
				
		}
	}
}
////////////
