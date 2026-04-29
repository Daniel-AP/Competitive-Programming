#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, x; cin >> n >> x;
    int ans1 = 0, ans2 = 0, ans3 = 0;

    for(int i = 1; i*i <= n-x; i++) {
        if((n-x)%i != 0) continue;
        if(i%2 == 0 && i/2+1 >= x) {
            ans1++;
        }
        if((n-x)/i != i && (n-x)/i%2 == 0 && ((n-x)/i)/2+1 >= x) {
            ans1++;
        }
    }

    for(int i = 1; i*i <= n+x-2; i++) {
        if((n+x-2)%i != 0) continue;
        if(i%2 == 0 && i/2+1 >= x) {
            ans2++;
        }
        if((n+x-2)/i != i && (n+x-2)/i%2 == 0 && ((n+x-2)/i)/2+1 >= x) {
            ans2++;
        }
    }

    for(int i = 1; i*i <= gcd(n+x-2, n-x); i++) {
        if(gcd(n+x-2, n-x)%i != 0) continue;
        if(i%2 == 0 && i/2+1 >= x) {
            ans3++;
        }
        if(gcd(n+x-2, n-x)/i != i && gcd(n+x-2, n-x)/i%2 == 0 && (gcd(n+x-2, n-x)/i)/2+1 >= x) {
            ans3++;
        }
    }

    cout << ans1+ans2-ans3 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}