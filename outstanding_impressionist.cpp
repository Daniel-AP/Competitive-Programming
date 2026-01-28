#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int n; cin >> n;

    set<int> d;
    vector<pair<int, int>> w(n);
    map<pair<int, int>, int> freq;

    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if(a == b) d.insert(a);
        w[i] = { a, b };
        freq[w[i]]++;
    }

    vector<int> cant(d.begin(), d.end());

    for(int i = 0; i < n; i++) {

        int idx1 = lower_bound(cant.begin(), cant.end(), w[i].first)-cant.begin();
        int idx2 = lower_bound(cant.begin(), cant.end(), w[i].second)-cant.begin();

        if(idx1 == cant.size() || idx2 == cant.size()) {
            cout << 1;
        } else if(cant[idx1] != w[i].first || cant[idx2] != w[i].second) {
            cout << 1;
        } else if(idx1 == idx2 && freq[w[i]] == 1) {
            cout << 1;
        } else if(idx2-idx1 == w[i].second-w[i].first) {
            cout << 0;
        } else {
            cout << 1;
        }

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