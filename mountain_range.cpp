#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "\nTime elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

struct Mono {
    int v;
    Mono(int v) : v(v) {}
    static Mono zero() { return {0LL}; }
};

Mono operator+(Mono a, Mono b) {
    return Mono(max(a.v, b.v));
}

struct Tree {
    vector<Mono> s;
    int n;

    Tree(int n) : n(n), s(2*n, Mono::zero()) {}

    void update(int pos, Mono val) {
        for (s[pos += n] = val; pos >>= 1;) s[pos] = s[pos<<1]+s[pos<<1|1];
    }

    // [l, r)
    Mono query(int l, int r) {
        Mono lv = Mono::zero(), rv = Mono::zero();
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) lv = lv+s[l++];
            if (r&1) rv = s[--r]+rv;
        }
        return lv+rv;
    }
};

void solve() {

    int n; cin >> n;

    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    stack<int> st;
    vector<int> l(n, -1), r(n, n);

    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && h[st.top()] < h[i]) st.pop();
        if(!st.empty()) r[i] = st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = 0; i < n; i++) {
        while(!st.empty() && h[st.top()] < h[i]) st.pop();
        if(!st.empty()) l[i] = st.top();
        st.push(i);
    }

    Tree seg(n);

    vector<int> memo(n, -1);
    set<int> unvis;

    for(int i = 0; i < n; i++) unvis.insert(i);

    auto dfs = [&](auto&& self, int i) -> int {
        if(memo[i] != -1) return memo[i];
        while(!unvis.empty() && unvis.upper_bound(l[i]) != unvis.end() && *unvis.upper_bound(l[i]) < i) self(self, *unvis.upper_bound(l[i]));
        while(!unvis.empty() && unvis.upper_bound(i) != unvis.end() && *unvis.upper_bound(i) < r[i]) self(self, *unvis.upper_bound(i));
        memo[i] = 1+max(seg.query(l[i]+1, i).v, seg.query(i+1, r[i]).v);
        unvis.erase(i);
        seg.update(i, memo[i]);
        return memo[i];
    };

    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, dfs(dfs, i));

    cout << ans << '\n';
    
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