#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    vector<int> px(n+1), cnt(n+1);

    for(int i = 1; i <= n; i++) px[i] = px[i-1]+(s[i-1] == '*' ? i : 0);
    for(int i = 1; i <= n; i++) cnt[i] = cnt[i-1]+(s[i-1]=='*');

    int ans = INF;

    for(int i = 1; i <= n; i++) {

        if(s[i-1] == '.') continue;

        int cntl = cnt[i-1], cntr = cnt[n]-cnt[i-1];
        int cur = 0;

        cur += cntl*(2*i-cntl-1)/2-px[i-1];
        cur += (px[n]-px[i-1])-cntr*(2*i+cntr-1)/2;

        ans = min(ans, cur);

    }

    cout << (ans == INF ? 0 : ans) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}