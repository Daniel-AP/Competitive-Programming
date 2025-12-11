#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n), good(n+1);
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++) {
        good[a[i]] = 1;
    }

    int mex = 0;

    for(; mex <= n; mex++) {
        if(good[mex] == 0) break;
    }

    int diff = k%(n+1);

    if(diff == 0) {

        for(int i = 0; i < n; i++) cout << a[i] << " ";

    } else {

        vector<int> p;
        for(int i = n-diff+1; i < n; i++) p.push_back(a[i]);
        rotate(a.begin(), a.end()-diff, a.end());

        a[diff-1] = mex;

        for(int i = 0; i < diff-1; i++) {
            a[i] = p[i];
        }

        for(int i = 0; i < n; i++) cout << a[i] << " ";

    }

    cout << "\n";
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}