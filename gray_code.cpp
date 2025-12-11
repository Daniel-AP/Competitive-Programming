#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;
    string prev(n, '0');
    set<string> s = { prev };

    cout << prev << endl;

    while(s.size() != (1<<n)) {
        vector<string> candidates(n);
        for(int i = 0; i < n; i++) {
            string k = prev;
            k[i] = (char)('1'+'0'-k[i]);
            candidates[i] = k;
        }
        for(int i = 0; i < n; i++) {
            if(!s.count(candidates[i])) {
                cout << candidates[i] << endl;
                prev = candidates[i];
                s.insert(candidates[i]);
                break;
            }
        }
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}