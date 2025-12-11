#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;

    vector<set<int>> rows(n), cols(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2*n; j++) {
            rows[i].insert(j);
            cols[i].insert(j);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            set<int> s;
            set_intersection(rows[i].begin(), rows[i].end(), cols[j].begin(), cols[j].end(), inserter(s, s.begin()));
            int mex = *s.begin();
            rows[i].erase(mex); cols[j].erase(mex);
            cout << mex << " ";
        }
        cout << endl;
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}