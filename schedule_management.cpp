#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<int> a(m), cnt(n+1);
    
    for(int i = 0; i < m; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cnt[a[i]]++;

    if(n == 1) return void(cout << m << '\n');

    multiset<int> ms;
    for(int i = 1; i <= n; i++) ms.insert(cnt[i]);

    while(true) {
        int mn = *ms.begin();
        int mx = *ms.rbegin();
        if(mx-mn <= 1) break;
        ms.erase(ms.begin());
        ms.erase(prev(ms.end()));
        ms.insert(mn+2);
        ms.insert(mx-1);
    }

    cout << *ms.rbegin() << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}