#include <bits/stdc++.h>
using namespace std;

#define int unsigned int

void solve() {

    int n, x; cin >> n >> x;

    vector<int> ans = {0};
    int op = 0;

    for(int i = 1; i < n; i++) {
        if((x&i) == i) ans.push_back(i);
    }

    int m = ans.size();

    for(int i = 0; i < n-m; i++) ans.push_back(0);
    for(int i: ans) op |= i;

    if(op != x) ans.back() = x;

    for(int i: ans) cout << i << " ";
    cout << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}