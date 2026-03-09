#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
#define MOD 998244353

int binpow(int a, int b) {

    a %= MOD;

    int ans = 1;

    while(b) {
        if(b%2) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }

    return ans;

}

int inv(int a) {
    a %= MOD;
    return binpow(a, MOD-2);
}

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int prev = 0;
    vector<int> cnt2(n), cnt3(n);
    
    for(int i = 0; i < n; i++) {
        cnt2[i] = prev+(a[i]==2);
        prev = cnt2[i];
    }

    prev = 0;

    for(int i = n-1; i >= 0; i--) {
        cnt3[i] = prev+(a[i]==3);
        prev = cnt3[i];
    }

    vector<pair<int, int>> vp;

    for(int i = 0; i < n; i++) {
        if(a[i] == 3) {
            vp.push_back({ i, cnt2[i] });
        }
    }

    int m = vp.size();

    vector<int> px(m+1);
    for(int i = 1; i <= m; i++) px[i] = (px[i-1]+binpow(2, vp[i-1].second))%MOD;

    int ans = 0, error = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            int j = lower_bound(all(vp), make_pair(i, 0LL))-vp.begin()+1;
            if(j > m) continue;
            int cur = (px[m]-px[j-1]+MOD)%MOD;
            cur *= inv(binpow(2, cnt2[i]));
            cur %= MOD;
            ans += cur;
            ans %= MOD;
            error += cnt3[i];
            error %= MOD;
        }
    }

    cout << (ans-error+MOD)%MOD << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}