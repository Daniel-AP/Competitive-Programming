#include <bits/stdc++.h>
using namespace std;

void solve() {

    int t;
    cin >> t;

    while(t--) {

        string s;
        cin >> s;

        int zero = 0;
        int one = 0;

        for(char c: s) {
            if(c == '0') zero++;
            if(c == '1') one++;
        }

        cout << one << endl;

    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}