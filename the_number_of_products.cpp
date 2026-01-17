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

    int pos = 1, neg = 0, cur = 1, ans1 = 0, ans2 = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] < 0) cur = -cur;
        if(cur == -1) {
            ans1 += neg;
            ans2 += pos;
            neg++;
        } else {
            ans1 += pos;
            ans2 += neg;
            pos++;
        }
    }

    cout << ans2 << ' ' << ans1 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}