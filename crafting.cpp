#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;

        vector<long long> amount(n), needed(n);
        long long need = 0;
        long long extra = 1e9;

        for(int i = 0; i < n; i++) cin >> amount[i];
        for(int i = 0; i < n; i++) cin >> needed[i];

        for(int i = 0; i < n; i++) {
            if(needed[i] > amount[i]) {
                if(need > 0) {
                    need = extra+1;
                    break;
                }
                need = needed[i]-amount[i];
            } else {
                extra = min(amount[i]-needed[i], extra);
            }
        }

        cout << (need > extra ? "NO" : "YES") << endl;

    }

    return 0;
    
}