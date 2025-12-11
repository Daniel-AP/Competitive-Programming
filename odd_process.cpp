#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> even, odd;

    for(int i = 0; i < n; i++) {
        if(a[i]%2) odd.push_back(a[i]);
        else even.push_back(a[i]);
    }

    sort(even.rbegin(), even.rend());
    sort(odd.rbegin(), odd.rend());

    if(even.size() == 0)  {

        for(int i = 0; i < n; i++) {
            if(i%2 == 0) cout << odd[0] << ' ';
            else cout << 0 << ' ';
        }

        cout << '\n';

        return;

    }

    if(odd.size() == 0) {

        for(int i = 0; i < n; i++) cout << "0 ";
        cout << '\n';

        return;

    }

    int curE = 0, curO = 1;
    int cur = odd[0];

    cout << cur << ' ';

    for(int i = 1; i < n; i++) {
        if(i%2 == 0) {
            if(curE+1 < even.size()) {
                cur += even[curE]+even[curE+1];
                curE += 2;
                cout << cur << ' ';
            } else if(curO+1 < odd.size()) {
                curO += 2;
                cout << cur << ' ';
            } else cout << 0 << ' ';
        } else {
            if(curE < even.size()) {
                cout << cur+even[curE] << ' ';
            } else if(curO+1 < odd.size() && curE > 0) {
                cout << cur-even[curE-1] << ' ';
            } else cout << 0 << ' ';
        }
    }

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