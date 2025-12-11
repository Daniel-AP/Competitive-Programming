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

        bool can = false;

        vector<int> sticks(n);
        for(int i = 0; i < n; i++) cin >> sticks[i];

        sort(sticks.begin(), sticks.end());

        for(int i = 0; i < n-1; i++) {
            if(sticks[i] == sticks[i+1]) {

                long long a(1e9), b(0), c(sticks[i]);
                int prev = i == 0 ? 2 : 0;

                for(int j = prev+1; j < n; j++) {
                    if(j == i || j == i+1) continue;
                    if(sticks[j]-sticks[prev] < a-b) {
                        a = sticks[j];
                        b = sticks[prev];
                    }
                    prev = j;
                }

                bool possible = 4*c*c > (a-b)*(a-b);
                if(possible) {
                    cout << c << " " << c << " " << a << " " << b;
                    can = true;
                    break;
                }

            }
        }

        if(!can) cout << -1;
        cout << endl;

    }

    return 0;

}