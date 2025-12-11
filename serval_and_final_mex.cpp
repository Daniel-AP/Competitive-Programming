#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, int>> moves;

    int cnt = count(a.begin(), a.end(), 0);

    if(cnt == 0) {
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
        return;
    }

    if(a.back() == 0) {

        cnt--;
        if(a[n-2] == 0) cnt--;

        if(cnt == 0) {
            cout << 2 << endl;
            cout << n-1 << " " << n << endl;
            cout << 1 << " " << n-1 << endl;
            return;
        }

        moves.push_back({ n-1, n });
        n--;

    }

    moves.push_back({ 1, n-1 });
    moves.push_back({ 1, 2 });

    cout << moves.size() << endl;

    for(pair<int, int> m: moves) {
        cout << m.first << " " << m.second << endl;
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}