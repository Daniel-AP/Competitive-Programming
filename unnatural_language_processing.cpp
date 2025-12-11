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

        string w, ans;
        cin >> w;

        unordered_set<char> vs = {'a', 'e'};
        unordered_set<char> cs = {'b', 'c', 'd'};

        int i = 1;

        for(; i < n; i+=2) {
            ans += w.substr(i-1, 2);
            if(i+1 < n && cs.count(w[min(i+2, n-1)])) {
                ans += w[i+1];
                i++;
            }
            if(i+2 < n) ans += '.';
        }

        cout << ans << endl;

    }

    return 0;

}