#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    string s; cin >> s;

    vector<pair<int, int>> a(26, { -1, -1 });

    for(int i = 0; i < 52; i++) {
        if(a[s[i]-'A'].first == -1) {
            a[s[i]-'A'].first = i;
        } else {
            a[s[i]-'A'].second = i;
        }
    }

    int ans = 0;

    for(int i = 0; i < 26; i++) {
        for(int j = i+1; j < 26; j++) {
            if(a[i].first > a[j].first && a[j].second < a[i].second && a[j].second > a[i].first) ans++;
            if(a[j].first > a[i].first && a[i].second < a[j].second && a[i].second > a[j].first) ans++;
        }
    }

    cout << ans;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    int t; t = 1;

    while(t--) solve();

    return 0;

}