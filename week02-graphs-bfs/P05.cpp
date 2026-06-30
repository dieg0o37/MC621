#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define MOD (ll)(1e9 + 9)
/*

Tn = Tn - 1 + Tn- 2 + Tn-3

T4  =       | 1 1 1 |   | 0 | T1
T3          | 0 0 1 |   | 1 | T2
T2          | 0 1 0 |   | 2 | T3

Tn      =   | 1 1 1 |^(n - 3) | 0 |
Tn-1        | 0 0 1 |         | 1 |
Tn-2        | 0 1 0 |         | 2 |

*/

typedef struct matrix {
    ll mat[3][3] {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    ll mat_def[3][3] {
        {1, 1, 1},
        {1, 0, 0},
        {0, 1, 0}
    };
} matrix;

matrix mult_m(const matrix& A, const matrix& B) {
    matrix C;
    F(i, 3) {
        F(k, 3) {
            ll val_a = A.mat[i][k];
            if (val_a == 0) continue;
            F(j, 3) {
                ll val_b = B.mat[k][j];
                C.mat[i][j] = (C.mat[i][j] + val_a*val_b)%MOD;
            }
        }
    }
    return C;
}


matrix exp_rapida(const matrix& A, ll n) {
    if (n == 0) {
        matrix I;
        I.mat[0][0] = 1;
        I.mat[1][1] = 1;
        I.mat[2][2] = 1;
        return I;
    } else if (n == 1) {
        return A;
    } else if (n % 2 == 0) {
        matrix aux = exp_rapida(A, n/2);
        return mult_m(aux, aux);
    } else {
        matrix aux = exp_rapida(A, (n - 1)/2);
        return mult_m(mult_m(aux, aux), A);
    }

}


bool solve() {
    // Your code here
    ll n;
    cin >> n;
    if (n == 0) return false;
    if (n == 1) {
        cout << 0 << "\n";
        return true;
    } else if (n == 2) {
        cout << 1 << "\n";
        return true;
    } else if (n == 3) {
        cout << 2 << "\n";
        return true;
    }
    matrix M;
    F(i, 3) {
        F(j , 3) {
            M.mat[i][j] = M.mat_def[i][j];
        }
    }
    M = exp_rapida(M, n - 3);
    ll ans = (M.mat[0][1] + 2*M.mat[0][0])%MOD;
    cout << ans << "\n";
    return true;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool run = true;
    while (run) 
        run = solve();


    return 0;
}
