#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;

    set<int> x;
    for(int i = 0; i < n; i++) {
        int y; cin >> y;
        x.insert(y);
    }

    cout << x.size() << endl;
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;
    
    while(t--) solve();

    return 0;

}