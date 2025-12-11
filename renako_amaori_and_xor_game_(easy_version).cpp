#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    
    int lastA = -1, lastB = -1;
    for(int i = 0; i < n; i++) {
        if(i%2 == 0 && (a[i]^b[i])) lastA = i;
        if(i%2 == 1 && (a[i]^b[i])) lastB = i;
    }

    int cntA = count(a.begin(), a.end(), 1);
    int cntB = count(b.begin(), b.end(), 1);

    if(cntA%2 == cntB%2) cout << "Tie" << '\n';
    else if(lastA > lastB) cout << "Ajisai" << '\n';
    else cout << "Mai" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}