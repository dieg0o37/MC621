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

void solve() {
    ll N;
    cin >> N;
    vector<ll> r(N);
    F(i, 0, N) {
        cin >> r[i];
    }
    sort(r.begin(), r.end());
    double d_min = INFINITY;

    do {
       bool left = false;
        double d = 0.0;
        double dt;
        F(i, 0, N - 1) {
            dt = sqrt(pow(r[i] + r[i + 1], 2) - pow(r[i] - r[i + 1], 2));
            d += dt;
        }
        d_min = min(d_min, d);
    }  while (next_permutation(r.begin(), r.end()));
    cout << fixed << setprecision(10) << d_min << "\n";
    
    
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
