#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n1, n2, n3, n4; cin >> n1 >> n2 >> n3 >> n4;

        for(int i = 0; i < n1; i++) cout << 'O';
        for(int i = 0; i < n2; i++) cout << 'I';
        for(int i = 0; i < n3; i++) cout << 'E';
        for(int i = 0; i < n4; i++) cout << '!';

        cout << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}