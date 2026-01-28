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
    string s; cin >> s;

    vector<pair<int, int>> segs;

    int i = 0;
    while(i < n) {
        if(s[i] == '1') { i++; continue; }
        int l = i;
        while(i+1 < n && s[i+1] == '0') i++;
        segs.push_back({ l, i });
        i++;
    }

    pair<int, int> p1, p2;
    i = 0;

    while(i < segs.size()) {
        if(segs[i].second > segs[i].first) { i++; continue; }
        int l = i;
        p1 = segs[i];
        int cur = segs[i].first;
        while(i+1 < segs.size() && segs[i+1].first == segs[i+1].second && segs[i+1].first == cur+2) i++, cur += 2;
        p2 = segs[i];
        int prev = 0, next = 0;
        if(l-1 >= 0 && segs[l-1].second == p1.first-2) prev = segs[l-1].second-segs[l-1].first+1;
        if(i+1 < segs.size() && segs[i+1].first == p2.second+2) next = segs[i+1].second-segs[i+1].first+1;
        if(p1.first == 0) prev = INF;
        if(p2.first == n-1) next = INF;
        int m = i-l+1;
        if(m%2 && prev < 2 && next < 2) return void(cout << "NO" << '\n');
        i++;
    }

    cout << "YES" << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}