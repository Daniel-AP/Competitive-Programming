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

    int sa = 0;
    for(int x: a) sa += x;

    vector<int> b1(n), b2(n), has(n+1);
    int mx = 0;

    for(int i = 0; i < n; i++) {
        if(has[a[i]]) mx = max(mx, a[i]);
        has[a[i]] = 1;
        b1[i] = mx;
    }

    int sb1 = 0;
    for(int x: b1) sb1 += x;

    fill(all(has), 0);
    mx = 0;

    for(int i = 0; i < n; i++) {
        if(has[b1[i]]) mx = max(mx, b1[i]);
        has[b1[i]] = 1;
        b2[i] = mx;
    }

    int ans = sa+sb1;
    int cur = 0;
    
    vector<int> cnt(n+1);
    for(int x: b2) cnt[x]++;

    for(int i = n; i >= 1; i--) {
        ans += i*(cnt[i]*cur+cnt[i]*(cnt[i]+1)/2);
        cur += cnt[i];
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