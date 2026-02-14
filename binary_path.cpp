#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s1, s2, s; cin >> s1 >> s2;

    int i = 0, j, ans = 1;

    for(; i < n; i++) {
        s += s1[i];
        if(i+1 >= n || s2[i] < s1[i+1]) {
            j = i;
            break;
        }
    }

    for(; i < n; i++) s += s2[i];
    for(int i = j; i >= 0 && s2[i-1] == s1[i]; i--) ans++;

    cout << s << '\n';
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