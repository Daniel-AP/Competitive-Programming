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

    vector<int> px(n+1);
    partial_sum(all(b), px.begin()+1);

    vector<int> diff(n+1), extra(n);

    for(int i = 1; i <= n; i++) {

        int x = px[i-1]+a[i-1];
        int j = upper_bound(px.begin()+i, px.end(), x)-px.begin();

        diff[i-1]++;
        diff[j-1]--;

        if(j < n+1) extra[j-1] += x-px[j-1];

    }

    int cur = 0;

    for(int i = 0; i < n; i++) {
        cur += diff[i];
        cout << cur*b[i]+extra[i] << ' ';
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