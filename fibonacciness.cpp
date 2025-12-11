#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        int a1, a2, a3, a4, a5;
        cin >> a1 >> a2 >> a4 >> a5;

        vector<int> possible = { a1+a2, a4-a2, a5-a4 };
        int mx = 0;

        for(int p: possible) {
            a3 = p;
            mx = max((a1+a2==a3)+(a2+a3==a4)+(a3+a4==a5), mx);
        }

        cout << mx << endl;

    }

    return 0;

}