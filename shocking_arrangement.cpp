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

    vector<int> pos, neg, ans;
    
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) ans.push_back(a[i]);
        else if(a[i] < 0) neg.push_back(a[i]);
        else pos.push_back(a[i]); 
    }

    if(count(all(ans), 0) == n) return void(cout << "No" << '\n');

    sort(all(pos)); sort(all(neg));

    int mx = pos.back();
    int px = pos.back();

    ans.push_back(pos.back());
    pos.pop_back();

    while(pos.size() && neg.size()) {
        if(px+pos.back() > mx) {
            ans.push_back(neg.back());
            px += neg.back();
            neg.pop_back();
        } else {
            ans.push_back(pos.back());
            px += pos.back();
            pos.pop_back();
        }
    }

    while(pos.size()) {
        ans.push_back(pos.back());
        pos.pop_back();
    }

    while(neg.size()) {
        ans.push_back(neg.back());
        neg.pop_back();
    }

    cout << "Yes" << '\n';
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