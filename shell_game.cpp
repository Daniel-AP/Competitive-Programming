#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int n; cin >> n;
    
    vector<int> p(3);
    vector<int> score(3);

    iota(p.begin(), p.end(), 1);

    for(int i = 0; i < n; i++) {

        int a, b, g; cin >> a >> b >> g;

        for(int j = 0; j < 3; j++) {
            if(p[j] == a) p[j] = b;
            else if(p[j] == b) p[j] = a;
        }

        for(int j = 0; j < 3; j++) {
            if(p[j] == g) score[j]++;
        }

    }

    cout << *max_element(score.begin(), score.end());
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int t; t = 1;

    while(t--) solve();

    return 0;

}