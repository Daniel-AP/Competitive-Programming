#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string s; cin >> s;
    int n = s.length();

    int cur = 1;
    vector<int> segs;
    
    for(int i = 1; i < n; i++) {
        if(s[i] != s[i-1]) {
            if(cur > 1) segs.push_back(cur);
            cur = 1;
        } else {
            cur++;
        }
    }

    if(cur > 1) segs.push_back(cur);

    if(segs.size() == 0) return void(cout << "YES" << '\n');
    if(segs.size() > 2) return void(cout << "NO" << '\n');
    if(*max_element(all(segs)) > 3) return void(cout << "NO" << '\n');
    if(*max_element(all(segs)) == 3) {
        if(segs.size() == 1) cout << "YES";
        else cout << "NO";
        cout << '\n';
        return;
    }
    cout << "YES" << '\n';
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}