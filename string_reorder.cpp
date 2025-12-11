#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";
 
void solve() {
 
    string s; cin >> s;
    int n = s.length();
 
    vector<int> freq(26);
    for(char x: s) freq[x-'A']++;
 
    string ans;

    for(int i = 0; i < 26; i++) {
        if(freq[i] > 0) {
            ans += char(i+'A');
            freq[i]--;
            break;
        }
    }
 
    for(int i = 1; i < n; i++) {
 
        bool found = false;

        int sm = accumulate(freq.begin(), freq.end(), 0);
        int mx = 0, mx1 = 0, mx2 = 0;

        for(int x : freq) {
            if(x > mx1) {
                mx2 = mx1;
                mx1 = x;
            } else if(x > mx2) {
                mx2 = x;
            }
        }
 
        for(int j = 0; j < 26; j++) {

            int mx = 0;

            if(freq[j] == mx1) mx = max(mx1-1, mx2);
            else mx = mx1;
            
            if(char(j+'A') != ans.back() && freq[j] > 0 && mx <= sm/2) {
                ans += char(j+'A');
                freq[j]--;
                found = true;
                break;
            }
        }
 
        if(!found) {
            cout << -1 << '\n';
            return;
        }
 
    }
 
    cout << ans << '\n';
    
}
 
signed main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    int t; t = 1;
 
    while(t--) solve();
 
    return 0;
 
}