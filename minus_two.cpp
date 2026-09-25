#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> cnt;
    for(int i = 0; i < n; i++) cnt[a[i]]++;

    int ans = 0;
    for(auto [k, v]: cnt) ans = max(ans, v);

    int c = 0;
    for(int i = 0; i < n; i++) {
        if(a[i]%2) {
            c++;
        }
    }

    ans = max(ans, c);

    c = 0;
    for(int i = 0; i < n; i++) {
        if(a[i]%2 == 0 && a[i]%4 != 0) c++;
    }

    ans = max(ans, c);

    c = 0;
    for(int i = 0; i < n; i++) {
        if(a[i]%4 == 0) c++;
    }

    cout << max(ans, c) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}