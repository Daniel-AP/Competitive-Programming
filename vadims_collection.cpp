#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    string s; cin >> s;
    unordered_map<char, int> freq;

    for(int i = 0; i < 10; i++) {
        freq[s[i]]++;
    }

    for(int i = 1; i <= 10; i++) {
        for(int j = 10-i; j < 10; j++) {
            if(freq['0'+j] > 0) {
                cout << j;
                freq['0'+j]--;
                break;
            }
        }
    }

    cout << endl;
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}