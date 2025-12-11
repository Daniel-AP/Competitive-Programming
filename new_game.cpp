#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    set<int> s;
    map<int, int> freq;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
        freq[a[i]]++;
    }

    vector<int> b(s.begin(), s.end());

    int m = b.size();
    vector<int> prefix(m+1);

    for(int i = 1; i <= m; i++) {
        prefix[i] = prefix[i-1]+freq[b[i-1]];
    }

    int ans = 0;

    for(int i = 0; i < m; i++) {

        int l = i, r = min(i+k-1, m-1), mid, f = -1;

        while(l <= r) {

            mid = l+(r-l)/2;

            if(b[mid] == b[i]+(mid-i)) {
                f = prefix[mid+1]-prefix[i];
                l = mid+1;
            } else {
                r = mid-1;
            }

        }

        ans = max(ans, f);

    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}