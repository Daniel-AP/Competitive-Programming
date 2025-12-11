#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        long long n;
        cin >> n;

        cout << max(6LL, n+n%2)*5/2 << endl;

    }

    return 0;

}