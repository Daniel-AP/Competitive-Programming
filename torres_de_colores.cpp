#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9+7;

int binPow(int base, int exp) {

    int ans = 1;

    while(exp > 0) {

        if(exp%2 == 1) ans = (ans*base)%MOD;

        base = (base%MOD*base%MOD)%MOD;
        exp /= 2;

    }

    return ans;

}

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n);
    vector<vector<int>> memo(n, vector<int>(n, 1));
    set<int> s;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
        b[i] = s.size();
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j+i < n; j++) {
            if(b[j+i]-b[j]+1 == 1) memo[j][j+i] = 1;
            else if(b[j+i]-b[j]+1 == i+1) memo[j][j+i] = binPow(2, i);
            else memo[j][j+i] = (memo[j][j+i-1]+memo[j+1][j+i])%MOD;
        }
    }

    cout << memo[0][n-1] << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}