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

    sort(all(a));

    int s = 0;
    for(int i = 0; i < n; i++) s += a[i];

    int t1 = (s+1)/2;

    vector<int> px(n+1);
    partial_sum(all(a), px.begin()+1);

    int j = upper_bound(all(px), t1)-px.begin();

    int t2 = n-j+1;

    cout << t1+t2 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}