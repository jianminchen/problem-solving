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
#include <fstream>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        long long A, B, C, D;
        cin >> A >> B >> C >> D;
        long long res = (100LL * (D-B)) / (C-A);
        cout << res / 100; cout << ","; cout << setw(2) << setfill('0') << res % 100 << "\n";
    }

	return 0;
}

















