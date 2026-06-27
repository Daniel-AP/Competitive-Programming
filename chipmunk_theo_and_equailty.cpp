#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> b(a);

    set<int> cur{{1, 2}};

    while(a[0] > 1) {
        cur.insert(a[0]);
        if(a[0]%2) a[0]++;
        else a[0] /= 2;
    }

    for(int i = 1; i < n; i++) {
        set<int> s{{1, 2}}, res;
        while(a[i] > 1) {
            s.insert(a[i]);
            if(a[i]%2) a[i]++;
            else a[i] /= 2;
        }
        set_intersection(all(cur), all(s), inserter(res, res.begin()));
        swap(cur, res);
    }

    int ans = INF;

    for(int x: cur) {
        vector<int> c(b);
        int anscur = 0;
        for(int i = 0; i < n; i++) {
            while(c[i] != x) {
                if(c[i]%2) c[i]++;
                else c[i] /= 2;
                anscur++;
            }
        }
        ans = min(ans, anscur);
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}