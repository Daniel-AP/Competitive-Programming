#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    multiset<int> a;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }

    int l = 0, r = n, mid, ans = 0;

    while(l <= r) {
        mid = l+(r-l)/2;
        vector<bool> need(mid, 1);
        multiset<int> b(a);
        for(int i = 0; i < mid; i++) {
            auto it = b.find(i);
            if(it != b.end()) b.erase(it), need[i] = 0;
        }
        for(int i = 0; i < mid; i++) {
            if(!need[i]) continue;
            auto it = b.upper_bound(2*i);
            if(it == b.end()) break;
            need[i] = 0;
            b.erase(it);
        }
        int mex = 0;
        while(mex < mid && !need[mex]) mex++;
        if(mex == mid) {
            l = mid+1;
            ans = mid;
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