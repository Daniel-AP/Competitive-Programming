#include <bits/stdc++.h>
using namespace std;

void solve() {

    int t;
    cin >> t;

    while(t--) {

        long long a, b;
        cin >> a >> b;

        if(b == 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << a << " " << a*(2*b-1) << " " << 2*a*b << endl;
        }

    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}