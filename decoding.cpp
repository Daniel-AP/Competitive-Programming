#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<char> ans(n);
    int median = (n-1)/2;
    int left = median-1;
    int right = median+1;

    ans[median] = s[0];

    for(int i = 1; i < n; i++) {

        if(i%2 != n%2) {
            ans[right] = s[i];
            right++;
        } else {
            ans[left] = s[i];
            left--;
        }

    }

    for(char c: ans) {
        cout << c;
    }

    return 0;

}