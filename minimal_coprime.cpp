#include <bits/stdc++.h>
using namespace std;

void solve() {

    int t;
    cin >> t;

    while(t--) {

        long long l, r;
        cin >> l >> r;

        if(l == r) {
            cout << (l == 1) << endl;
            continue;
        }

        cout << r-l << endl;

    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}