#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

int op(int a, int b) {
    return a+b;
}

int inv(int a) {
    return -a;
}

const int neu = 0;

struct BIT {

    int n;
    vector<int> t;

    BIT(int n, vector<int>& a) : n(n), t(n+1, neu) {

        for(int i = 1; i <= n; i++) {
            t[i] = op(t[i], a[i-1]);
            int j = i+(i&-i);
            if(j <= n) t[j] = op(t[j], t[i]);
        }

    }

    void update(int i, int val) {

        int curr = range(i, i);
        int x = op(val, inv(curr));

        while(i <= n) {
            t[i] = op(t[i], x);
            i += i&-i;
        }

    }

    int query(int i) {

        int ans = neu;

        while(i > 0) {
            ans = op(ans, t[i]);
            i -= i&-i;
        }

        return ans;

    }

    int range(int l, int r) {
        
        return op(query(r), inv(query(l-1)));

    }

};

void solve() {

    int n, q; cin >> n >> q;

    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    BIT bit(n, x);

    while(q--) {

        int o, k, u; cin >> o >> k >> u;

        if(o == 1) bit.update(k, u);
        else cout << bit.range(k, u) << '\n';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}