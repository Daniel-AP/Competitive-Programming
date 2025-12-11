#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    map<pair<int, int>, int> mp;

    int d = 0, k = 0;

    for(char c: s) {

        d += (c=='D');
        k += (c=='K');

        int a = d, b = k, g = gcd(d, k);
        a /= g, b /= g;

        mp[{ a, b }]++;

        cout << mp[{ a, b }] << ' ';

    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}