#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        long long n, s;
        cin >> n >> s;

        if(n == 1) {
            cout << s << endl;
            continue;
        }

        long long pos = n/2+n%2;
        long long median = s/(n-pos+1);

        cout << median << endl;

    }

    return 0;

}