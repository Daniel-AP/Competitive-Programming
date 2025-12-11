#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];

    sort(b.rbegin(), b.rend());

    int val = 0;

    for(int i = 0; i < n; i++) {
        val += (b[i]>0)-(b[i]<0);
        cout << val << ' ';
    }

    cout << '\n';

    int cnt = 0;
    for(int i = 0; i < n; i++) cnt += (b[i]<0);

    for(int i = 0; i < cnt; i++) cout << 1 << ' ' << 0 << ' ';
    for(int i = 0; i < n-cnt*2; i++) cout << i+1 << ' ';
    
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}