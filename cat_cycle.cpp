#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    if(n%2 == 0) {
        cout << (k%n == 0 ? n : k%n) << '\n';
    } else {

        int a = (k%n == 0 ? n : k%n);
        int cnt = 0;
        
        if(k >= (n+1)/2) {
            cnt = 1;
            k -= (n+1)/2;
            cnt += k/(n/2);
        }

        cout << ((a+cnt)%n == 0 ? n : (a+cnt)%n) << '\n';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}