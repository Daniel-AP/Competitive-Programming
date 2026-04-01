#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)
 
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "\nTime elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";
 
// #define MOD 1000000007
// #define MOD 998244353
 
void solve() {
 
    int n, x; cin >> n >> x;
 
    vector<pair<int, int>> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
 
    sort(all(a));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {

            int y = x-(a[i].first+a[j].first);
            int k1 = lower_bound(a.begin(), a.begin()+j, make_pair(y, 0LL))-a.begin();
            int k2 = lower_bound(a.begin()+j+1, a.begin()+i, make_pair(y, 0LL))-a.begin();
            int k3 = lower_bound(a.begin()+i+1, a.end(), make_pair(y, 0LL))-a.begin();

            int k = -1;

            if(k1 < j && a[k1].first == y) k = k1;
            else if(k2 < i && a[k2].first == y) k = k2;
            else if(k3 < n && a[k3].first == y) k = k3;

            if(k == -1) continue;

            cout << a[i].second << ' ' << a[j].second << ' ' << a[k].second << '\n';

            return;

        }
    }

    cout << "IMPOSSIBLE" << '\n';
    
}
 
signed main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    int t = 1;
 
    // START_TIMER;
 
    while(t--) solve();
 
    // END_TIMER;
 
    return 0;
 
}