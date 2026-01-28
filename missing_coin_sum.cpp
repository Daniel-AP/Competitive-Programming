#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int n; cin >> n;

    vector<int> a(n), prefix(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    if(a[0] != 1) {
        cout << 1 << '\n';
        return;
    }

    partial_sum(a.begin(), a.end(), prefix.begin());

    for(int i = 1; i < n; i++) {
        if(a[i] > prefix[i-1]+1) {
            cout << prefix[i-1]+1 << '\n';
            return;
        }
    }

    cout << prefix[n-1]+1 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}