#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int cnt0 = 0;
    map<array<int, 3>, int> cnt;

    for(int i = 0; i < n; i++) {

        if(b[i] == 0 && a[i] == 0) {
            cnt0++;
            continue;
        }

        if(a[i] == 0) continue;
        
        int g = gcd(abs(b[i]), abs(a[i]));
        b[i] /= g; a[i] /= g;
        int s = ((b[i]<0)+(a[i]<0)+1)%2;

        cnt[{abs(b[i]), abs(a[i]), s}]++;

    }

    int ans = cnt[{0, 1, 1}]+cnt[{0, 1, 0}];

    for(auto& [k, v]: cnt) {
        ans = max(ans, v);
    }   

    cout << ans+cnt0 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}