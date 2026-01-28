#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int n, m; cin >> n >> m;

    vector<tuple<int, int, int>> a;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x; cin >> x;
            a.push_back({ x, i, j });
        }
    }

    sort(a.rbegin(), a.rend());

    int i = 1, l = get<1>(a[0]), r = get<2>(a[0]);

    for(; i < n*m; i++) {
        if(get<1>(a[i]) != l) {
            r = get<2>(a[i]);
            break;
        }
    }

    for(; i < n*m; i++) {
        if(get<2>(a[i]) != r && get<1>(a[i]) != l) {
            break;
        }
    }

    int ans1, ans2;

    if(i == n*m) {
        ans1 = get<0>(a[0])-1;
    } else {
        ans1 = max(get<0>(a[0])-1, get<0>(a[i]));
    }

    r = get<2>(a[0]);
    i = 1;

    for(; i < n*m; i++) {
        if(get<2>(a[i]) != r) {
            l = get<1>(a[i]);
            break;
        }
    }

    for(; i < n*m; i++) {
        if(get<2>(a[i]) != r && get<1>(a[i]) != l) {
            break;
        }
    }

    if(i == n*m) {
        ans2 = get<0>(a[0])-1;
    } else {
        ans2 = max(get<0>(a[0])-1, get<0>(a[i]));
    }

    cout << min(ans1, ans2) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}