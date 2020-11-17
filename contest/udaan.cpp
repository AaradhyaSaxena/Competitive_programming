////// udaan

////// Movie ticket problem

#include<bits/stdc++.h>
using namespace std;

struct screen{
     int r, c;
     set<int> aisle;
     bool g[101][101];
};

int main(){
    set<int>mp;
    screen A[101];
    int q;
    cin>>q;
    string s;
    getline(cin, s);
    while(q--){
        getline(cin, s);
        stringstream ss(s);
        string temp;
        ss>>temp;
        if(temp=="add-screen"){
            ss>>temp;
            temp=temp.substr(6);
            int snum=stoi(temp);
            if(mp.find(snum)!=mp.end()){
                cout<<"failure"<<endl;
                continue;
            }
            mp.insert(snum);
               
			ss>>temp;
			A[snum].r=stoi(temp);
			ss>>temp;
			A[snum].c=stoi(temp);

            while(ss>>temp){
                 A[snum].aisle.insert(stoi(temp));
            }
            cout<<"success"<<endl;
        }
        else if(temp=="reserve-seat"){
            ss>>temp;
            temp=temp.substr(6);
            int snum=stoi(temp);
            if(mp.find(snum)==mp.end()){
                cout<<"failure"<<endl;
                continue;
            }
            ss>>temp;

            int row=stoi(temp);
            if(row>A[snum].r){
                 cout<<"failure"<<endl;
            }

            vector<int>check;
            while(ss>>temp){
                 check.push_back(stoi(temp));
            }
               
            set<int>st;
            for(int i=0;i<check.size();i++)st.insert(check[i]);
            if(st.size()!=check.size()){
               cout<<"failure"<<endl;
               continue;
            } 
          	bool flag=true;
               
		    for(int i=0;i<check.size();i++){
		        if(check[i]>A[snum].c){
		            cout<<"failure"<<endl;
		            flag=false;
		            break;
		        }
		    }

            if(!flag){
                cout<<"failure"<<endl;
                continue;
            }
               
            for(int i=0;i<check.size();i++){
                if(A[snum].g[row][check[i]]){
                     flag=false;
                     break;
                }
            }
            if(!flag)cout<<"failure"<<endl;
            else{
                cout<<"success"<<endl;
                for(int i=0;i<check.size();i++){
                    A[snum].g[row][check[i]]=1;
                }
            }
        }
            
		else if(temp=="get-unreserved-seats"){
		    ss>>temp;
		    temp=temp.substr(6);
		    int snum=stoi(temp);
		    if(mp.find(snum)==mp.end()){
		        cout<<endl;
		        continue;
		    }
		    ss>>temp;
            int row=stoi(temp);
            if(row>A[snum].r){
                 cout<<endl;
                 continue;
            }
            for(int i=1;i<=A[snum].c;i++){
                 if(!A[snum].g[row][i])cout<<i<<" ";
            }
            cout<<endl;
        }
		else if(temp=="suggest-contiguous-seats"){
		    ss>>temp;
		    temp=temp.substr(6);
		    int snum=stoi(temp);
		    if(mp.find(snum)==mp.end()){
		        cout<<"none"<<endl;
		        continue;
		    }
            ss>>temp;
            int cs=stoi(temp);
            ss>>temp;
            int row=stoi(temp);
            ss>>temp;
            int sn=stoi(temp);
            if(row>A[snum].r){
                cout<<"none"<<endl;
                continue;
            }
            vector<int>check;
            int cnt=0;
            for(int i=sn;i<=A[snum].c;i++){
                if(A[snum].aisle.find(i)!=A[snum].aisle.end()){
                    cnt++;
                }
                if(cnt==2) break;
                if(A[snum].g[row][i]){
                    break;
                }
                check.push_back(i);
            }
            if(check.size()>=cs){
                for(int i=0;i<cs;i++)cout<<check[i]<<" ";
                cout<<endl;
                continue;
            }
            cnt=0;
            check.clear();
            for(int i=sn;i>=1;i--){
                if(A[snum].aisle.find(i)!=A[snum].aisle.end()){
                    cnt++;
                }
                if(cnt==2) break;
                if(A[snum].g[row][i]){
                    break;
                }
                check.push_back(i);
            }
            if(check.size()>=cs){
                for(int i=0;i<cs;i++){
                	cout<<check[i]<<" ";
                }
            }
            cout<<"lol";
        }
    }
}

/*
9
add-screen Screen1 12 10 4 5 8 9
add-screen Screen2 20 25 3 4 12 13 17 18
reserve-seat Screen1 4 5 6 7
reserve-seat Screen2 13 6 7 8 9 10
reserve-seat Screen2 13 13 4 5 6
get-unreserved-seats Screen2 13
suggest-contiguous-seats Screen1 3 3 4
suggest-contiguous-seats Screen2 4 12 4
suggest-contiguous-seats Screen2 4 10 3


*/

    #include<bits/stdc++.h>
    using namespace std;
     
    struct screen{
         int r, c;
         set<int> aisle;
         bool g[101][101];
    };
     
    int main(){
        set<int>mp;
        screen A[101];
        int q;
        cin>>q;
        string s;
        getline(cin, s);
        while(q--){
            getline(cin, s);
            stringstream ss(s);
            string temp;
            ss>>temp;
            if(temp=="add-screen"){
                ss>>temp;
                temp=temp.substr(6);
                int snum=stoi(temp);
                if(mp.find(snum)!=mp.end()){
                    cout<<"failure"<<endl;
                    continue;
                }
                mp.insert(snum);
     
                ss>>temp;
                A[snum].r=stoi(temp);
                ss>>temp;
                A[snum].c=stoi(temp);
     
                while(ss>>temp){
                     A[snum].aisle.insert(stoi(temp));
                }
                cout<<"success"<<endl;
            }
            else if(temp=="reserve-seat"){
                ss>>temp;
                temp=temp.substr(6);
                int snum=stoi(temp);
                if(mp.find(snum)==mp.end()){
                    cout<<"failure"<<endl;
                    continue;
                }
                ss>>temp;
     
                int row=stoi(temp);
                if(row>A[snum].r){
                     cout<<"failure"<<endl;
                }
     
                vector<int>check;
                while(ss>>temp){
                     check.push_back(stoi(temp));
                }
     
                set<int>st;
                for(int i=0;i<check.size();i++)st.insert(check[i]);
                if(st.size()!=check.size()){
                   cout<<"failure"<<endl;
                   continue;
                } 
                bool flag=true;
     
                for(int i=0;i<check.size();i++){
                    if(check[i]>A[snum].c){
                        cout<<"failure"<<endl;
                        flag=false;
                        break;
                    }
                }
     
                if(!flag){
                    cout<<"failure"<<endl;
                    continue;
                }
     
                for(int i=0;i<check.size();i++){
                    if(A[snum].g[row][check[i]]){
                         flag=false;
                         break;
                    }
                }
                if(!flag)cout<<"failure"<<endl;
                else{
                    cout<<"success"<<endl;
                    for(int i=0;i<check.size();i++){
                        A[snum].g[row][check[i]]=1;
                    }
                }
            }
            else if(temp=="get-unreserved-seats"){
                ss>>temp;
                temp=temp.substr(6);
                int snum=stoi(temp);
                if(mp.find(snum)==mp.end()){
                    cout<<endl;
                    continue;
                }
                ss>>temp;
                int row=stoi(temp);
                if(row>A[snum].r){
                     cout<<endl;
                     continue;
                }
                for(int i=1;i<=A[snum].c;i++){
                     if(!A[snum].g[row][i])cout<<i<<" ";
                }
                cout<<endl;
            }
            else if(temp=="suggest-contiguous-seats"){
                ss>>temp;
                temp=temp.substr(6);
                int snum=stoi(temp);
                if(mp.find(snum)==mp.end()){
                    cout<<"none"<<endl;
                    continue;
                }
                ss>>temp;
                int cs=stoi(temp);
                ss>>temp;
                int row=stoi(temp);
                ss>>temp;
                int sn=stoi(temp);
                if(row>A[snum].r){
                    cout<<"none"<<endl;
                    continue;
                }
                vector<int>check;
                int cnt=0;
                for(int i=sn;i<=A[snum].c;i++){
                    if(A[snum].aisle.find(i)!=A[snum].aisle.end()){
                        cnt++;
                    }
                    if(cnt==2) break;
                    if(A[snum].g[row][i]){
                        break;
                    }
                    check.push_back(i);
                }
                if(check.size()>=cs){
                    for(int i=0;i<cs;i++)cout<<check[i]<<" ";
                    cout<<endl;
                    continue;
                }
                cnt=0;
                check.clear();
                for(int i=sn;i>=1;i--){
                    if(A[snum].aisle.find(i)!=A[snum].aisle.end()){
                        cnt++;
                    }
                    if(cnt==2) break;
                    if(A[snum].g[row][i]){
                        break;
                    }
                    check.push_back(i);
                }
                vector<int> check1;
                if(check.size()>=cs){
                    for(int i=0;i<cs;i++){
                        check1.push_back(check[i]);
                        // cout<<check[i]<<" ";
                    }
                    sort(check1.begin(), check1.end());
                    for(int i=0;i<check1.size();i++){
                        cout<<check1[i]<<" ";
                    }
                    cout<<endl;
                    continue;
                }
                if(check.size()<cs){
                    cout<<"none"<<endl;
                }
            }
        }
    }

///////////
/////////////
///////////////////
/////////

// #!/usr/bin/env python
// # coding: utf-8

# In[52]:

global count,screen_id,arr,aisle_seats
arr=[[[-1 for i in range(50)] for j in range(50)] for k in range(50)]
aisle_seats={}
count=0
screen_id={}

def add_screen(screen,num_rows,seats,aisle):
    global count
    screen_id[screen]=count
    aisle_seats[count]=set(aisle)
    
    for i in range(1,num_rows+1):
        for j in range(1,seats+1):
            arr[count][i][j]=False
    
    count+=1
    

def reserve(screen,row,seats):
    if screen not in screen_id:
        return "fail"
    index=screen_id[screen]
    
    flag=True
    for seat in seats:
        if arr[index][row][seat]!=False:
            flag=False
            break
    
    if not flag:
        return "fali"
    
    for seat in seats:
        arr[index][row][seat]=True
            
    return "success"


def getunreserved(screen,row):
    if screen not in screen_id:
        return "fail"
    index=screen_id[screen]
    ans=[]
    for i in range(1,50):
        if arr[index][row][i]==False:
            ans.append(i)
        
    return ans

def suggest(screen,num_seats,row,choice):
    if screen not in screen_id :
        return "fail"
    
    index=screen_id[screen]
    
    if arr[index][row][choice]!=False:
        return "fail"
    ans1=[choice]
    for i in range(choice+1,50):
        if arr[index][row][i]==False:
            if i not in aisle_seats[index]:
                ans1.append(i)
            else:
                if (i-1 not in aisle_seats[index]):
                    ans1.append(i)
                else:
                    break
        else:
            break
   
    
    if len(ans1)>=num_seats:
        return ans1[:num_seats]
    
    ans2=[choice]
    
    for i in range(choice-1,0,-1):
        if arr[index][row][i]==False:
            if i not in aisle_seats[index]:
                ans2.append(i)
            else:
                if (i+1 not in aisle_seats[index]):
                    ans2.append(i)
                else:
                    break
        else:
            break
    
    if len(ans2)>=num_seats:
        return ans2[:num_seats]
    
    return "fail"


# In[53]:
add_screen("Screen1",12,10,[4,5,8,9])

# In[54]:
add_screen("Screen2",20,25,[3,4,12,13,17,18])

# In[55]:
response=reserve("Screen1" ,4, [5 ,6, 7])
print(response)

# In[56]:
response=reserve("Screen2" ,13,[6, 7 ,8 ,9 ,10])

# In[57]:
print(response)

# In[58]:
response=reserve("Screen2" ,13,[4,5,6])
print(response)

# In[59]:
response=getunreserved("Screen2" ,13)
print(response)

# In[60]:
response=suggest("Screen1" ,3 ,3, 4)

# In[61]:
print(response)

# In[62]:
response=suggest("Screen2" ,4 ,12, 4)

# In[63]:
print(response)

/////////////////
////////////
//////////////

#include<bits/stdc++.h>
#define ll            long long
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define rep(i,a,b)  for(ll int i=a;i<b;i++)
#define rrep(i,a,b) for(ll int i=a;i>=b;i--)
#define all(a)      (a).begin(),(a).end()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define tr(i, cont) for(auto i=cont.begin();i!=cont.end();i++)
#define ios            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define trace(x)                 cerr << #x << ": " << x << "\n";
#define trace1(x)                cerr << #x << ": " << x << "\n";
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << "\n";
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n";
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n";
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << "\n";
#define endl "\n"
using namespace std;

class Screen{
public:
    string name;
    int n,m;
    // vector<int> aisle;
    map<int,bool> aisle;
    map<pair<int,int>,bool> used;
    Screen(string str,int r,int c,vector<int> v){
        name=str;
        n=r;
        m=c;
        // used.clear();
        for(auto i:v){
            aisle[i]=1;
        }
        // cout<<"Param";
    }
    Screen(){
        // cout<<"called";
    }
};
class MovieSystem{
public:
    // vector<Screen> screens;
    map<string,Screen> sToScr;
    string addScreen(string str,int r,int c,vector<int> v){
        Screen s1(str,r,c, v);
        // screens.push_back(s1);
        sToScr[str]=s1;
        return "Success";
    }
    string book(string str,int r,vector<int> v){
        if(sToScr.find(str)==sToScr.end()) return "Failure";
        Screen *s1=&sToScr[str];
        for(auto i:v){
            if((*s1).used[{r,i}]==1) return "Failure";
        }
        for(auto i:v){
           (*s1).used[{r,i}]=1;
       
        }
        return "Success";
    }
    vector<int> getUnres(string str,int r){
        if(sToScr.find(str)==sToScr.end()) return vector<int>();
        Screen s1=sToScr[str];
        vector<int> ans;
        for(int i=1;i<=s1.m;i++){
            if(s1.used[{r,i}]!=1) ans.push_back(i);
        }
        return ans;
    }
    vector<int> suggest(string str,int num,int r,int seat){
        if(sToScr.find(str)==sToScr.end()) return vector<int>();
        Screen s1=sToScr[str];
       
        // checks
        if(s1.used[{r,seat}]==1) return vector<int>();

        if(s1.n<r || seat > s1.m) return vector<int>();


        int l=seat,rt=seat;
        for( l=seat;l>=1 && seat-l<num-1;l--){
            if(s1.aisle.find(l)!=s1.aisle.end()&& s1.aisle.find(l-1)!=s1.aisle.end()) break;
            if(s1.used[{r,l}]==1) break;
            if(seat-l == num) break;
        }
        // cout<<l<<endl;
        l=max(l,1);
        for( rt=seat;rt<=s1.m && rt-seat<num;rt++){
            if(s1.aisle.find(rt)!=s1.aisle.end() && s1.aisle.find(rt+1)!=s1.aisle.end()) break;
            if(s1.used[{r,rt}]==1) break;
            if(rt-seat == num) break;
        }
        // cout<<rt<<endl;
        if(rt-l+1 <num) return vector<int>();
        vector<int> ans;
        for(int i=0;i<num;i++){
            ans.push_back(i+l);
        }
        return ans;
    }
};

int cmd,row,col,nums,seat;
string sname;
vector<int> v;

void parse(string s){
    v.clear();

    if(s[0]=='a'){
        cmd=1;
        int idx=1;
        while(idx<s.size() && s[idx]!=' ')
            idx++;
        idx++;
        sname="";
        while(idx<s.size() && s[idx]!=' '){
            sname+=s[idx];
            idx++;
        }
        idx++;
        string temp="";
        while(idx<s.size() && s[idx]!=' '){
            temp+=s[idx];
            idx++;
        }
        row=stoi(temp);
        idx++;
        temp="";
        while(idx<s.size() && s[idx]!=' '){
            temp+=s[idx];
            idx++;
        }
        col=stoi(temp);
        idx++;
        while(idx<s.size()){
            temp="";
            while(idx<s.size() && s[idx]!=' '){
                temp+=s[idx];
                idx++;
            }
            // cout<<temp<<endl;
            int tp=stoi(temp);
            idx++;
            v.push_back(tp);
        }
        // idx++;
    }
    if(s[0]=='r'){
        cmd=2;
        int idx=1;
        while(idx<s.size() && s[idx]!=' ')
            idx++;
        idx++;
        sname="";
        while(idx<s.size() && s[idx]!=' '){
            sname+=s[idx];
            idx++;
        }
        idx++;
        string temp="";
        while(idx<s.size() && s[idx]!=' '){
            temp+=s[idx];
            idx++;
        }
        row=stoi(temp);
        idx++;
        while(idx<s.size()){
            temp="";
            while(idx<s.size() && s[idx]!=' '){
                temp+=s[idx];
                idx++;
            }
            // cout<<temp<<endl;
            int tp=stoi(temp);
            idx++;
            v.push_back(tp);
        }
       
    }
    if(s[0]=='g'){
        cmd=3;
        int idx=1;
        while(idx<s.size() && s[idx]!=' ')
            idx++;
        idx++;
        sname="";
        while(idx<s.size() && s[idx]!=' '){
            sname+=s[idx];
            idx++;
        }
        idx++;
        string temp="";
        while(idx<s.size() && s[idx]!=' '){
            temp+=s[idx];
            idx++;
        }
        row=stoi(temp);
        idx++;
    }
    if(s[0]=='s'){
        cmd=4;
        int idx=1;
        while(idx<s.size() && s[idx]!=' ')
            idx++;
        idx++;
        sname="";
        while(idx<s.size() && s[idx]!=' '){
            sname+=s[idx];
            idx++;
        }
        idx++;
        string temp="";
        while(idx<s.size() && s[idx]!=' '){
            temp+=s[idx];
            idx++;
        }
        nums=stoi(temp);
        idx++;
        temp="";
        while(idx<s.size() && s[idx]!=' '){
            temp+=s[idx];
            idx++;
        }
        row=stoi(temp);
        idx++;
        temp="";
        while(idx<s.size() && s[idx]!=' '){
            temp+=s[idx];
            idx++;
        }
        seat=stoi(temp);
        idx++;
   
    }

}
int main(){
    ios;
    // string str="123";
    // int r=1,c=1;
    // vector<int> v;
    // Screen s1(str,r,c, v);
    MovieSystem mov;
    int x;
    cin>>x;
    string s;
    cin.ignore(256,'\n');
    for(int q=0;q<x;q++){
        getline(cin,s);
        cout<<q<<" : ";
        // cout<<s<<endl;
        parse(s);
        if(cmd==1){
            // cout<<sname<<" "<<row<<" "<<col;
            string res=mov.addScreen(sname,row,col,v);
            cout<<res<<endl;
        }
        if(cmd==2){
            // cout<<sname<<" "<<row<<" ";
            string res=mov.book(sname,row,v);
            cout<<res<<endl;
        }
        if(cmd==3){
            vector<int> sol;
            sol=mov.getUnres(sname,row);
           
            for(auto i:sol){
                cout<<i<<" ";
            }

        }
        if(cmd==4){
            vector<int> sol;
            sol=mov.suggest(sname,nums,row,seat);
            // cout<<q<<" : ";
            for(auto i:sol){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

///////////////
/////////////////////////
//////////



