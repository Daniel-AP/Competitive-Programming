#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<array<int, 3>> a(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) cin >> a[i][j];
    }

    vector<int> c(n);

    for(int i = 0; i < n; i++) {
        if(!is_sorted(all(a[i]))) continue;
        if(a[i][0] == a[i][1] && a[i][1] == a[i][2]) c[i] = INF;
        set<int> st(all(a[i]));
        if(st.size() == 2) c[i] = 1;
        else if(st.size() == 3) {
            vector<int> aa(all(st));
            c[i] = min(aa[2]-aa[1], aa[1]-aa[0])+1;
        }
    }

    int l = (int)(-1e10), r = (int)(1e10)+k, mid, ans;

    while(l <= r) {
        mid = l+(r-l)/2;
        bool ok = true;
        int kk = k;
        int cost = 0;
        vector<int> ss(n);
        for(int i = 0; i < n; i++) {
            if(a[i][0]+a[i][1]+a[i][2] < mid) {
                cost += c[i], ss[i] = a[i][0]+a[i][1]+a[i][2]-c[i];
                if(c[i] == INF) {
                    ok = false;
                    break;
                }
            }
            else ss[i] = a[i][0]+a[i][1]+a[i][2];
        }
        if(!ok) {
            r = mid-1;
            continue;
        }
        if(cost > kk) {
            r = mid-1;
            continue;
        }
        kk -= cost;
        for(int i = 0; i < n; i++) {
            if(ss[i] < mid) {
                if(kk < mid-ss[i]) {
                    ok = false;
                    break;
                }
                kk -= mid-ss[i];
            }
        }
        if(ok) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
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