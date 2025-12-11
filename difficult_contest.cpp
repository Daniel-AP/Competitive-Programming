#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    string s; cin >> s;
    
    vector<int> a(3);

    for(int i = 0; i < s.length(); i++) {
        if(s[i] != 'F' && s[i] != 'T' && s[i] != 'N') cout << s[i];
        if(s[i] == 'F') a[0]++;
        else if(s[i] == 'T') a[1]++;
        else if(s[i] == 'N') a[2]++;
    }

    cout << string(a[1], 'T');
    cout << string(a[2], 'N');
    cout << string(a[0], 'F');

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}