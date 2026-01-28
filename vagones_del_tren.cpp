#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

struct BIT {

    int n;
    vector<int> t;

    BIT(int n, vector<int>& a) : n(n), t(n+1) {

        for(int i = 1; i <= n; i++) {
            t[i] += a[i-1];
            int j = i+(i&-i);
            if(j <= n) t[j] += t[i];
        }

    }

    void update(int i, int val) {

        while(i <= n) {
            t[i] += val;
            i += i&-i;
        }

    }

    int query(int i) {

        int ans = 0;

        while(i > 0) {
            ans += t[i];
            i -= i&-i;
        }

        return ans;

    }

};

void solve() {

    int n, q; cin >> n >> q;

    vector<int> a(n);
    BIT bit(n, a);

    while(q--) {

        char o; cin >> o;

        if(o == 'A') {
            int p, v; cin >> p >> v;
            bit.update(1, v);
            bit.update(p+1, -v);
        } else {
            int p; cin >> p;
            cout << bit.query(p) << '\n';
        }

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}