#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    
    map<pair<int, int>, set<int>> mp;

    for(int i = 0; i < n; i++) {
        mp[{ max(0LL, i-k+1), min(n-k, i) }].insert(a[i]);
    }

    set<int> st;

    for(int i = 0; i < n; i++) {
        if(b[i] == -1) continue;
        if(st.find(b[i]) != st.end()) return void(cout << "NO" << '\n');
        if(mp[{ max(0LL, i-k+1), min(n-k, i) }].find(b[i]) == mp[{ max(0LL, i-k+1), min(n-k, i) }].end()) return void(cout << "NO" << '\n');
        st.insert(b[i]);
    }

    cout << "YES" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}