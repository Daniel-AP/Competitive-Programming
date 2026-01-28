#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int s1 = 0, s2 = 0;

    for(int i = 0; i < n; i += 2) {
        s1 += a[i];
        if(i+1 < n) s2 += a[i+1];
    }

    int d = (s1+s2)/n;

    if((s1+s2)%n != 0) cout << "NO" << '\n';
    else if(s1 == (n+1)/2*d && s2 == n/2*d) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}