#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e18

char vowels[] = {'a', 'e', 'i', 'o', 'u'};

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    int q; cin >> q;

    while(q--) {

        int l, r; cin >> l >> r;
        l--; r--;
        
        unordered_map<char, vector<int>> mp;

        for(int i = l; i <= r; i++) {
            mp[s[i]].push_back(i);
        }

        int pos = -1;

        bool found = false;

        for(char v: vowels) {
            if(mp[v].empty()) {
                cout << 1 << "\n";
                found = true;
                break;
            }
        }

        if(found) continue;

        for(char v: vowels) {
            if(mp[v][0] > pos) {
                pos = mp[v][0];
            }
        }

        int cnt = 1;
        
        while(!found) {
            int curr = -1;
            cnt++;
            for(char v: vowels) {
                int i = upper_bound(mp[v].begin(), mp[v].end(), pos)-mp[v].begin();
                if(i == mp[v].size()) {
                    cout << cnt << "\n";
                    found = true;
                    break;
                } else if(mp[v][i] > curr) {
                    curr = mp[v][i];
                }
            }
            pos = curr;
        }

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}