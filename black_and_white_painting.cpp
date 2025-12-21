#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve(int n, int m, bool c) {

    if(n < 8 || m < 8) return void(cout << 0 << '\n');

    if(c) {
        cout << ((n-6)/2)*((m-6)/2)+((n-7)/2)*((m-7)/2);
    } else {
        cout << ((n-7)/2)*((m-6)/2)+((n-6)/2)*((m-7)/2);
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(true) {
        int n, m, c; cin >> n >> m >> c;
        if(n == m && m == c && c == 0) break;
        solve(n, m, c);
    }

    return 0;

}