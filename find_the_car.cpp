#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k, q; cin >> n >> k >> q;

    vector<int> a(k+1);
    for(int i = 1; i <= k; i++) cin >> a[i];

    vector<int> b(k+1);
    for(int i = 1; i <= k; i++) cin >> b[i];

    while(q--) {
        int d; cin >> d;
        int l = lower_bound(all(a), d)-a.begin();
        int r = upper_bound(all(a), d)-a.begin()-1;
        long double dist = a[r]-a[l];
        if(a[r] == a[l]) {
            cout << b[l] << ' ';
            continue;
        }
        long double t = b[r]-b[l];
        long double vel = dist/t;
        cout << (int)floor(b[l]+((d-a[l])*t)/dist) << ' ';
    }

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