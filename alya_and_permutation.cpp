#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    if(n == 5) {
        cout << 5 << '\n';
        cout << "2 1 3 4 5" << '\n';
        return;
    }

    vector<int> ans(n), used(n+1);

    int m = bit_floor(n), i = n-n%2-1;

    while(m > 1) {
        if(i%2 == 0) {
            used[m] = 1;
            ans[i] = m, m = (m+1)/2;
        } else {
            ans[i] = m;
            used[m] = 1;
            m--;
        }
        i--;
    }

    ans[i] = 1;
    used[1] = 1;
    
    if(n&1) {
        int mx = 0;
        for(int i = 1; i <= n; i += 2) if(!used[i]) mx = max(mx, ((bit_floor(n)*2-1)&i));
        for(int i = 1; i <= n; i += 2) if(!used[i] && ((bit_floor(n)*2-1)&i) == mx) {
            used[i] = 1;
            ans[n-1] = i;
            break;
        }
    }

    i = 0;

    for(int j = 2; j <= n; j += 2) {
        if(used[j]) continue;
        if(ans[i]) {
            i++;
            j -= 2;
            continue;
        }
        ans[i] = j;
        used[j] = 1;
        i++;
    }

    for(int j = 1; j <= n; j += 2) {
        if(used[j]) continue;
        if(ans[i]) {
            i++;
            j -= 2;
            continue;
        }
        ans[i] = j;
        used[j] = 1;
        i++;
    }

    int val = 0;

    for(int i = 0; i < n; i++) {
        if(i%2 == 0) {
            val &= ans[i];
        } else {
            val |= ans[i];
        }
    }

    cout << val << '\n';
    for(int x: ans) cout << x << ' ';
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