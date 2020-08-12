//////

int Solution::solve(int A, int B, int C, int D, vector<string> &E) {

    queue<pair<int,pair<int,int>>>q;

    q.push({0,make_pair(A-1,B-1)});

    //vector<vector<int>>arr(E.size(),vector<int>(E[0].size(),0));

    for(int i=0;i<E.size();i++)

    for(int j=0;j<E[0].size();j++)

    {

    if(E[i][j]=='1')

    {

        

        E[i][j]='?';

    }

    }

   char b = '0'+1;

   if(A==C&&B==D)

   return 0;

    while(!q.empty())

    {

        

        pair<int,pair<int,int>>p=q.front();

        q.pop();

        int x=p.second.first,y=p.second.second;

        

        if(x==C-1 && y==D-1)

        {

        int c= E[C-1][D-1]-'0';

        return p.first;

        }

       

        for(int i=x+1;i<E.size();i++)

        {

           

           if(A-1==i && B-1 == y) //reached the same starting point

           break;

           

            if(E[i][y]=='?') //obstacle is present

            break;

 

            else if(E[i][y]=='0'|| E[i][y] > E[x][y]+1)

            {

                E[i][y] = E[x][y] + 1;

                q.push({p.first+1,make_pair(i,y)});

            }

        }

       // if(b<a)

        for(int i=x-1;i>=0;i--)

        {

             if(A-1==i && B-1 == y) //reached the same starting point

           break;

             if(E[i][y]=='?') //obstacle is present

            break;

            else if(E[i][y]=='0'||E[i][y]>E[x][y]+1)

            {

                E[i][y]=E[x][y]+1;

                q.push({p.first+1,make_pair(i,y)});

            }

        }

        //if(c<d)

        for(int i=y+1;i<E[0].size();i++)

        {

             if(A-1==x && B-1==i)

            break;

            if(E[x][i]=='?')

            break;

            else if(E[x][i]=='0'||E[x][i]>E[x][y]+1)

            {

                E[x][i]=E[x][y]+1;

                //q.push(make_pair(p.first,i));

                         q.push({p.first+1,make_pair(x,i)});

            }

        }

        //if(c>d)

        for(int i=y-1;i>=0;i--)

        {

            if(A-1==x && B-1==i)

            break;

            if(E[x][i]=='?')

            break;

            else if(E[x][i]=='0'||E[x][i]>E[x][y]+1)

            {

                E[x][i]=E[x][y]+1;

           q.push({p.first+1,make_pair(x,i)});

            }

        }

        

    }

    return -1;

}