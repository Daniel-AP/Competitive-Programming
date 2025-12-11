#include <bits/stdc++.h>
using namespace std;

void solve() {

    int q;
    cin >> q;

    while(q--) {

        string s, t;
        cin >> s >> t;

        int n = s.length();
        int m = t.length();

        string candidate_s;
        string candidate_t;

        for(int i = 0; i < lcm(n, m)/n; i++) candidate_s += s;
        for(int i = 0; i < lcm(n, m)/m; i++) candidate_t += t;

        if(candidate_s == candidate_t) {
            cout << candidate_s << endl;
        } else {
            cout << -1 << endl;
        }

    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;

}