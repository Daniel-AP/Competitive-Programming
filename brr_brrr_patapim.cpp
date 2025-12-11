#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        vector<int> perm(2*n);
        iota(perm.begin(), perm.end(), 1);
        unordered_set<int> s(perm.begin(), perm.end());

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int x; cin >> x;
                perm[i+j+1] = x;
                s.erase(x);
            }
        }

        cout << *s.begin() << " ";
        for(int i = 1; i < n; i++) cout << perm[i] << " ";
        cout << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}