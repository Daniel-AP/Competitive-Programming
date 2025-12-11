#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

string xr(string a, string b) {

    int na = a.size();
    int nb = b.size();

    int n = max(na, nb);
    string result(n, '0');

    for(int i = 0; i < n; i++) {

        char ca = (i < na ? a[na - 1 - i] : '0');
        char cb = (i < nb ? b[nb - 1 - i] : '0');

        if(ca != cb) {
            result[n - 1 - i] = '1';
        }

    }

    return result;
}

void solve() {

    string s; cin >> s;
    int n = s.length();

    if(count(s.begin(), s.end(), '1') == n) {
        cout << 1 << " " << 1 << " " << 1 << " " << n << "\n";
        return;
    }

    int idx = find(s.begin(), s.end(), '0')-s.begin();
    int p = n-idx;

    string mx = xr(s, "0");
    int l = idx+1, r = idx+1;

    for(int i = 0; i+p-1 < n; i++) {
        string o = s.substr(i, p);   
        if(xr(s, o) > mx) {
            mx = xr(s, o);
            l = i+1; r = i+p;
        }
    }

    cout << 1 << " " << n << " " << l << " " << r << "\n";
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}