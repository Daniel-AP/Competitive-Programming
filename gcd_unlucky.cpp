#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n; cin >> n;

    vector<int> p(n), s(n), a(n);

    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> s[i];

    for(int i = 1; i < n; i++) {
        if(p[i-1]%p[i] != 0) {
            cout << "NO" << '\n';
            return;
        }
    }

    for(int i = 0; i < n-1; i++) {
        if(s[i+1]%s[i] != 0) {
            cout << "NO" << '\n';
            return;
        }
    }

    for(int i = 0; i < n; i++) {
        a[i] = lcm(p[i], s[i]);
    }

    vector<int> gcd_p(n), gcd_s(n);

    gcd_p[0] = a[0];
    for(int i = 1; i < n; i++) gcd_p[i] = gcd(gcd_p[i-1], a[i]);

    gcd_s[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--) gcd_s[i] = gcd(a[i], gcd_s[i+1]);

    bool ans1 = true, ans2 = true;

    for(int i = 0; i < n; i++) {
        if(gcd_p[i] != p[i]) ans1 = false;
    }
    for(int i = 0; i < n; i++) {
        if(gcd_s[i] != s[i]) ans2 = false;
    }

    cout << (ans1 && ans2 ? "YES" : "NO") << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}