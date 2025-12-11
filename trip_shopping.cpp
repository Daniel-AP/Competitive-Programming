#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<int> ind(n);

    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int i, int j) { return a[i] < a[j]; });
    
    int prev = 0;
    bool sorted = true;
    
    for(int i: ind) {
        if(prev > b[i]) sorted = false;
        prev = b[i];
    }
    
    if(!sorted) {
        int ans = 0;
        for(int i = 0; i < n; i++) ans += abs(a[i]-b[i]);
        
        return void(cout << ans << '\n');
    }
    
    int mn = INF;

    for(int i = 0; i+1 < n; i++) {

        int diff1 = abs(a[ind[i]]-b[ind[i]])+abs(a[ind[i+1]]-b[ind[i+1]]);
        int diff2 = abs(a[ind[i]]-b[ind[i+1]])+abs(a[ind[i+1]]-b[ind[i]]);

        mn = min(mn, diff2-diff1);

    }

    for(int i = 0; i+1 < n; i++) {

        int diff1 = abs(a[ind[i]]-b[ind[i]])+abs(a[ind[i+1]]-b[ind[i+1]]);
        int diff2 = abs(a[ind[i]]-b[ind[i+1]])+abs(a[ind[i+1]]-b[ind[i]]);

        if(diff2-diff1 == mn) {
            swap(b[ind[i]], b[ind[i+1]]);
            break;
        }

    }

    int ans = 0;
    for(int i = 0; i < n; i++) ans += abs(a[i]-b[i]);

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