#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, q; cin >> n >> q;
    string a; cin >> a;
    string b; cin >> b;

    vector<vector<int>> prefix_a(n+1, vector<int>(26)), prefix_b(n+1, vector<int>(26));

    for(int i = 1; i <= n; i++) {
        prefix_a[i] = prefix_a[i-1];
        prefix_a[i][a[i-1]-'a']++;
        prefix_b[i] = prefix_b[i-1];
        prefix_b[i][b[i-1]-'a']++;
    }

    while(q--) {

        int l, r; cin >> l >> r;

        vector<int> cnt_a(26), cnt_b(26);
        int diff = 0;

        for(int i = 0; i < 26; i++) cnt_a[i] += prefix_a[r][i];
        for(int i = 0; i < 26; i++) cnt_a[i] -= prefix_a[l-1][i];

        for(int i = 0; i < 26; i++) cnt_b[i] += prefix_b[r][i];
        for(int i = 0; i < 26; i++) cnt_b[i] -= prefix_b[l-1][i];

        for(int i = 0; i < 26; i++) diff += abs(cnt_a[i]-cnt_b[i]);

        cout << (diff+1)/2 << '\n';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}