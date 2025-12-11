#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;

        while(q--) {

            int l, r;
            cin >> l >> r;
            l--;
            r--;
            
            if(s.find(s[l]) < l || s.rfind(s[r]) > r) cout << "YES" << endl;
            else cout << "NO" << endl;
            
        }

    }

    return 0;

}