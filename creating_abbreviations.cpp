#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<string> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];

    array<bool, 26> has{};

    for(int i = 0; i < n; i++) {
        char ch = a[i][0];
        has[ch-'a'] = 1;
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < b[i].size(); j++) {
            char ch = b[i][j];
            int k = ch-'A';
            if(!has[k]) return void(cout << "NO" << '\n');
        }
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