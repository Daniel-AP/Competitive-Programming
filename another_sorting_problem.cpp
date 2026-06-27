#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    bool good = true;

    for(int i = 1; i < n; i++) {
        if(a[i] < a[i-1]) good = false;
    }

    if(good) return void(cout << "YES" << '\n');

    for(int i = 0; i+2 < n; i++) {
        if(a[i] > a[i+1] && a[i+1] > a[i+2]) return void(cout << "NO" << '\n');
    }

    int l = 0;

    for(int i = 1; i < n; i++) {
        if(a[i] < a[i-1]) {
            l = max(l, a[i-1]-a[i]);
        }
    }

    vector<bool> cant(n);

    for(int i = 1; i < n; i++) {
        if(a[i] < a[i-1]) {
            a[i] += l;
            cant[i] = 1;
        }
    }

    for(int i = 1; i < n; i++) {
        if(a[i] < a[i-1] && !cant[i]) {
            a[i] += l;
        }
    }

    for(int i = 1; i < n; i++) {
        if(a[i] < a[i-1]) return void(cout << "NO" << '\n');
    }

    // for(int i = 0; i < n; i++) cout << a[i] << ' ';
    // cout << '\n';

    cout << "YES" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}