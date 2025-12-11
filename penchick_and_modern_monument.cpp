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

        unordered_map<int, int> counter;
        int m = 0;

        for(int i = 0; i < n; i++) {

            int h;
            cin >> h;

            counter[h]++;
            m = max(m, counter[h]);
            
        }

        cout << n-m << endl;

    }

    return 0;

}