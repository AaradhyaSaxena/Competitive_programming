#define<bits/stdc++.h>
#define ll long long int
#define maxN 1000
#define maxVal 100000000
#define minVal -100000000
#define mod 1000000007LL
#define gcd(a,b) __gcd(a,b)
using namespace std;
char a[maxN+5][maxN+5];
int d[maxN+5][maxN+5];

set<pair<int,pair<int,int> > > s;
set<pair<int,pair<int,int> > >::iterator it;

int r[]={0,0,1,-1};
int c[]={1,-1,0,0};

int main(){

	int n,m,q,ui,uj,vi,vj,i,j,k;
    scanf("%d%d%d",&n,&m,&q);
    for(i=0;i<n;i++)
    {
    	scanf("%s",a[i]);
    	for(j=0;j<m;j++)
    		d[i][j]=maxVal;
    }
    scanf("%d%d",&ui,&uj);
    d[ui-1][uj-1]=0;
    s.insert(make_pair(0,make_pair(ui-1,uj-1)));
    while(!s.empty())
    {
    	it=s.begin();
    	ui=(*it).second.first;
    	uj=(*it).second.second;
    	s.erase(it);
    	for(k=0;k<4;k++)
    	{
    		vi=ui+r[k];
    		vj=uj+c[k];
    		if(vi>=0&&vi<n&&vj>=0&&vj<m&&a[vi][vj]!='*'&&
    			d[vi][vj]>(d[ui][uj]+1))
    		{
    			if(d[vi][vj]!=maxVal)
    				s.erase(s.find(make_pair(d[vi][vj],make_pair(vi,vj))));
    			d[vi][vj]=d[ui][uj]+1;
    			s.insert(make_pair(d[vi][vj],make_pair(vi,vj)));
    		}
    	}
    }
    while(q--)
    {
        scanf("%d%d",&ui,&uj);
    	if(d[ui-1][uj-1]==maxVal)
    		printf("-1\n");
    	else
    		printf("%d\n",d[ui-1][uj-1]);
    }
    return 0;
}