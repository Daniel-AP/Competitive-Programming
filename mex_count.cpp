#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> cnt(n+1);
    for(int i = 0; i < n; i++) cnt[a[i]]++;

    int mex = n+1;
    for(int i = 0; i <= n; i++) {
        if(cnt[i] == 0) {
            mex = i;
            break;
        }
    }

    vector<int> px(n+1), sx(n+1);
    px[0] = 0;
    sx[n] = 0;

    for(int i = 1; i <= n; i++) px[i] = cnt[i-1]+px[i-1]-1;
    for(int i = n-1; i >= 0; i--) sx[i] = cnt[i+1]+sx[i+1];

    vector<int> diff(n+1);

    for(int i = 0; i <= mex; i++) {
        diff[cnt[i]]++;
        if(px[i]+cnt[i]+sx[i]+1 <= n) diff[px[i]+cnt[i]+sx[i]+1]--;
    }

    int cur = 0;
    for(int i = 0; i <= n; i++) {
        cur += diff[i];
        cout << cur << ' ';
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