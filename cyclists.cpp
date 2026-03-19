#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k, p, m; cin >> n >> k >> p >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0, cur = p-1;

    while(m > 0) {
        if(cur < k) {
            if(a[cur] > m) break;
            ans++;
            m -= a[cur];
            int x = a[cur];
            a.erase(a.begin()+cur);
            a.push_back(x);
            cur = n-1;
        } else {
            int mn = INF;
            for(int i = 0; i < k; i++) {
                mn = min(mn, a[i]);
            }
            if(mn > m) break;
            for(int i = 0; i < k; i++) {
                if(a[i] == mn) {
                    int x = a[i];
                    a.erase(a.begin()+i);
                    a.push_back(x);
                    cur--;
                    m -= mn;
                    break;
                }
            }
        }
    }

    cout << ans << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}