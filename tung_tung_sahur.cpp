#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        string p; cin >> p;
        string s; cin >> s;

        vector<int> seg_p, seg_s;

        int cnt = 1;
        char prev = p[0];

        for(int i = 1; i < p.length(); i++) {
            if(p[i] == prev) cnt++;
            else {
                seg_p.push_back(cnt);
                cnt = 1;
                prev = p[i];
            }
        }

        seg_p.push_back(cnt);
        cnt = 1;
        prev = s[0];

        for(int i = 1; i < s.length(); i++) {
            if(s[i] == prev) cnt++;
            else {
                seg_s.push_back(cnt);
                cnt = 1;
                prev = s[i];
            }
        }

        seg_s.push_back(cnt);
        
        if(seg_p.size() != seg_s.size()) {
            cout << "NO" << endl;
            continue;
        }

        bool good = true;
        
        for(int i = 0; i < seg_p.size(); i++) {
            if(seg_s[i] < seg_p[i]) good = false;
            if(seg_s[i] > 2*seg_p[i]) good = false;
        }

        cout << (good && p[0] == s[0] ? "YES" : "NO") << endl;
        
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}