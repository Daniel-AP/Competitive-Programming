#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

void solve() {

    int n; cin >> n;

    vector<int> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    unordered_map<int, int> ind;
    unordered_map<int, vector<int>> pos;

    for(int i = 0; i < n; i++) {
        pos[s[i]].push_back(i+1);
    }

    for(auto &[k, v]: pos) {
        if(v.size() == 1) {
            cout << -1 << "\n";
            return;
        } else {
            rotate(v.begin(), v.end()-1, v.end());
        }
    }

    for(int i = 0; i < n; i++) {
        cout << pos[s[i]][ind[s[i]]] << " ";
        ind[s[i]]++;
    }
    
    cout << "\n";

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}