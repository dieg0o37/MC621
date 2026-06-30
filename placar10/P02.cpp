#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)

struct Suffix {
    int index; 
    int rank[2]; 
};

int compare_suf(const Suffix& a, const Suffix& b) {
    if (a.rank[0] == b.rank[0]) {
        return a.rank[1] < b.rank[1];
    }
    return a.rank[0] < b.rank[0];
}
vector<int> buildSuffixArray(const string& txt) {
    int n = txt.size();
    vector<Suffix> s(n);
    for (int i = 0; i < n; i++) {
        s[i].index = i;
        s[i].rank[0] = txt[i];
        s[i].rank[1] = (i + 1 < n) ? txt[i + 1] : -1;
    }
    sort(s.begin(), s.end(), compare_suf); // sorting pra k = 2
    vector<int> newRank(n);

    for (int k = 4; k < 2 * n; k *= 2) {
        int rank = 0;
        int prev_rank = s[0].rank[0];
        s[0].rank[0] = rank;
        newRank[s[0].index] = 0;
        for (int i = 1; i < n; i++) {
            if (s[i].rank[0] == prev_rank && s[i].rank[1] == s[i-1].rank[1]) {
                prev_rank = s[i].rank[0];
                s[i].rank[0] = rank;
            } else {
                prev_rank = s[i].rank[0];
                s[i].rank[0] = ++rank;
            }
            newRank[s[i].index] = s[i].rank[0];
        }

        for (int i = 0; i < n; i++) {
            int next_index = s[i].index + k / 2;
            s[i].rank[0] = newRank[s[i].index];
            s[i].rank[1] = (next_index < n) ? newRank[next_index] : -1;
        }

        sort(s.begin(), s.end(), compare_suf);
    }

    vector<int> suffixArr(n);
    for (int i = 0; i < n; i++) {
        suffixArr[i] = s[i].index;
    }

    return suffixArr;
}

vector<ll> build_LCP(const vector<int>& SA, const vector<int>& rank, const string& s) {
    ll h = 0;
    int n = s.size();
    vector<ll> LCP(n);
    F(i, n) {
        int r = rank[i];
        if (r == 0) {
            LCP[0] = 0;
            h = 0;
            continue;
        }
        int j = SA[r - 1];
        while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
        LCP[r] = h;
        if (h > 0) h--;
    }
    return LCP;
}


void solve() {
    string S;
    cin >> S;
    ll k;
    cin >> k;
    ll ns = S.size();
    auto SA = buildSuffixArray(S);
    vector<int> rank(ns);
    F(i, ns) {
        rank[SA[i]] = i;
    }
    auto lcp = build_LCP(SA, rank, S);
    ll j = 0;
    F(i, ns) {
        if (j == k - 1) {
            break;
        }
    }

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    ll t;
    cin >> t;
    while(t--)
    */
        solve();

    return 0;
}
