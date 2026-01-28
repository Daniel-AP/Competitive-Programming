#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int k; cin >> k;
    string s; cin >> s;

    int n = s.length();
    
    char prev = s[0];
    int cnt = 1, ans = 0;
    
    if(k == 2) {
        int d1 = 0, d2 = 0;
        for(int i = 0; i < n; i++) {
            if(i%2 == 0 && s[i] == '0') d1++;
            if(i%2 == 1 && s[i] == '1') d1++;
        }
        for(int i = 0; i < n; i++) {
            if(i%2 == 0 && s[i] == '1') d2++;
            if(i%2 == 1 && s[i] == '0') d2++;
        }
        cout << min(d1, d2) << ' ';
        if(d1 < d2) {
            for(int i = 0; i < n; i++) {
                if(i%2 == 0) cout << 1;
                if(i%2 == 1) cout << 0;
            }
        } else {
            for(int i = 0; i < n; i++) {
                if(i%2 == 1) cout << 1;
                if(i%2 == 0) cout << 0;
            }
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i < n; i++) {
        if(s[i] == prev) {
            cnt++;
        } else {
            if(cnt >= k) {
                for(int j = i-cnt+k-1; j < i; j += k) {
                    if(j == i-1) {
                        s[j-1] = '0'+'1'-s[j];
                        ans++;
                        cnt = 1;
                        break;
                    }
                    s[j] = '0'+'1'-s[j];
                    ans++;
                }
            }
            cnt = 1;
            prev = s[i];
        }
    }

    if(cnt >= k) {
        for(int j = n-cnt+k-1; j < n; j += k) {
            if(j == n-1) {
                s[j-1] = '0'+'1'-s[j];
                ans++;
                cnt = 1;
                break;
            }
            s[j] = '0'+'1'-s[j];
            ans++;
        }
    }

    cout << ans << ' ' << s << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}