#include <bits/stdc++.h>
using namespace std;

#define int long long

int s(int n) {
    return (n*(n-1))/2;
}

void solve() {

    int n; cin >> n;

    unordered_map<int, int> counter;
    vector<int> b(n);
    int mn = 1e9, mx = 0;

    for(int i = 0; i < n; i++) {

        cin >> b[i];
        mn = min(b[i], mn);
        mx = max(b[i], mx);

        counter[b[i]]++;

    }

    int ways = 0;

    if(mx-mn == 0) {
        for(auto p: counter) ways += s(counter[p.first]);
    } else {
        ways = counter[mn]*counter[mx];
    }

    cout << mx-mn << " " << ways << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}