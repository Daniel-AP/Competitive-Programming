#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;

        string s;
        cin >> s;

        int count = 2;
        int mx = 2;

        for(int i = 1; i < n; i++) {
            if(s[i-1] != s[i]) {
                count = 2;
            } else {
                count++;
                mx = max(count, mx);
            }
        }

        cout << mx << endl;

    }

    return 0;

}