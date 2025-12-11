#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;

    int cnt1a = count(s1.begin(), s1.end(), 'a');
    int cnt1b = count(s1.begin(), s1.end(), 'b');
    
    int cnt2a = count(s2.begin(), s2.end(), 'a');
    int cnt2b = count(s2.begin(), s2.end(), 'b');

    int mn1 = min(cnt1a, cnt1b);
    int mn2 = min(cnt2a, cnt2b);

    if(mn1 > mn2) cout << "primera";
    else if(mn2 > mn1) cout << "segunda";
    else cout << "empate";

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}