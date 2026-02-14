#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s, t; cin >> s >> t;

    int cnt0 = 0, cnt1 = 0;

    for(int i = 0; i < n; i++) {
        cnt0 += (t[i]!=s[i]);
    }

    reverse(all(s));

    for(int i = 0; i < n; i++) {
        cnt1 += (t[i]!=s[i]);
    }

    int ans1, ans2;

    if(cnt0%2) ans1 = 2*cnt0-1;
    else ans1 = 2*cnt0;

    if(cnt1%2) ans2 = 2*cnt1;
    else if(cnt1 > 0) ans2 = 2*cnt1-1;
    else ans2 = 2;

    cout << min(ans1, ans2) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}