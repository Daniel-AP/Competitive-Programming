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

        vector<int> a(n), b, c;
        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end(), greater<int>());

        int i = 0;

        while(i < n && a[0] == a[i]) {
            c.push_back(a[i]);
            i++;
        }

        while(i < n) {
            b.push_back(a[i]);
            i++;
        }

        if(b.size() == 0 || c.size() == 0) {
            cout << -1 << endl;
            continue;
        }

        cout << b.size() << " " << c.size() << endl;

        for(int d: b) cout << d << " ";
        cout << endl;
        for(int d: c) cout << d << " ";
        cout << endl;

    }

    return 0;

}