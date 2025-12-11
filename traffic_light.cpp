#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

        int n;
        char c;
        cin >> n >> c;

        string s;
        cin >> s;

        int prev_g = -1;
        int counter = 0;
        int max_secs = 0;

        bool counting = false;

        if(c == 'g') {
            cout << 0 << endl;
            continue;
        }

        for(int i = 0; i < n; i++) {

            if(counting) counter++;

            if(s[i] == 'g' && prev_g == -1) prev_g = i;
            if(s[i] == 'g') {
                max_secs = max(max_secs, counter);
                counter = 0;
                counting = false;
            }

            if(s[i] == c) counting = true;

        }

        if(counting) max_secs = max(max_secs, counter+prev_g+1);

        cout << max_secs << endl;
        
    }

    return 0;    

}