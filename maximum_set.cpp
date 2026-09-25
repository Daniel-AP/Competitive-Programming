#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
#define MOD 998244353

void solve() {

    int l, r; cin >> l >> r;
    int sz = 1, cur = l;

    while(cur*2 <= r) sz++, cur *= 2;

    int lb = l, rb = r, mxbase2s = 0;

    while(lb <= rb) {
        int mid = lb+(rb-lb)/2;
        int cursz = 1;
        cur = mid;
        while(cur*2 <= r) cursz++, cur *= 2;
        if(cursz < sz) rb = mid-1;
        else {
            lb = mid+1;
            mxbase2s = mid;
        }
    }

    lb = l, rb = r;
    int mxbase3 = 0;

    while(lb <= rb) {
        int mid = lb+(rb-lb)/2;
        if(mid*3 > r) {
            rb = mid-1;
            continue;
        }
        int cursz = 2;
        cur = mid*3;
        while(cur*2 <= r) cursz++, cur *= 2;
        if(cursz < sz) rb = mid-1;
        else {
            lb = mid+1;
            mxbase3 = mid;
        }
    }

    cout << sz << ' ' << max(mxbase2s-l+1, 0LL)+(sz-1)*max(mxbase3-l+1, 0LL) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}