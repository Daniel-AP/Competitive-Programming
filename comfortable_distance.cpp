#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, l, r; cin >> n >> l >> r;
    string s; cin >> s;

    array<vector<int>, 26> a{};

    int ans = 0;

    for(int i = 0; i < n; i++) {
        a[s[i]-'a'].push_back(i);
        int jl = lower_bound(all(a[s[i]-'a']), i-r)-a[s[i]-'a'].begin();
        int jr = upper_bound(all(a[s[i]-'a']), i-l)-a[s[i]-'a'].begin();
        ans += jr-jl;
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