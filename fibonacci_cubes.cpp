#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

int fib[] = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

void solve() {

    int n, m; cin >> n >> m;

    while(m--) {

        int w, l, h; cin >> w >> l >> h;

        if(fib[n-1] > w || fib[n-1] > l || fib[n-1] > h) {
            cout << 0;
            continue;
        }

        if(fib[n-1]+fib[n-2] > w && fib[n-1]+fib[n-2] > l) {
            if(fib[n-1]+fib[n-2] > h) {
                cout << 0;
                continue;
            }
        }

        cout << 1;

    }

    cout << "\n";
        
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}