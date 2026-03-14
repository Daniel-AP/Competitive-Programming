#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int ask(int u, int v) {

    cout << "? " << u << ' ' << v << endl;
    int x; cin >> x;

    return x;

}

void solve() {

    int n; cin >> n;

    vector<pair<int, int>> ans;

    for(int i = 2; i <= n; i++) {
        int cur = 1, to = 1;
        while(true) {
            to = cur;
            cur = ask(i, cur);
            if(cur == i) {
                ans.push_back({ i, to });
                break;
            }
        }
    }

    cout << "! ";
    for(const auto& [u, v]: ans) {
        cout << u << ' ' << v << ' ';
    }

    cout << endl;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}