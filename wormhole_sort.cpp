#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    int n, m; cin >> n >> m;

    vector<int> p(n+1);
    for(int i = 1; i <= n; i++) cin >> p[i];

    vector<tuple<int, int, int>> wrs(m+1);
    for(int i = 1; i <= m; i++) {
        int a, b, w; cin >> a >> b >> w;
        wrs[i] = { a, b, w };
    }

    unordered_map<int, int> mp;

    for(int i = 1; i <= n; i++) {
        mp[p[i]] = i;
        mp[i] = p[i];
    }

    bool sorted = true;

    for(int i = 1; i <= n; i++) {
        if(p[i] != i) sorted = false;
    }

    if(sorted) {
        cout << -1;
        return;
    }

    sort(wrs.begin()+1, wrs.end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {
        return get<2>(a) > get<2>(b);
    });

    unordered_map<int, vector<int>> g;
    queue<int> q;
    vector<bool> visited(n+1);

    vector<set<int>> ccs;

    int l(1), r(m), mid, ans;
    bool good = true;

    while(l <= r) {

        mid = l+(r-l)/2;

        for(int i = 1; i <= mid; i++) {
            auto [a, b, w] = wrs[i];
            g[a].push_back(b); g[b].push_back(a);
        }

        for(auto [ky, v]: g) {

            if(visited[ky]) continue;
            q.push(ky); visited[ky] = true;

            ccs.push_back(set<int>());

            while(!q.empty()) {
                int k = q.front(); q.pop();
                ccs.back().insert(k);
                for(int j: g[k]) {
                    if(visited[j]) continue;
                    q.push(j); visited[j] = true;
                }
            }

        }

        for(int i = 0; i < ccs.size(); i++) {
            if(!good) break;
            for(int j: ccs[i]) {
                if(ccs[i].count(mp[j]) == 0) {
                    good = false;
                    break;
                }
            }
        }

        bool o = true;

        for(int i = 1; i <= n; i++) {
            if(p[i] != i && !visited[p[i]]) o = false;
        }

        if(!o) {
            l = mid+1;
        } else if(good) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }

        good = true;
        g.clear(); fill(visited.begin(), visited.end(), false);
        ccs.clear();

    }

    cout << get<2>(wrs[ans]);
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    int t; t = 1;

    while(t--) solve();

    return 0;

}