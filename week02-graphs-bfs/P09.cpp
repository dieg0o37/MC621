#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)

/*
T0 = 1
T1 = 1
...
...
Tn = 1 + Tn-1 + Tn-2
| Tn   | = | 1 | + | 1 1 || Tn-1 |
| Tn-1 |   | 0 |   | 1 0 || Tn-2 |


A = | 1 1 |
    | 1 0 |
(A - I)^(-1) = A
S = A + A^2 + ... + A^(n - 2) = (A^(n - 1) - A)A
| Tn   | = | 1 | + (A^(n - 1) - A)A| 1 | + A^(n - 1)| 1 |
| Tn-1 |   | 0 |                   | 0 |            | 1 | 

*/

typedef struct matrix {
    ll mat_d[2][2] {
        {0, 0},
        {0, 0}
    };
} matrix;


matrix mult_m(const matrix& A, const matrix& B, ll b) {
    matrix C;
    F(i, 2) {
        F(k, 2) {
            ll val_a = A.mat_d[i][k];
            if (val_a == 0) continue;
            F(j, 2) {
                ll val_b = B.mat_d[k][j];
                C.mat_d[i][j] = (C.mat_d[i][j] + (val_a*val_b)%b)%b;
            }
        }
    }
    return C;
}
matrix exp_rapida(ll n, ll b, const matrix& M) {
    if (n == 0) {
        matrix I;
        I.mat_d[0][0] = 1;
        I.mat_d[1][1] = 1;
        return I;
    } else if (n == 1) {
        return M;
    } else if (n % 2 == 0) {
        matrix aux = exp_rapida(n/2, b, M);
        return mult_m(aux, aux, b);
    } else {
        matrix aux = exp_rapida((n - 1)/2, b, M);
        return mult_m(mult_m(aux, aux, b), M, b);
    }
}

bool solve(ll t) {
    ll n, b;
    cin >> n >> b;
    if (n == 0 && b == 0) {
        return false;
    } 
    else if (n == 0 || n == 1) {
        cout << "Case " << t << ": " << n << " " << b << " " << (1)%b << "\n";
        return true;
    }

    matrix ini_m;
    ini_m.mat_d[0][0] = 1;
    ini_m.mat_d[1][0] = 1;
    ini_m.mat_d[0][1] = 1;

    matrix m_next = exp_rapida(n - 1, b, ini_m);
    
    ll ans = 0;
    ans =  (ans + m_next.mat_d[0][0] + m_next.mat_d[0][1])%b;

    m_next.mat_d[0][0] =  (m_next.mat_d[0][0] - 1 + b)%b;
    m_next.mat_d[0][1] = (m_next.mat_d[0][1] - 1 + b)%b;
    m_next.mat_d[1][0]= (m_next.mat_d[1][0] - 1 + b)%b;;
    m_next = mult_m(m_next, ini_m, b);

    ans = (ans + m_next.mat_d[0][0] + 1)%b;

    cout << "Case " << t << ": " << n << " " << b << " " << (ans)%b << "\n";
    return true;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    bool run = true;
    while (run) {
        run = solve(t++);
    }
    return 0;
}
