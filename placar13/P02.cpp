#include  <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, a, b) for(int i = a; i < b; i++)
#define Fr(i, a, b) for(int i = a; i >=b; i--)
typedef complex<ll> P;
typedef complex<double> Pd;
#define Y imag() 
#define X real()
double xProdD (Pd a, Pd b) {return (conj(a)*b).Y;}
ll xProd (P a, P b) {return (conj(a)*b).Y;}
ll plt(const P& p1, const P& p2) {
    ll val = (conj(p1)*p2).Y;
    return (val == 0) ? 0 : (val < 0) ? -1 : 1;}
double pltD(const Pd& p1, const Pd& p2) {
    double val = (conj(p1)*p2).Y;
    return (val == 0) ? 0 : (val < 0) ? -1 : 1;}

bool is_integer(double val) {
    const double epsilon = 1e-9; 
    return abs(val - trunc(val)) < epsilon;
}
void solve() {
    double d;
    cin >> d;
    if (is_integer(d)) {
        cout << fixed << setprecision(12) << d + 1 << "\n";
    } else {
        cout << fixed << setprecision(12) << d*sqrt(2.00) << "\n";
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
