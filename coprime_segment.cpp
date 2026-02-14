#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

template <class T, class Op>
struct AggQueue {

    vector<pair<T, T>> in, out;

    int size() const { return (int)in.size()+(int)out.size(); }
    bool empty() const { return size() == 0; }

    void push(const T& x) {
        T agg = in.empty() ? x : Op::merge(in.back().second, x);
        in.push_back({x, agg});
    }

    void pour() {
        while(!in.empty()) {
            T x = in.back().first;
            in.pop_back();
            T agg = out.empty() ? x : Op::merge(x, out.back().second);
            out.push_back({x, agg});
        }
    }

    void pop() {
        if(out.empty()) pour();
        out.pop_back();
    }

    T query() const {
        if(in.empty()) return out.back().second;
        if(out.empty()) return in.back().second;
        return Op::merge(out.back().second, in.back().second);
    }
    
};

struct GcdOp {
    static int merge(int a, int b) { return gcd(a, b); }
};

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    AggQueue<int, GcdOp> q;

    int ans = INF;

    for(int r = 0; r < n; r++) {
        q.push(a[r]);
        while(!q.empty() && q.query() == 1) {
            ans = min(ans, q.size());
            q.pop();
        }
    }

    cout << (ans == INF ? -1 : ans) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}