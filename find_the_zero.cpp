#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int ask(int i, int j) {

    cout << "? " << i << ' ' << j << endl;
    int x; cin >> x;

    return x;

}

void solve() {

    int n; cin >> n;
    
    if(ask(1, 2)) return void(cout << "! " << 1 << endl);
    else if(ask(2, 3)) return void(cout << "! " << 2 << endl);
    else if(ask(3, 1)) return void(cout << "! " << 3 << endl);

    for(int i = 4; i+1 <= 2*n; i += 2) {
        if(ask(i, i+1)) return void(cout << "! " << i << endl);
    }

    cout << "! " << 2*n << endl;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}