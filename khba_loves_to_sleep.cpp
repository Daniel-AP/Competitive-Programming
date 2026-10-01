#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k, x; cin >> n >> k >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(all(a));

    vector<int> ans;

    int l = 0, r = x, mid;

    while(l <= r) {
        mid = l+(r-l)/2;
        set<int> cur;
        bool ok = false;
        for(int i = 0; i+1 < n; i++) {
            int lb = a[i]+mid, rb = a[i+1]-mid;
            if(lb > rb) continue;
            for(int j = lb; j <= rb; j++) {
                if(cur.size() == k) break;
                cur.insert(j);
            }
            if(cur.size() == k) ok = true;
            if(ok) break;
        }
        for(int i = 0; i <= a[0]-mid; i++) {
            if(cur.size() == k) break;
            cur.insert(i);
        }
        for(int i = a.back()+mid; i <= x; i++) {
            if(cur.size() == k) break;
            cur.insert(i);
        }
        if(cur.size() == k) ok = true;
        if(ok) {
            ans.clear();
            for(int v: cur) ans.push_back(v);
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    for(int v: ans) cout << v << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}