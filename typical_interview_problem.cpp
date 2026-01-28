#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

string fb;

void pre() {

    int i = 1;

    while(fb.size() < 50) {
        if(i%3 == 0) fb += 'F';
        if(i%5 == 0) fb += 'B';
        i++;
    }

}

void solve() {

    int k; cin >> k;
    string s; cin >> s;

    if(fb.find(s) != string::npos) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    pre();

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}