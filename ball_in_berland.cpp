#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int a, b, k; cin >> a >> b >> k;

    vector<int> ak(k), bk(k);

    for(int i = 0; i < k; i++) cin >> ak[i];
    for(int i = 0; i < k; i++) cin >> bk[i];

    vector<pair<int, int>> ab(k);
    for(int i = 0; i < k; i++) ab[i] = {ak[i], bk[i]};

    map<int, int> mp;
    for(int i = 0; i < k; i++) mp[bk[i]]++;

    sort(all(ab));

    int ans = 0;

    for(int i = 0; i < k; i++) {

        int st = lower_bound(all(ab), make_pair(ab[i].first, 0LL))-ab.begin();
        int end = lower_bound(all(ab), make_pair(ab[i].first, INF))-ab.begin()-1;

        ans += k-(end-st+1)-mp[ab[i].second]+1;

    }

    cout << ans/2 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}