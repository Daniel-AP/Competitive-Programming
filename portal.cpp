#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, x, y; cin >> n >> x >> y;

    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    int mn = *min_element(p.begin()+x, p.begin()+y);

    for(int i = x; i < y; i++) {
        if(p[i] == mn) {
            rotate(p.begin()+x, p.begin()+i, p.begin()+y);
            break;
        }
    }

    bool pass = false;

    vector<int> l, r;

    for(int i = 0; i < x; i++) {
        if(p[i] > p[x]) pass = true;
        if(!pass) l.push_back(p[i]);
        else r.push_back(p[i]);
    }

    for(int i = y; i < n; i++) {
        if(p[i] > p[x]) pass = true;
        if(!pass) l.push_back(p[i]);
        else r.push_back(p[i]);
    }

    for(int x: l) cout << x << ' ';
    for(int i = x; i < y; i++) cout << p[i] << ' ';
    for(int x: r) cout << x << ' ';

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