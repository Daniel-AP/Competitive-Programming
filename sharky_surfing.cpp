#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n, m, l; cin >> n >> m >> l;

    vector<tuple<int, int, char>> events;

    for(int i = 0; i < n; i++) {
        int li, ri; cin >> li >> ri;
        events.push_back({ li, ri-li+1, 'H' });
    }

    for(int i = 0; i < m; i++) {
        int xi, vi; cin >> xi >> vi;
        events.push_back({ xi, vi, 'P' });
    }

    sort(events.begin(), events.end());

    multiset<int, greater_equal<int>> ms;

    int acc = 1, cnt = 0;

    for(tuple<int, int, char> e: events) {
        if(get<2>(e) == 'H' && acc <= get<1>(e)) {
            while(acc <= get<1>(e)) {
                if(ms.empty()) {
                    cout << -1 << '\n';
                    return;
                }
                acc += *(ms.begin());
                ms.erase(ms.begin());
                cnt++;
            }
        }
        if(get<2>(e) == 'P') {
            ms.insert(get<1>(e));
        }
    }

    cout << cnt << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}