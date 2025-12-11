#include <bits/stdc++.h>
using namespace std;

#define int long long

int s(int n) {

    return ((n-1)*n)/2;

}

void solve() {

    int n; cin >> n;
    int ans = 0;

    vector<string> cake(n);
    for(int i = 0; i < n; i++) cin >> cake[i];

    for(int i = 0; i < n; i++) {
        int m = count(cake[i].begin(), cake[i].end(), 'C');
        ans += s(m);
    }

    for(int i = 0; i < n; i++) {
        int m = 0;
        for(int j = 0; j < n; j++) {
            m += (cake[j][i] == 'C');
        }
        ans += s(m);
    }

    cout << ans << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}