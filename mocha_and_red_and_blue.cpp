#include<bits/stdc++.h>
using namespace std;
 
int main() {

    int t;
    cin>>t;

    while(t--) {

        int n;
        cin>>n;

        string s;
        cin >> s;

        int start = n-1;

        for(int i = 1; i < n; i++) {
            if(s[i-1] != '?') {
                start = min(start, i-1);
                if(s[i] == '?') s[i] = s[i-1] == 'B' ? 'R' : 'B';
            }
        }

        if(s[start] == '?') s[start] = 'B';

        for(int i = start-1; i >= 0; i--) {
            s[i] = s[i+1] == 'B' ? 'R' : 'B';
        }

        cout << s << endl;

    }

    return 0;

}