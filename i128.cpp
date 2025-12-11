#include <bits/stdc++.h>
using namespace std;

__int128_t read() {
    string s;
    cin >> s;
    __int128_t x = 0;
    bool neg = false;
    size_t i = 0;
    if (s[0] == '-') { neg = true; i = 1; }
    for (; i < s.size(); ++i) {
        x = x * 10 + (s[i] - '0');
    }
    return neg ? -x : x;
}

void print(__int128_t x) {
    if (x == 0) {
        cout << '0';
        return;
    }
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    string s;
    while (x > 0) {
        s.push_back(char('0' + x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}