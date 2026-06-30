#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1e9 + 7;

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
matrix exp_rapida(ll n, const matrix& M, ll k) {
    matrix aux;
    if (k == 1) {
        return M;
    }
    else if (k == 0) {
        matrix I;
        I.initialize_I(n);
        return I;
    } else if (k % 2 == 0) {
        aux = exp_rapida(n, M, k/2);
        return mult_m(aux, aux, n);
    } else {
        aux = exp_rapida(n, M, (k - 1)/2);
        return mult_m(mult_m(M, aux, n), aux, n);
    }

}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    matrix M; 
    pair<ll, ll> edge;
    M.initialize(n);
    F(i, m) {
        cin >> edge.first >> edge.second;
        M.adj[edge.first - 1][edge.second - 1]++;
    }
    matrix new_M = exp_rapida(n, M, k);
    cout << new_M.adj[0][n - 1] << "\n";
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
