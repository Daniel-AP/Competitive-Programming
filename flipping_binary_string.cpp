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

    int cnt0 = count(all(s), '0'), cnt1 = n-cnt0;

    if(cnt1%2 && cnt0%2 == 0) return void(cout << -1 << '\n');

    if(cnt1%2 == 0) {
        cout << cnt1 << '\n';
        for(int i = 0; i < n; i++) if(s[i] == '1') cout << i+1 << ' ';
        cout << '\n';
    } else {
        cout << cnt0 << '\n';
        for(int i = 0; i < n; i++) if(s[i] == '0') cout << i+1 << ' ';
        cout << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}