#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> first, last;

    for(int i = 0; i < n; i++) {
        if(first.find(a[i]) == first.end()) first[a[i]] = i;
        last[a[i]] = i;
    }

    vector<int> diff(n+1);

    for(auto [k, v]: first) {
        diff[v]++;
        diff[last[k]]--;
    }

    vector<int> bad(n);
    bad[n-1] = 0;

    for(int i = n-2; i >= 0; i--) {
        bad[i] = bad[i+1]+(a[i]>a[i+1]);
    }

    int cur = 0;
    set<int> un;

    for(int i = 0; i < n; i++) {
        if(cur == 0 && bad[i] == 0) return void(cout << un.size() << '\n');
        un.insert(a[i]);
        cur += diff[i];
    }

    cout << un.size() << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}