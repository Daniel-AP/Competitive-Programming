#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];

    int ans = 0;

    vector<int> prefix(n+1);
    partial_sum(a.begin(), a.end(), prefix.begin()+1);

    for(int i = 0; i < m; i++) {

        int l = i+1, r = n-(m-i-1);
        int j = lower_bound(a.begin(), a.end(), b[i])-a.begin()+1;

        int s1 = prefix[min(j-1, r)]-prefix[l-1];
        int s2 = prefix[r]-prefix[max(j, l)-1];
        
        if(l <= min(j-1, r)) ans += b[i]*(min(j-1, r)-l+1)-s1;
        if(max(j, l) <= r) ans += s2-b[i]*(r-max(j, l)+1);

    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}