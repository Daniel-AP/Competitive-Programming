#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
#define MOD 998244353

const int N = 1e7;
vector<int> spf(N+1);

void sieve() {

    for(int i = 2; i <= N; i++) spf[i] = i;

    for(int i = 2; i*i <= N; i++) {
        if(spf[i] == i) {
            for(int j = i*i; j <= N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }

}

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

    map<int, pair<int, int>> cnt;

    for(int i = 0; i < n; i++) {
        int x = a[i];
        while(spf[x]) {

            int pf = spf[x], cur = 0;
            while(x%pf == 0) cur++, x /= pf;

            if(cnt[pf].first < cur) cnt[pf].second = cnt[pf].first, cnt[pf].first = cur;
            else if(cnt[pf].second < cur) cnt[pf].second = cur;

        }
    }

    int ans = 1;

    for(auto& [k, v]: cnt) {
        ans *= binpow(k, v.first);
        ans %= MOD;
    }

    for(int i = 0; i < n; i++) {
        int x = a[i], tans = ans;
        while(spf[x]) {

            int pf = spf[x], cur = 0;
            while(x%pf == 0) cur++, x /= pf;

            if(cnt[pf].first == cur) {
                tans *= inv(binpow(pf, cnt[pf].first-cnt[pf].second));
                tans %= MOD;
            }

        }
        cout << tans << ' ';
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve();

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}