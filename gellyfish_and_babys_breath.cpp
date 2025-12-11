#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define MOD 998244353

int binpow(int a, int b) {

    a %= MOD;

    int res = 1;

    while(b > 0) {
        if(b%2 == 1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }

    return res;

}

void solve() {

    int n; cin >> n;

    vector<int> p(n), q(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> q[i];

    vector<int> mx_p(n), mx_q(n);

    for(int i = 1; i < n; i++) {
        if(p[i] > p[mx_p[i-1]]) mx_p[i] = i;
        else mx_p[i] = mx_p[i-1];
    }

    for(int i = 1; i < n; i++) {
        if(q[i] > q[mx_q[i-1]]) mx_q[i] = i;
        else mx_q[i] = mx_q[i-1];
    }

    for(int i = 0; i < n; i++) {

        int a = (binpow(2, p[mx_p[i]])+binpow(2, q[i-mx_p[i]]))%MOD;
        int b = (binpow(2, q[mx_q[i]])+binpow(2, p[i-mx_q[i]]))%MOD;

        if(p[mx_p[i]] == q[mx_q[i]]) {
            if(q[i-mx_p[i]] > p[i-mx_q[i]]) {
                cout << a << " ";
            } else {
                cout << b << " ";
            }
        } else if(p[mx_p[i]] > q[mx_q[i]]) {
            cout << a << " ";
        } else {
            cout << b << " ";
        }

    }

    cout << "\n";

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}