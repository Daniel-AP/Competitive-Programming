#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    bool all_zero = true;
    for(char c : s) {
        if(c != '0') {
            all_zero = false;
            break;
        }
    }
    if(all_zero) {
        cout << "Alice\n";
        return;
    }

    if(k == 1) {
        cout << "Alice\n";
        return;
    }

    bool has_k_ones = false;
    int cnt = 0;
    for(char c : s) {
        if(c == '1') {
            cnt++;
            if(cnt >= k) {
                has_k_ones = true;
                break;
            }
        } else {
            cnt = 0;
        }
    }

    if(!has_k_ones) {
        cout << "Alice\n";
        return;
    }

    if(k == n) {
        cout << "Alice\n";
        return;
    }

    cout << "Bob\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;
}