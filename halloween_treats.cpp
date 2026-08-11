#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve(int c, int n) {

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> px(n+1);
    for(int i = 1; i <= n; i++) px[i] = (px[i-1]+a[i-1])%c;

    for(int i = 1; i <= n; i++) {

        if(px[i] != 0) continue;

        for(int j = 1; j <= i; j++) cout << j << ' ';
        cout << '\n';
        return;

    }

    map<int, int> seen;

    for(int i = 1; i <= n; i++) {
        if(seen.find(px[i]) != seen.end()) {

            for(int j = seen[px[i]]+1; j <= i; j++) cout << j << ' ';
            cout << '\n';
            return;

        }
        seen[px[i]] = i;
    }

    cout << "no sweets" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(true) {
        int c, n; cin >> c >> n;
        if(c == 0 && n == 0) break;
        solve(c, n);
    }

    return 0;

}