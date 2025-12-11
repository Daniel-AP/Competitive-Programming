#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, h; cin >> n >> h;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> cur;

    for(int i = 0; i < n; i++) {
        cur.push_back(a[i]);
        sort(cur.rbegin(), cur.rend());
        int ava = h;
        for(int j = 0; j < i+1; j += 2) {
            if(cur[j] > ava) return void(cout << i << '\n');
            ava -= cur[j];
        }
    }

    cout << n << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}