#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    vector<int> ind(n);
    iota(all(ind), 0);
    sort(all(ind), [&](int i, int j) { return x[i] < x[j]; });

    sort(all(x));

    vector<int> px(n+1);
    partial_sum(all(x), px.begin()+1);

    vector<int> ans(n);

    for(int i = 0; i < n; i++) {
        int j = ind[i];
        ans[j] = (x[i]*i-px[i]+i)+(px[n]-px[i+1]-x[i]*(n-i-1)+(n-i-1))+1;
    }

    for(int x: ans) cout << x << ' ';
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