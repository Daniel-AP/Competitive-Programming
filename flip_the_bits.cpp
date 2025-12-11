#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;

    vector<bool> same(n);
    int z = (s1[0] == '0'), o = (s1[0] == '1');

    for(int i = 1; i < n; i++) {

        if(s1[i-1] == s2[i-1] && s1[i] != s2[i]) {
            if(!same[i-1]) return void(cout << "NO" << '\n');
        }

        if(s1[i-1] != s2[i-1] && s1[i] == s2[i]) {
            if(!same[i-1]) return void(cout << "NO" << '\n');
        }

        z += (s1[i] == '0');
        o += (s1[i] == '1');

        same[i] = (z==o);

    }

    if(s1[n-1] != s2[n-1] && !same[n-1]) {
        return void(cout << "NO" << '\n');
    }

    cout << "YES" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}