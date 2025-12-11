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

    sort(a.begin(), a.end());

    vector<int> mx(n);
    for(int i = 0; i < n; i++) {
        int j = upper_bound(a.begin(), a.end(), a[i])-a.begin();
        mx[i] = n-j;
    }

    int ans = INF;

    for(int i = 0; i < n; i++) {
        int j = lower_bound(a.begin(), a.end(), a[i]/2+1)-a.begin();
        if(j > 0 &&  a[j-1]+a[j] > a[i]) j--;
        ans = min(ans, mx[i]+j);
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