#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> idx(n+1);
    for(int i = 0; i < n; i++) idx[a[i]] = i;

    for(int i = 0; i < n; i++) {
        if(a[i] < (n-i)) {
            reverse(a.begin()+i, a.begin()+idx[n-i]+1);
            break;
        }        
    }

    for(int x: a) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}