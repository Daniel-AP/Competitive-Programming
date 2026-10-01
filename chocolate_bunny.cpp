#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int ask(int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    int k; cin >> k;
    return k;
}

void solve() {

    int n; cin >> n;
    int pos = 1;

    vector<int> ans(n+1);

    for(int i = 2; i <= n; i++) {

        int a = ask(pos, i);
        int b = ask(i, pos);

        if(a > b) ans[pos] = max(a, b), pos = i;
        else ans[i] = max(a, b);

    }

    ans[pos] = n;

    cout << "! ";
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}