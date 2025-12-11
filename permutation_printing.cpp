#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n; cin >> n;

    vector<int> p1(n/2), p2((n+1)/2);
    iota(p1.begin(), p1.end(), 1);
    iota(p2.rbegin(), p2.rend(), n/2+1);

    for(int i = 0; i < n/2; i++) {
        cout << p1[i] << " " << p2[i] << " ";
    }

    if(n%2 == 1) cout << p2.back();
    cout << "\n";
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}