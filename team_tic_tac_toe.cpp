#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    vector<string> ttt(3);
    cin >> ttt[0] >> ttt[1] >> ttt[2];
    
    set<int> s1;
    set<pair<int, int>> s2;

    for(int i = 0; i < 3; i++) {
        set<char> t(ttt[i].begin(), ttt[i].end());
        if(t.size() == 1) s1.insert(*t.begin());
        if(t.size() == 2) s2.insert({ *t.begin(), *t.rbegin() });
    }

    for(int i = 0; i < 3; i++) {
        set<char> t;
        for(int j = 0; j < 3; j++) t.insert(ttt[j][i]);
        if(t.size() == 1) s1.insert(*t.begin());
        if(t.size() == 2) s2.insert({ *t.begin(), *t.rbegin() });
    }

    set<char> t{ ttt[0][0], ttt[1][1], ttt[2][2] };

    if(t.size() == 1) s1.insert(*t.begin());
    if(t.size() == 2) s2.insert({ *t.begin(), *t.rbegin() });

    cout << s1.size() << '\n' << s2.size();

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    int t; t = 1;

    while(t--) solve();

    return 0;

}