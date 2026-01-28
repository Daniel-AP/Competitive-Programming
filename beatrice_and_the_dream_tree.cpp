#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 

vector<vector<int>> children;
vector<int> code;

int cnt;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x^(x >> 30))*0xbf58476d1ce4e5b9ULL;
        x = (x^(x >> 27))*0x94d049bb133111ebULL;
        return x^(x >> 31);
    }
    
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return (size_t)splitmix64(x+FIXED_RANDOM);
    }
};

struct vec_hash {
    int operator()(const vector<int>& v) const noexcept {
        static const uint64_t SEED =
            chrono::steady_clock::now().time_since_epoch().count();
        uint64_t h = custom_hash::splitmix64(SEED+v.size());
        for(int i = 0; i < v.size(); i++) {
            uint64_t x = (uint64_t)hash<int>{}(v[i]);
            h ^= custom_hash::splitmix64(x+0x9e3779b97f4a7c15ULL*(i+1));
            h = custom_hash::splitmix64(h);
        }
        return (int)h;
    }
};

unordered_map<vector<int>, int, vec_hash> h;

int dfs(int u) {
    if(children[u].empty()) {
        auto it = h.find(vector<int>());
        if(it == h.end()) {
            h[vector<int>()] = ++cnt;
            code[u] = cnt;
        } else {
            code[u] = it->second;
        }
        return code[u];
    }
    vector<int> ch(children[u].size());
    for(int i = 0; i < (int)children[u].size(); i++) {
        ch[i] = dfs(children[u][i]);
    }
    sort(ch.begin(), ch.end());

    auto it = h.find(ch);
    if(it == h.end()) {
        h[ch] = ++cnt;
        code[u] = cnt;
    } else {
        code[u] = it->second;
    }
    return code[u];
}

void solve() {

    int n; cin >> n;

    vector<vector<int>> g(n+1);

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    children.assign(n+1, vector<int>());

    vector<int> p(n+1, 0), q; q.reserve(n);
    p[1] = -1; q.push_back(1);

    for(int i = 0; i < (int)q.size(); i++) {
        int u = q[i];
        for(int v : g[u]) {
            if(v != p[u]) {
                p[v] = u;
                children[u].push_back(v);
                q.push_back(v);
            }
        }
    }

    h.clear();
    cnt = 0;
    code.assign(n+1, 0);
    dfs(1);

    vector<char> uni(n+1, 0);

    for(int u = 1; u <= n; u++) {
        vector<int> ch = children[u];
        if(ch.size() == 1) { uni[ch[0]] = 1; continue; }
        if(ch.size() >= 2) {
            vector<pair<int,int>> a(ch.size());
            for(int i = 0; i < (int)ch.size(); i++) {
                a[i] = { code[ch[i]], ch[i] };
            }
            sort(a.begin(), a.end());
            for(int i = 0; i < (int)a.size();) {
                int j = i;
                while(j < (int)a.size() && a[j].first == a[i].first) j++;
                if(j-i == 1) uni[a[i].second] = 1;
                i = j;
            }
        }
    }

    int ans = 1;
    
    vector<pair<int,bool>> st; st.reserve(n);
    st.push_back({1, true});

    for(int i = 0; i < (int)st.size(); i++) {
        auto [u, fix] = st[i];
        for(int v : children[u]) {
            bool nx = fix && (uni[v] != 0);
            if(nx) ans++;
            st.push_back({v, nx});
        }
    }

    cout << ans << '\n';
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}
