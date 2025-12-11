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

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        string ans = "YES";

        for(int i = 1; i < n; i++) {
            if(a[i]-a[i-1] > 1) {
                ans = "NO";
                break;
            }
        }

        cout << ans << endl;
        
    }

    return 0;

}