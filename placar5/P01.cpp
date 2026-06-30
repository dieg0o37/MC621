#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)

/*
2ia0 + (i - 1)i = 2*x
i(2a0 + i - 1) = 2*x
d = 2a0 + i - 1
d - i = ímpar => d ímpar e i é par
OU               i é impar e d é par

achar fatoração de 2 termos (d, i) de 2*x tal que d*i = 2*x e i é ímpar => achar o número de divisores ímpar de 2*x
12
24
(3, 1) temos então 4 possíveis seq.


*/
void solve() {
    ll x;
    cin >> x;
    ll i = 3;
    ll result = 2, r_temp = 0;
    while (x%2 == 0) x /= 2;
    while (i*i <= x) {
        if (x %i == 0) {
            r_temp++;
            while (x%i == 0) {
                x /= i;
                r_temp++;
            }
            result *= r_temp;
            r_temp = 0;
        }
        i += 2;
    }
    if (x > 1) result *= 2;
    cout << result << "\n";
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
