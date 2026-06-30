#include  <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, a, b) for(int i = a; i < b; i++)
#define Fr(i, a, b) for(int i = a; i >=b; i--)
typedef complex<ll> P;
typedef complex<double> Pd;
#define Y imag() 
#define X real()
ll xProdD (Pd a, Pd b) {return (conj(a)*b).Y;}
ll xProd (P a, P b) {return (conj(a)*b).Y;}
ll plt(const P& p1, const P& p2) {
    ll val = (conj(p1)*p2).Y;
    return (val == 0) ? 0 : (val < 0) ? -1 : 1;}
double pltD(const Pd& p1, const Pd& p2) {
    double val = (conj(p1)*p2).Y;
    return (val == 0) ? 0 : (val < 0) ? -1 : 1;}

double Euclid_dist(Pd a, Pd b) {
    return sqrt(pow((a.X - b.X), 2) + pow((a.Y - b.Y), 2));
}

Pd find_intersec(P a1, P b1, P a2, P b2, bool *found) {
    ll A1 = a1.Y - b1.Y;
    ll B1 = b1.X - a1.X;
    ll C1 = a1.X*A1 + a1.Y*B1;

    ll A2 = a2.Y - b2.Y;
    ll B2 = b2.X - a2.X;
    ll C2 = a2.X*A2 + a2.Y*B2;

    ll det = A1*B2 - B1*A2;
    ll detx = C1*B2 - B1*C2;
    ll dety = A1*C2 - C1*A2;

    if (det == 0) {
        *found = false;
        Pd p = {0, 0};
        return p;
    } else {
        double x = detx/det;
        double y = dety/det;
        Pd p = {x, y};
        *found = true;
        return p;
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<pair<P, P>> v(n);
    F(i, 0, n) {
        P a, b;
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a = {x1, y1};
        b = {x2, y2};
        v[i] = make_pair(a, b);
    }
    double max_p = 0.000;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto r1 = v[i];
            auto r2 = v[j];
            bool found1 = false;
            Pd inc1 = find_intersec(r1.first, r1.second, r2.first, r2.second, &found1); 
            if (found1) {
                for (int k = 0; k < n; ++k) { 
                    if (k != i && k != j){
                        auto r3 = v[k];
                        bool found2 = false;
                        Pd inc2 = find_intersec(r1.first, r1.second, r3.first, r3.second, &found2); 
                        if (found2) {
                            bool found3 = false;
                            Pd inc3 = find_intersec(r2.first, r2.second, r3.first, r3.second, &found3); 
                            if (found3) {
                                double ab = Euclid_dist(inc1, inc2);
                                double bc = Euclid_dist(inc2, inc3);
                                double ca = Euclid_dist(inc3, inc1);
                                max_p = max(max_p, (ab + bc + ca));
                            } else {
                                continue;
                            }
                        } else {
                            continue;
                        }
                       
                    }
                }
            }else {
                continue;
            }
        }
    }
    if (max_p == 0.000) {
        cout << "no triangle" << "\n";
    } else {
        cout << fixed << setprecision(10) << max_p << "\n";
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
