#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m, x, y; cin >> n >> m >> x >> y;

    set<int, greater<int>> a;
    for(int i = 0; i < x; i++) {
        int k; cin >> k;
        a.insert(k);
    }

    set<int, greater<int>> b;
    for(int i = 0; i < y; i++) {
        int k; cin >> k;
        b.insert(k);
    }

    set<int, greater<int>> aonly, bonly, inter;

    for(int k: a) {
        if(!b.contains(k)) aonly.insert(k);
    }

    for(int k: b) {
        if(!a.contains(k)) bonly.insert(k);
    }

    for(int k: a) {
        if(b.contains(k)) inter.insert(k);
    }

    int ans = 0;

    set<int, greater<int>> aa, bb;
    
    for(int k: aonly) aa.insert(k);
    for(int k: inter) aa.insert(k);
    for(int k: bonly) bb.insert(k);
    for(int k: inter) bb.insert(k);

    int i = 0, cur = 0;
    for(int k: aa) {
        if(i == n) break;
        cur += k;
        i++;
    }

    ans = max(ans, cur);
    cur = 0, i = 0;

    for(int k: bb) {
        if(i == m) break;
        cur += k;
        i++;
    }

    ans = max(ans, cur);
    cur = 0, i = 0;

    set<int, greater<int>> curr;
    
    for(int k: aonly) {
        if(i == n) break;
        curr.insert(k);
        i++;
    }

    i = 0;
    for(int k: bonly) {
        if(i == m-1) break;
        curr.insert(k);
        i++;
    }

    for(int k: inter) curr.insert(k);

    i = 0;
    for(int k: curr) {
        if(i == n+m-1) break;
        cur += k;
        i++;
    }

    ans = max(ans, cur);
    cur = 0, i = 0;
    curr.clear();

    for(int k: aonly) {
        if(i == n-1) break;
        curr.insert(k);
        i++;
    }

    i = 0;
    for(int k: bonly) {
        if(i == m) break;
        curr.insert(k);
        i++;
    }

    for(int k: inter) curr.insert(k);

    i = 0;
    for(int k: curr) {
        if(i == n+m-1) break;
        cur += k;
        i++;
    }

    ans = max(ans, cur);

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