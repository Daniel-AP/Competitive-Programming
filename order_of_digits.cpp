#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

struct Trie {
    struct Node {
        array<int, 10> next;
        int cnt = 0;       // strings passing through this node
        int end = 0;       // strings ending at this node

        Node() {
            next.fill(-1);
        }
    };

    vector<Node> trie;

    Trie() {
        trie.emplace_back();  // root
    }

    void insert(const string& s) {
        int node = 0;
        trie[node].cnt++;

        for (char c : s) {
            int x = c - '0';

            if (trie[node].next[x] == -1) {
                trie[node].next[x] = trie.size();
                trie.emplace_back();
            }

            node = trie[node].next[x];
            trie[node].cnt++;
        }

        trie[node].end++;
    }

    int count(const string& s) {
        int node = 0;

        for (char c : s) {
            int x = c - '0';

            if (trie[node].next[x] == -1)
                return 0;

            node = trie[node].next[x];
        }

        return trie[node].end;
    }

    bool contains(const string& s) {
        return count(s) > 0;
    }

    int count_prefix(const string& s) {
        int node = 0;

        for (char c : s) {
            int x = c - '0';

            if (trie[node].next[x] == -1)
                return 0;

            node = trie[node].next[x];
        }

        return trie[node].cnt;
    }

    bool erase(const string& s) {
        if (!contains(s))
            return false;

        int node = 0;
        trie[node].cnt--;

        for (char c : s) {
            node = trie[node].next[c - '0'];
            trie[node].cnt--;
        }

        trie[node].end--;
        return true;
    }

    int query(const string& s, const vector<char>& p) {
        
        int node = 0, ans = 0;

        for(char c: s) {
            int x = c-'0';
            for(int i = 0; i < 10; i++) {
                if(p[i] == c) break;
                if(trie[node].next[p[i]-'0'] != -1) ans += trie[trie[node].next[p[i]-'0']].cnt;
            }
            if (trie[node].next[x] == -1) break;
            node = trie[node].next[x];
        }

        return ans;

    }

};

void solve() {

    int n; cin >> n;

    Trie trie;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        reverse(all(s));
        while(s.length() < 20) s += "0";
        reverse(all(s));
        trie.insert(s);
    }

    int q; cin >> q;

    for(int i = 0; i < q; i++) {
        vector<char> p(10);
        for(int j = 0; j < 10; j++) {
            int x; cin >> x;
            p[j] = char(x+'0');
        }
        string x; cin >> x;
        reverse(all(x));
        while(x.length() < 20) x += "0";
        reverse(all(x));
        cout << trie.query(x, p) << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}