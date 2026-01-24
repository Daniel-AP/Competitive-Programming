#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> cnt(26);

    for(int i = 0; i < n; i++) {
        cnt[s[i]-'a']++;
    }

    int odd = 0;

    for(int i = 0; i < 26; i++) odd += cnt[i]%2;

    if(k > odd) {
        cout << "YES" << '\n';
    } else if(odd-k <= 1) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
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