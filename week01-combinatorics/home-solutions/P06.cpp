#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> v;
vector<ll> seg_tree;
vector<ll> lazy;
void push_lazy(int i, int low, int high) {
    if (lazy[i]) {
        seg_tree[i] += lazy[i];
        if (low != high) {
            lazy[2*i + 1] += lazy[i];
            lazy[2*i + 2] += lazy[i];
        }
        lazy[i] = 0;
    }

}
void build(int low, int high, int i) {
    if (low == high) {
        seg_tree[i] = v[low];
        return;
    }
    int mid = (low + high)/2;
    build(low, mid, 2*i + 1);
    build(mid + 1, high, 2*i + 2);
    seg_tree[i] = min(seg_tree[2*i + 1], seg_tree[2*i + 2]);
}
ll rmq(int l, int r, int low, int high, int i) {
    push_lazy(i, low, high);
    if (low >= l && high <= r) {
        return seg_tree[i];
    }
    if (low > r || high < l || low > high) {
        return LONG_MAX;
    }
    int mid = (low + high)/2;
    ll rt_n = rmq(l, r, mid + 1, high, 2*i + 2);
    ll lf_n = rmq(l, r, low, mid, 2*i + 1);
    return min(rt_n, lf_n);
}
void inc(int l, int r, int v, int low, int high, int i) {
    push_lazy(i, low, high);
    if (low >= l && high <= r) {
        lazy[i] += v;
        push_lazy(i, low, high);
        return;
    }
    if (low > r || high < l || low > high) {
        return;
    }
    int mid = (low + high)/2;
    inc(l, r, v, mid + 1, high, 2*i + 2);
    inc(l, r, v, low, mid, 2*i + 1);
    seg_tree[i] = min(seg_tree[2*i + 1], seg_tree[2*i + 2]);
}
void solve() {
    // Your code here
    int t;
    cin >> t;
    v.resize(t);
    for (int j = 0; j < t; j++) {
        cin >> v[j];
    }

    seg_tree.resize(4*t);
    lazy.resize(4*t);
    build(0, t - 1, 0);

    int m;
    cin >> m;
    cin.ignore();

    string line;
    for (int j = 0; j < m; j ++) {
        vector<int> params;
        getline(cin, line);
        stringstream ss(line);
        int p;
        while (ss >> p) {
            params.push_back(p);
        }
        int lf = params[0];
        int rt = params[1];
        if (params.size() == 2) {
            if (lf > rt){
                ll r1 = rmq(0, rt, 0, t -1 , 0);
                ll r2 = rmq(lf, t -1, 0 , t - 1, 0);
                cout << min(r1, r2) << "\n";
            } else {
                cout << rmq(lf, rt, 0, t - 1, 0) << "\n";
            }
        } else {
            int v = params[2];
            if (lf > rt) {
                inc(0, rt, v, 0, t - 1, 0);
                inc(lf, t -1, v, 0, t - 1, 0);
            } else {
                inc(lf, rt, v, 0, t - 1, 0);
            }
        }


    }
    
    
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Uncomment the following lines to read from a file instead of stdin
    /*
    #ifndef ONLINE_JUDGE
        freopen("P06.in", "r", stdin);
    #endif
    */
    solve();

    return 0;
}
