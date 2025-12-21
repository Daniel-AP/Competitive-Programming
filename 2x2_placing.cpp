#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int di[] = { 0, 1, 0, 1 };
int dj[] = { 0, 0, 1, 1 };

void solve() {

    int n, m; cin >> n >> m;

    set<pair<int, int>> has;

    for(int i = 0; i < m; i++) {
        int r, c; cin >> r >> c;
        bool can = true;
        for(int j = 0; j < 4; j++) {
            if(has.find({ r+di[j], c+dj[j] }) != has.end()) {
                can = false;
                break;
            }
        }
        if(!can) continue;
        for(int j = 0; j < 4; j++) {
            has.insert({ r+di[j], c+dj[j] });
        }
    }

    cout << has.size()/4 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}