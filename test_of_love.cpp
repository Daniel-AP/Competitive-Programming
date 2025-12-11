#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m, k; cin >> n >> m >> k;
    string a; cin >> a;

    for(int i = 0; i < n; i++) {
        if(a[i] == 'C') {
            bool all = true;
            for(int j = 1; j < m; j++) {
                if(i-j < 0) { all = false; break; }
                if(a[i-j] == 'L') all = false;
            }
            if(all) return void(cout << "NO" << '\n');
        }
    }

    vector<int> l = {-1};
    for(int i = 0; i < n; i++) if(a[i] == 'L') l.push_back(i);
    l.push_back(n);

    int w = 0;
    for(int i = 0; i+1 < l.size(); i++) w += max(l[i+1]-l[i]-m, 0LL);

    cout << (w <= k ? "YES" : "NO") << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}