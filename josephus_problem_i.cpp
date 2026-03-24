#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a;
    for(int i = 1; i <= n; i++) a.push_back(i);

    for(int i = 0; i < a.size(); i++) {
        if(i%2 == 0) {
            a.push_back(a[i]);
        } else {
            cout << a[i] << ' ';
        }
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}