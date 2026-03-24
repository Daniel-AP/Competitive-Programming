#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, c, k; cin >> n >> c >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(all(a));

    for(int i = 0; i < n; i++) {
        if(c >= a[i]) {
            int take = min(k, c-a[i]);
            k -= take;
            c += a[i]+take;
            continue;
        }
        return void(cout << c << '\n');
    }

    cout << c << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}