#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n; cin >> n;

    vector<int> ans(26);

    for(int i = 0; i < n; i++) {

        string s1, s2; cin >> s1 >> s2;
        vector<int> freq1(26), freq2(26);

        for(char chr: s1) freq1[chr-'a']++;
        for(char chr: s2) freq2[chr-'a']++;

        for(int j = 0; j < 26; j++) {
            ans[j] += max(freq1[j], freq2[j]);
        }

    }

    for(int i: ans) cout << i << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int t; t = 1;

    while(t--) solve();

    return 0;

}