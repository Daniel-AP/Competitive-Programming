#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int m = 0;

    for(int i = 0; i < n; i++) {
        m = max(m, (int)a[i].length());
    }

    for(int i = 0; i < n; i++) {
        string s(m, '.');
        int k = (m-a[i].length())/2;
        for(int j = 0; j < a[i].length(); j++) s[j+k] = a[i][j]; 
        cout << s << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}