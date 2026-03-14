#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int s, m; cin >> s >> m;
    vector<int> has;

    for(int i = 0; i < 63; i++) {
        if((1ULL<<i)&m) has.push_back((1ULL<<i));
    }

    int n = has.size();
    reverse(all(has));

    if(s%has.back() != 0) return void(cout << -1 << '\n');

    int cnt = s/has.back();
    int l = 1, r = cnt, mid, ans = cnt;

    while(l <= r) {
        mid = l+(r-l)/2;
        for(int i = 0; i < n && cnt > 0; i++) {
            int factor = has[i]/has[n-1];
            if(cnt/factor < mid) cnt %= factor;
            else cnt -= factor*mid;
        }
        if(cnt == 0) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
        cnt = s/has.back();
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