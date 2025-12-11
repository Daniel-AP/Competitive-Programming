#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;

        int min_grain = a-b;
        int max_grain = a+b;
        int min_total = c-d;
        int max_total = c+d;

        if(min_grain*n > max_total || max_grain*n < min_total) cout << "No" << endl;
        else cout << "Yes" << endl;

    }

}