#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    if(count(all(s), s[0]) == n) return void(cout << 1 << '\n');

    vector<char> com;
    vector<int> cnt;

    int cur = 1;

    for(int i = 1; i < n; i++) {
        if(s[i] != s[i-1]) {
            com.push_back(s[i-1]);
            cnt.push_back(cur);
            cur = 1;
        } else {
            cur++;
        }
    }

    com.push_back(s.back());
    cnt.push_back(cur);

    int ans = com.size();

    for(int i = 1; i+1 < com.size(); i++) {
        if(cnt[i] == 1 && com[i-1] == com[i+1]) return void(cout << ans-2 << '\n');
    }

    for(int i = 1; i+1 < com.size(); i++) {
        if(cnt[i] == 1) return void(cout << ans-1 << '\n');
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