#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; ++i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int sgn( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp( double a, double b ){ return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 2222

vector< int > gr[MAXN];
int color[MAXN], cc[2];

bool dfs( int u, int c ){
	color[ u ] = c;
	cc[ c ]++;
	REP( i, SIZE(gr[u]) ){
		if( color[gr[u][i]] == -1 ){
			if( !dfs( gr[u][i], 1-c ) ) return false;
		} else if( color[gr[u][i]] == color[u] ) return false;
	}
	return true;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int N, M, v, u;
	int t;
	cin >> t;
	while( t-- ){
		cin >> N >> M;
		REP( i, N ){
			gr[i].clear();
			color[i] = -1;
		}
		REP( i, M ){
			cin >> u >> v;
			gr[u].PB( v );
			gr[v].PB( u );
		}
		int ans = 0;
		REP( i, N ) if( color[i] == -1 ){
			cc[0] = cc[1] = 0;
			if( dfs( i, 0 ) ){ ans += MIN( ((cc[0])?(cc[0]):(1)), ((cc[1])?(cc[1]):(1)) ); }
			else{ ans = -1; break; } 
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}




















