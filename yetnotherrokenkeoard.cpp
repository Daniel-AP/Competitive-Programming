#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    string s; cin >> s;
    int n = s.length();

    vector<int> s1, s2;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'b') {
            if(!s1.size()) continue;
            s1.pop_back();
        } else if(s[i] == 'B') {
            if(!s2.size()) continue;
            s2.pop_back();
        } else if(s[i] >= 65 && s[i] <= 90) {
            s2.push_back(i);
        } else if(s[i] >= 97 && s[i] <= 122) {
            s1.push_back(i);
        }
    }

    int i = 0, j = 0;

    while(i < s1.size() && j < s2.size()) {
        if(s1[i] < s2[j]) {
            cout << s[s1[i]];
            i++;
        } else {
            cout << s[s2[j]];
            j++;
        }
    }

    while(i < s1.size()) {
        cout << s[s1[i]];
        i++;
    }

    while(j < s2.size()) {
        cout << s[s2[j]];
        j++;
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}