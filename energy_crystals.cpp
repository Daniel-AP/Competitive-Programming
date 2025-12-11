#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define INF (1LL<<60)
#define LOG2(X) ((unsigned) (8*sizeof (unsigned long long) - __builtin_clzll((X)) - 1))

void solve() {

    int x; cin >> x;

    cout << 2*(LOG2(x)+1)+1 << "\n";

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}