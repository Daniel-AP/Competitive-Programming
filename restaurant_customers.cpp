#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n), ind(n);

    iota(ind.begin(), ind.end(), 0);

    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[i] = x; b[i] = y;
    }

    sort(ind.begin(), ind.end(), [&](int x, int y) {
        return a[x] < a[y];
    });
    sort(a.begin(), a.end());

    int ans = 1, curr = 0, i = 0;
    multiset<int> s;

    while(i < n) {
        int k = s.empty() ? INF : *(s.begin());
        if(a[i] < k) {
            ans = max(ans, ++curr);
            s.insert(b[ind[i]]);
            i++;
        }
        else {
            curr--;
            s.erase(s.begin());
        }
    }

    cout << ans;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}