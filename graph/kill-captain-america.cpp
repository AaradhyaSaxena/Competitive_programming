//////https://practice.geeksforgeeks.org/problems/kill-captain-america/0

//// kill captain america

#include <bits/stdc++.h>
#define MAXN 40000
 
using namespace std;
 
vector< int > graph[ MAXN + 1 ], graphT[ MAXN + 1 ], sol;
bool visited[ MAXN + 1 ];
int conne[ MAXN + 1 ], in[ MAXN + 1 ];
 
void dfs1( int S ) {
    visited[ S ] = true;
    int i;
    for ( i = 0; i < graph[ S ].size(); ++i ) {
        if ( !visited[ graph[ S ][ i ] ] ) {
            dfs1( graph[ S ][ i ] );
        }
    }
    sol.push_back( S );
}
 
void dfs2( int S, int c ) {
    visited[ S ] = false;
    conne[ S ] = c;
    int i;
    for ( i = 0; i < graphT[ S ].size(); ++i ) {
        if ( visited[ graphT[ S ][ i ] ] ) {
            dfs2( graphT[ S ][ i ], c );
        }
    }
}
 
int main() {
    int t, i, N, v, j, compon, M, u, ou, lim,aa,bb;
   cin>>aa;
    for(bb=0;bb<aa;bb++)
    {
    cin>>N>>M;
    int cc;
    sol.clear();
    for(cc=1;cc<=N;cc++)
    {
    graph[cc].clear();graphT[cc].clear();
visited[ cc] = false;
conne[ cc ]=in[ cc ]=0;}
    for ( i = 1; i <= N; ++i ) {
        visited[ i ] = false;
        graph[ i ].clear();
        graphT[ i ].clear();
        in[ i ] = 0;
    }
    for ( i = 1; i <= M; ++i ) {
        cin>>u>>v;
        graph[ v ].push_back( u );
        graphT[ u ].push_back( v );
    }
    for ( i = 1; i <= N; ++i ) {
        if ( !visited[ i ] ) {
            dfs1( i );
        }
    }
    compon = 0;
    for ( i = sol.size() - 1; i >= 0; --i ) {
        if ( visited[ sol[ i ] ] ) {
            dfs2( sol[ i ], compon++ );
        }
    }
    lim = compon;
    for ( i = 1; i <= N; ++i ) {
        for ( j = 0; j < graph[ i ].size(); ++j ) {
           if ( conne[ i ] != conne[ graph[ i ][ j ] ] ) {
                in[ conne[ graph[ i ][ j ] ] ] += 1;
            }
        }
    }
    ou = 0;
    for ( i = 0; i < lim; ++i ) {
        if ( in[ i ] == 0 ) {
            ++ou;
        }
    }
    if ( ou > 1 ) {
        cout<<"0\n";
    }
    else {
        ou = 0;
        for ( i = 1; i <= N; ++i ) {
            if ( in[ conne[ i ] ] == 0 ) {
                ++ou;
            }
        }
        cout<<ou<<"\n";
 
    }
   }
 
}

