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

    string s; cin >> s;

    int invs = 0, ones = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] == 1) ones++;
        else invs += ones;
    }

    if(is_sorted(all(a))) {
        for(int i = 0; i < n+1; i++) cout << 0 << ' ';
        cout << '\n';
        return;
    }

    vector<int> invsin, invsrev;
    int cnt0 = 0, cnt1 = 0;

    for(int i = n-1; i >= 0; i--) {
        if(a[i] == 1) {
            invsin.push_back(cnt0);
        } else {
            cnt0++;
        }
    }

    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            invsrev.push_back(cnt1);
        } else {
            cnt1++;
        }
    }

    reverse(all(invsin));
    reverse(all(invsrev));

    int curin = 0, currev = 0;
    int redin = 0, redrev = 0;

    cout << invs << ' ';

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            if(curin >= invsin.size()) cout << invs;
            else cout << max(invs-max(invsin[curin]-redin, 0LL), 0LL);
            cout << ' ';
            if(curin < invsin.size()) invs -= max(invsin[curin++]-redin, 0LL);
            invs = max(invs, 0LL);
            redrev++;
        } else {
            if(currev >= invsrev.size()) cout << invs;
            else cout << max(invs-max(invsrev[currev]-redrev, 0LL), 0LL);
            cout << ' ';
            if(currev < invsrev.size()) invs -= max(invsrev[currev++]-redrev, 0LL);
            invs = max(invs, 0LL);
            redin++;
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