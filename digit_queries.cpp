#include <bits/stdc++.h>
using namespace std;

#define int long long

int lg(int n) {

    int f = 10;
    int ans = 1;

    while(f < n) {
        ans++;
        f *= 10;
    }

    return ans;

}

int d(int n) {
    
    return to_string(n).length();

}

int before(int n) {

    int lg = lg(n);
    int f = 10, ans = 0;

    for(int i = 1; i <= lg; i++) {
        ans += min(n-f/10, f-f/10)*i;
        f *= 10;
    }

    return ans+d(n);

}

void solve() {

    int q; cin >> q;

    while(q--) {

        int k; cin >> k;
        int l(1), r(1e18), mid, n, digits;

        while(l <= r) {

            mid = l+(r-l)/2;
            int b = before(mid);

            if(b >= k) {
                n = mid;
                digits = b;
                r = mid-1;
            } else {
                l = mid+1;
            }

        }

        int p = pow(10, digits-k);

        cout << (n/p)%10 << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}