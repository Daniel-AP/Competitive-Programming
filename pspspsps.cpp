#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    int cnt_p = count(s.begin(), s.end(), 'p');
    int cnt_s = count(s.begin(), s.end(), 's');

    bool p_before = false;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'p') p_before = true;
        if(s[i] == 's' && p_before) {
            cout << "NO" << endl;
            return;
        }
    }

    if(cnt_p == 0 || cnt_s == 0) {
        cout << "YES" << endl;
        return;
    }

    if(s[0] == '.' && s.back() == '.') {
        cout << "NO" << endl;
        return;
    }

    if(cnt_p > 1 && cnt_s > 1) {
        cout << "NO" << endl;
        return;
    }

    if((s[0] == '.' && cnt_p > 1) || (s.back() == '.' && cnt_s > 1)) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}