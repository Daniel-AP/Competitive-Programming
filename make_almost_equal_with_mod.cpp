#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < 64; i++) {
        set<int> s;
        for(int j = 0; j < n; j++) {
            s.insert(a[j]%(1ULL<<i));
        }
        if(s.size() == 2) return void(cout << (1ULL<<i) << '\n');
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}