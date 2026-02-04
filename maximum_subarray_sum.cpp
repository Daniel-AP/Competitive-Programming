#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) if(s[i] == '0') a[i] = -1e18;
    
    int mx = a[0], cur = a[0];

    for(int i = 1; i < n; i++) {
        cur = max(a[i], cur+a[i]);
        mx = max(mx, cur);
    }

    if(count(all(s), '1') == n) {
        if(mx == k) {
            cout << "Yes" << '\n';
            for(int x: a) cout << x << ' ';
            cout << '\n';
        } else cout << "No" << '\n';
        return;
    }

    if(mx > k) return void(cout << "No" << '\n');

    vector<int> l(n), r(n);
    l[0] = a[0], r[n-1] = a[n-1];

    for(int i = 1; i < n; i++) l[i] = max(l[i-1]+a[i], a[i]);
    for(int i = n-2; i >= 0; i--) r[i] = max(r[i+1]+a[i], a[i]);

    int i = s.find('0');

    if(i-1 >= 0 && i+1 < n) a[i] = k-max(l[i-1], 0LL)-max(r[i+1], 0LL);
    else if(i-1 >= 0) a[i] = k-max(l[i-1], 0LL);
    else if(i+1 < n) a[i] = k-max(r[i+1], 0LL);
    else a[i] = k;

    cout << "Yes" << '\n';
    for(int x: a) cout << x << ' ';
    cout << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}