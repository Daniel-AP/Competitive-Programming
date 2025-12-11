#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    vector<int> a(n), b;
    for(int i = 0; i < n; i++) cin >> a[i];

    if(n == 1) return void(cout << "YES" << '\n');

    for(int i = 0; i < n; i++) {
        if(b.empty() || b.back() != a[i]) b.push_back(a[i]);
    }

    int m = b.size(), cnt = 0;

    if(m == 1) return void(cout << "YES" << '\n');

    for(int i = 1; i < m-1; i++) {
        if(b[i] < b[i-1] && b[i] < b[i+1]) cnt++;
    }

    cnt += (b[0]<b[1]);
    cnt += (b[m-1]<b[m-2]);

    if(cnt == 1) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}