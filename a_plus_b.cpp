#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        string n;
        cin >> n;

        int result = 0;

        for(char c: n) {
            result += c-'0';
        }

        cout << result << endl;

    }

    return 0;

}