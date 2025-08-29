#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1e9;

#define F(i, n) for (int i = 0; i < n; i++)

typedef struct matrix {
    vector<vector<ll>> adj;

    void initialize(ll n) {
        adj.resize(n);
        for (int i = 0; i < n; i++) {
            adj[i].resize(n);
            fill(adj[i].begin(), adj[i].end(), 0);
        }
    }
    void initialize_I(ll n) {
        adj.resize(n);
        for (int i = 0; i < n; i++) {
            adj[i].resize(n);
            fill(adj[i].begin(), adj[i].end(), 0);
            adj[i][i] = 1;
        }
    }
    void print(ll n) {
        F(i, n) {
            F(j, n) {
                cout << adj[i][j] << (j == n - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }
} matrix;

matrix mult_m(const matrix& A, const matrix& B, ll n) {
    matrix C;
    C.initialize(n);
    F(i, n) {
        F(k, n) {
            ll valA = A.adj[i][k];
            if (valA == 0) continue; 
            F(j, n) {
                ll valB = B.adj[k][j];
                C.adj[i][j] = (C.adj[i][j] + valA * valB) % MOD;
            }
        }
    }
    return C;
}


matrix mpow(matrix A, ll exp, ll n) {
    matrix res;
    res.initialize_I(n);
    while (exp > 0) { 
        if (exp & 1) res = mult_m(res, A, n);
        A = mult_m(A, A, n);
        exp >>= 1;
    }
    return res;
}


void solve() {
    ll ord;
    cin >> ord;
    ll init_vals[ord];
    ll n;
    matrix M;
    M.initialize(ord);
    F(i, ord) {
        cin >> init_vals[i];
    }
    ll j = 0;
    F(i, ord - 1) {
        cin >> M.adj[0][i];
        M.adj[i + 1][j++] = 1;
    }
    cin >> M.adj[0][ord - 1];
    // M.print(ord);
    cin >> n;
    if (n <= ord) {
        cout << init_vals[n - 1] << "\n";
        return;
    }
    M = mpow(M, n - ord, ord);
    ll ans = 0;
    for (int i = ord - 1; i >=0; i--) {
        ans = (ans + M.adj[0][i]*init_vals[ord - i - 1])%MOD;
    }
    cout << ans << "\n";
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
