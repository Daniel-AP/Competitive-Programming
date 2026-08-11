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

    if(n == 1) return void(cout << (a[0] == 0 ? 1 : 0) << '\n');

    set<int> has;
    for(int i = 0; i < n; i++) has.insert(a[i]);

    vector<int> can;
    for(int i = n; i >= 0; i--) if(!has.contains(i)) can.push_back(i);

    vector<int> b(n, -1);

    for(int i = 1; i < n; i++) {
        if(a[i] != a[i-1]) {
            b[i] = a[i-1];
        }
    }

    for(int i = 0; i < n; i++) {
        if(b[i] != -1) continue;
        b[i] = can.back();
        if(can.size() > 1) can.pop_back();
    }

    for(int x: b) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}