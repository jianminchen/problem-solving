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
#include <bitset>
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

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<string> w;
int n;

int64 dp[1<<13][2][14][14];
bool calc[1<<13][2][14][14];

bool ok[2][14][14][14];

int64 solve(int mask, int side, int rem, int last) {
    
    int64 &res = dp[mask][side][rem][last];
    if (calc[mask][side][rem][last]) return res;
    calc[mask][side][rem][last] = true;
    
    res = 1;
    if (rem) {
        int i, j;
        if (side) {
            i = 0;
            j = rem-1;
        } else {
            i = SIZE(w[last])-rem;
            j = SIZE(w[last])-1;
        }
        while (i < j) {
            if (w[last][i] != w[last][j]) {
                res--; break;
            }    
            i++;
            j--;
        }
    }
    
    REP(i,n) if (mask & (1<<i)) {
                        
        if (ok[side][last][i][rem]) {
            int nrem, nside, nlast;
                
            if (rem > SIZE(w[i])) {
                nrem = rem - SIZE(w[i]);
                nside = side;
                nlast = last;
            } else {
                nrem = SIZE(w[i]) - rem;
                nside = 1-side;
                nlast = i;
            }
                
           res += solve(mask ^ (1<<i),nside,nrem,nlast); 
        }
    }
            
    return res;
}

class PalindromePhrases {
public:
    long long getAmount( vector <string> words ) {
        w = words;
        n = SIZE(w);
        int all = (1<<n) - 1;

        REP(side,2) {
            REP(last,n) {
                REP(i,n) {
                    int mrem = max(SIZE(w[last]),SIZE(w[i])) + 1;
                    REP(rem, mrem) {
                       ok[side][last][i][rem] = true;
                       
                       if (side) {
                           int il = 0;
                           int ir = rem-1;
                           int chck = min(rem,SIZE(w[i]));
                           while (chck) {
                               if (w[i][il] != w[last][ir]) {
                                   ok[side][last][i][rem] = false;
                                   break;
                               }
                               il++;
                               ir--;
                               chck--;
                          }
                       } else {
                           int il = SIZE(w[last]) - rem;
                           int ir = SIZE(w[i]) - 1;
                           int chck = min(rem,SIZE(w[i]));
                           while (chck) {
                               if (w[last][il] != w[i][ir]) {
                                   ok[side][last][i][rem] = false;
                                   break;
                               }
                               il++;
                               ir--;
                               chck--;
                           }
                       }                        
                    }
                }
            }
        }

        int64 res = 0;        
        REP(i,n) res += solve(all^(1<<i), 0, SIZE(w[i]), i);
        return res;
    }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string words[]            = {"a","ba"};
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = PalindromePhrases().getAmount(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string words[]            = {"ab","bcd","efg"};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = PalindromePhrases().getAmount(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string words[]            = {"a", "bba", "abb"};
			long long expected__      = 7;

			clock_t start__           = clock();
			long long received__      = PalindromePhrases().getAmount(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string words[]            = {"aabccc", "ccbbca", "a", "acaabb", "aaa", "aab", "c", "babb", "aacaa", "b"};
			long long expected__      = 47;

			clock_t start__           = clock();
			long long received__      = PalindromePhrases().getAmount(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string words[]            = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = PalindromePhrases().getAmount(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string words[]            = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = PalindromePhrases().getAmount(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string words[]            = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = PalindromePhrases().getAmount(vector <string>(words, words + (sizeof words / sizeof words[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE

