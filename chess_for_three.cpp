#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;

        if((p1+p2+p3)%2 != 0) {

            cout << -1 << endl;

        } else {

            cout << min((p1+p2+p3)/2, p1+p2) << endl;

        }

    }

    return 0;

}