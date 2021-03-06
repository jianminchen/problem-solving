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
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


int main( int argc, char* argv[] ){
        
        ios::sync_with_stdio( false );

        int a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;
        string ans = "";
        
        if( (abs(a3-a4) > 1) || (a1<a3) || (a2<a3) || (a1<a4) || (a2<a4) ) cout << "-1\n";
        else if( a4 > a3 ){
                cout << "7";
                cout << "4";
                a1--;
                a2--;
                a4--;
                while( a1 > a4  ){ cout << '4'; a1--; }
                
                while( a3 != 1 ){
                        cout << "74";
                        a2--;
                        a3--;
                }
                while( a2 ){ cout << "7"; a2--; }
                cout << "4";
                cout << "\n";
        } else if( a3 > a4 ){
                

                while( a1 > a4  ){ cout << '4'; a1--; }
                cout << "7";
                a2--;
                
                while( a4 ){
                        cout << "47";
                        a2--;
                        a4--;
                }
                while( a2 ){ cout << "7"; a2--; }
                cout << "\n";
        } else {
                
                while( a1 > a3 ){ cout << '4'; a1--; }
                
                while( a3 != 1 ){
                        cout << "74";
                        a1--; a2--; a3--;
                }
                while( a2 ){ cout << "7"; a2--; }
                cout << "4\n";
                //474        74747474
        }
        
        

        return 0;
}
