#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;
    map<string, int> mp;

    while(n--) {

        string s; cin >> s;
        sort(s.begin(), s.end());
        mp[s]++;

    }

    int ans = 0;

    for(auto [key, val]: mp) {
        ans = max(val, ans);
    }

    cout << ans << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}