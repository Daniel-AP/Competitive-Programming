#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int a, b, c; cin >> a >> b >> c;
    int s = a+b+c;

    if(s%3 != 0 && s%4 != 0 && s%5 != 0) return void(cout << "NO" << '\n');

    bool ok = false;

    if(s%3 == 0) {
        ok |= (a==s/3 && b==s/3 && c==s/3);
    }
    if(s%4 == 0 && a%(s/4) == 0 && b%(s/4) == 0 && c%(s/4) == 0) {
        int cnt = 0;
        cnt += a/(s/4);
        cnt += b/(s/4);
        cnt += c/(s/4);
        ok |= (cnt<=4);
    }
    if(s%5 == 0 && a%(s/5) == 0 && b%(s/5) == 0 && c%(s/5) == 0) {
        int cnt = 0;
        cnt += a/(s/5);
        cnt += b/(s/5);
        cnt += c/(s/5);
        ok |= (cnt<=5);
    }
    if(s%6 == 0 && a%(s/6) == 0 && b%(s/6) == 0 && c%(s/6) == 0) {
        int cnt = 0;
        cnt += a/(s/6);
        cnt += b/(s/6);
        cnt += c/(s/6);
        ok |= (cnt<=6);
    }

    cout << (ok ? "YES" : "NO") << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}