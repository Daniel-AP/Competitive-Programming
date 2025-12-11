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

        string ans = "YES";

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        for(int i = 1; i < n; i++) {
            int mn = min(a[i-1], a[i]);
            a[i-1] -= mn;
            a[i] -= mn;
            if(a[i-1] > a[i]) ans = "NO";
            if(i+1 < n && a[i] > a[i+1]) ans = "NO";
        }

        cout << ans << endl;

    }

    return 0;

}