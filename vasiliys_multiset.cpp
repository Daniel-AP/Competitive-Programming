#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

struct Trie {
    struct Node {
        array<int, 2> next;
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

    void insert(int s) {
        int node = 0;
        trie[node].cnt++;

        for(int i = 32; i >= 0; i--) {
            int x = (s>>i)&1;

            if (trie[node].next[x] == -1) {
                trie[node].next[x] = trie.size();
                trie.emplace_back();
            }

            node = trie[node].next[x];
            trie[node].cnt++;
        }

        trie[node].end++;
    }

    int count(int s) {
        int node = 0;

        for(int i = 32; i >= 0; i--) {
            int x = (s>>i)&1;

            if (trie[node].next[x] == -1)
                return 0;

            node = trie[node].next[x];
        }

        return trie[node].end;
    }

    bool contains(int s) {
        return count(s) > 0;
    }

    int count_prefix(int s) {
        int node = 0;

        for(int i = 32; i >= 0; i--) {
            int x = (s>>i)&1;

            if (trie[node].next[x] == -1)
                return 0;

            node = trie[node].next[x];
        }

        return trie[node].cnt;
    }

    bool erase(int s) {
        if (!contains(s))
            return false;

        int node = 0;
        trie[node].cnt--;

        for(int i = 32; i >= 0; i--) {
            node = trie[node].next[(s>>i)&1];
            trie[node].cnt--;
        }

        trie[node].end--;
        return true;
    }

    int query(int s) {
        int node = 0, ans = 0;
        for(int i = 32; i >= 0; i--) {
            int x = (s>>i)&1;
            if(trie[node].next[x^1] != -1 && trie[trie[node].next[x^1]].cnt > 0) {
                ans |= (1LL<<i);
                node = trie[node].next[x^1];
            } else {
                node = trie[node].next[x];
            }
        }
        return ans;
    }

};

void solve() {

    int q; cin >> q;

    Trie trie;
    trie.insert(0);

    while(q--) {
        char op; cin >> op;
        int x; cin >> x;
        if(op == '+') {
            trie.insert(x);
        } else if(op == '-') {
            trie.erase(x);
        } else {
            cout << trie.query(x) << '\n';
        }
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}