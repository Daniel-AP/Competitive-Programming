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

        vector<int> cream(n);
        vector<bool> drenched(n);

        for(int i = 0; i < n; i++) cin >> cream[i];

        vector<int> dp(n);

        dp[n-1] = cream[n-1]-1;
        drenched[n-1] = dp[n-1] >= 0;

        for(int i = n-2; i >= 0; i--) {

            dp[i] = max(cream[i], dp[i+1])-1;
            drenched[i] = dp[i] >= 0;

        }

        for(bool d: drenched) cout << d << " ";
        cout << endl;

    }

    return 0;

}