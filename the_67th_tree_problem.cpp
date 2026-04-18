#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int x, y; cin >> x >> y;
    int take = min(x, y);

    x -= take, y -= take;

    if((x+y)%2) {
        if(y == 0) return void(cout << "NO" << '\n');
    } else {
        if(x == 0) {
            if(y == 0) {
                cout << "YES" << '\n';
                for(int i = 1; i < 2*take; i++) {
                    cout << i << ' ' << i+1 << '\n';
                }
                return;
            }
        } else return void(cout << "NO" << '\n');
    }

    if(x != 0) return void(cout << "NO" << '\n');
    if(take == 0 && y%2 == 0) return void(cout << "NO" << '\n');

    cout << "YES" << '\n';

    if(take == 0) {
        for(int i = 2; i <= y; i++) {
            cout << 1 << ' ' << i << '\n';
        }
        return;
    }

    for(int i = 1; i < 2*take; i++) {
        cout << i << ' ' << i+1 << '\n';
    }

    for(int i = 1; i <= y; i++) {
        cout << 2*take << ' ' << 2*take+i << '\n';
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