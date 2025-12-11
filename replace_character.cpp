#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        string s; cin >> s;

        unordered_map<char, int> counter;
        for(int i = 0; i < n; i++) {
            counter[s[i]]++;
        }

        unordered_set<char> k(s.begin(), s.end());
        vector<char> unique(k.begin(), k.end());

        sort(unique.begin(), unique.end(), [&](char a, char b) {
            return counter[a] > counter[b];
        });

        int i = s.find(unique[unique.size()-1]);

        s[i] = unique[0];

        cout << s << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}