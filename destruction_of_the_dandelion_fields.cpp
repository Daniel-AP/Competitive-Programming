#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    int s = 0;

    vector<int> odd;

    for(int i = 0; i < n; i++) {

        int x; cin >> x;

        if(x&1) odd.push_back(x);
        else s += x;

    }

    sort(odd.begin(), odd.end());

    int m = odd.size();

    if(m == 0) return void(cout << 0 << '\n');

    for(int i = 0; i < (m+1)/2; i++) s += odd.back(), odd.pop_back();

    cout << s << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}