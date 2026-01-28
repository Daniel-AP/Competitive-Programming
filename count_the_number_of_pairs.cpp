#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> a(26), b(26);

    for(int i = 0; i < n; i++) {
        if(s[i] >= 65 && s[i] <= 90) b[s[i]-'A']++;
        else a[s[i]-'a']++;
    }

    int ans = 0;

    for(int i = 0; i < 26; i++) {
        ans += min(a[i], b[i]);
        ans += min(k, (max(a[i], b[i])-min(a[i], b[i]))/2);
        k -= min(k, (max(a[i], b[i])-min(a[i], b[i]))/2);
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