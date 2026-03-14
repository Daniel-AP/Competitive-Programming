#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int ask(int a, int b) {

    cout << "? " << a << ' ' << b << endl;
    int x; cin >> x;
    
    return x;

}

void solve() {

    int l = 2, r = 999, mid, ans;

    while(l <= r) {

        mid = l+(r-l)/2;
        int x = ask(mid, mid);

        if(x == mid*mid) {
            l = mid+1;
        } else {
            ans = mid;
            r = mid-1;
        }

    }

    cout << "! " << ans << endl;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}