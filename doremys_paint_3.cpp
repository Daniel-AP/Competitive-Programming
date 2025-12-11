#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    set<int> b;
    for(int i = 0; i < n; i++) b.insert(a[i]);

    if(b.size() == 1) return void(cout << "YES" << '\n');

    if(b.size() == 2) {
        int cnt1 = count(a.begin(), a.end(), *b.begin());
        int cnt2 = count(a.begin(), a.end(), *b.rbegin());
        int mx = max(cnt1, cnt2), mn = min(cnt1, cnt2);
        if(mx == (n+1)/2 && mn == n/2) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    } else {
        cout << "NO" << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}