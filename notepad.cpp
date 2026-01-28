#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    vector<int> has(26*26, -1);
    bool good = false;

    for(int i = 0; i < n-1; i++) {
        if(has[(s[i]-'a')*26+(s[i+1]-'a')] == -1) has[(s[i]-'a')*26+(s[i+1]-'a')] = i+1;
    }

    for(int i = 0; i < n-1; i++) {
        if(has[(s[i]-'a')*26+(s[i+1]-'a')] < i) good = true;
    }

    cout << (good ? "YES" : "NO") << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}