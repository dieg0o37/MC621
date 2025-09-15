#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)
#define MOD (ll)1e9 + 7
#define MAX (int)1e6


// solve(x) p/ x <= 0 = 0 
// solve(1) = 1
// solve(2) = 2
// solve(3) = 4
// solve(4) = 8
// solve(5) = 16
// solve(6) = 32
// solve(x) = solve(x - 1) + solve(x - 2) + solve (x - 3) + ... + solve(x - 6)


ll calculado[MAX];
ll solve(int n) {
    if (calculado[n - 1]) return calculado[n - 1];
    if (n <= 0) { return 0; }
    if (n == 1) { return 1; }
    if (n == 2) {return 2;}
    if (n == 3) {return 4;}
    if (n == 4) {return 8;}
    if (n == 5) {return 16;}
    if (n == 6) {return 32;}
    ll resultado = solve(n - 1) + solve(n - 2) + solve(n - 3) + solve(n - 4) + solve(n - 5) + solve(n - 6);
    resultado %= MOD;
    calculado[n - 1] = resultado;
    return resultado;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill(calculado, calculado + MAX, 0);
    int n;
    cin >> n;
    cout << solve(n) << "\n";

    return 0;
}
