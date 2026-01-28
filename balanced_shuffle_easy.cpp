#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    string s; cin >> s;
    int o=0, c=0;

    int n = s.length();
    vector<int> prefix(n), ind(n);

    iota(ind.begin(), ind.end(), 0);

    if(s[0] == '(') o++;
    else c++;

    for(int i = 1; i < n; i++) {
        prefix[i] = o-c;
        if(s[i] == '(') o++;
        else c++;
    }

    sort(ind.begin(), ind.end(), [&](int a, int b) {
        if(prefix[a] < prefix[b]) return true;
        else if(prefix[b] < prefix[a]) return false;
        else return a > b;
    });

    for(int i: ind) cout << s[i];
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}