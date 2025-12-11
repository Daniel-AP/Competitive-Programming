#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int length = s.length();

    sort(s.begin(), s.end());

    cout << string(length-s.find(s[length-1]), s[length-1]) << endl;

    return 0;

}