#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int binpow(int a, int b) {

    int ans = 1;

    while(b) {
        if(b&1) ans *= a;
        a *= a;
        b /= 2;
    }

    return ans;

}

void solve() {

    int n, m; cin >> n >> m;
    int ans = 1, k = n, best = 0;

    while(k%10 == 0) k /= 10, best++;
    
    for(int i = 1; i <= 32; i++) {
        for(int j = i; j >= 0; j--) {

            int two = j, five = i-j;
            int cur = binpow(2, two)*binpow(5, five);
            int b = 0;

            if(cur > m) break;

            k = n*cur;
            while(k%10 == 0) k /= 10, b++;

            if(b == best) {
                if(m/ans*ans < m/cur*cur) ans = cur;
            } else if(b > best) {
                best = b;
                ans = cur;
            }

        }
    }

    cout << (best == 0 ? n*m : n*(m/ans*ans)) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}