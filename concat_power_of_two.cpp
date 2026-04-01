#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

vector<int> a;

int sz(int n) {

    int ans = 1;

    while(n > 0) {
        ans *= 10;
        n /= 10;
    }

    return ans;

}

void add(int px) {

    if(px > 1e9) return;

    a.push_back(px);

    for(int i = 1; i <= (1<<30); i *= 2) {
        add(px*sz(i)+i);
    }

}

void solve() {

    int n; cin >> n;

    add(0);
    sort(all(a));
    unique(all(a));

    cout << a[n] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}