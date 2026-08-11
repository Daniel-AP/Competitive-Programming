#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    set<int> avail;
    for(int i = 1; i <= n; i++) avail.insert(i);

    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = x;
        avail.erase(x);
    }

    vector<int> ans(n);

    if(avail.size() > 0) {

        int i = 0;

        set<int> can;
        for(int i = 1; i <= n; i++) can.insert(i);

        while(!avail.empty()) {
            ans[i] = *avail.begin();
            can.erase(*avail.begin());
            avail.erase(avail.begin());
            i++;
        }

        while(i < n) {
            int first = *can.begin();
            can.erase(can.begin());
            if(first == a[n-i]) {
                if(!can.empty()) {
                    ans[i] = *can.begin();
                    can.erase(can.begin());
                    can.insert(first);
                } else {
                    ans[i] = first;
                }
            } else {
                ans[i] = first;
            }
            i++;
        }

    } else {

        for(int i = 0; i < n; i++) {
            ans[i] = a[i];
        }

    }

    for(int i = 0; i < k; i++) cout << ans[i] << ' ';
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