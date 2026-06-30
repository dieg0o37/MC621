#include  <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, a, b) for(int i = a; i < b; i++)
#define Fr(i, a, b) for(int i = a; i >=b; i--)
typedef complex<double> P;
#define Y imag() 
#define X real()
#define epsilon 1e17

ll plt(const P& p1, const P& p2) {
    double val = (conj(p1)*p2).Y;
    if (val == 0) return 0;
    return (val < 0) ? -1 : 1;
}

ll na_linha(const P& p1, const P& p2, const P& p3) {
    return ((p3.X <= max(p1.X, p2.X)) && (p3.X >= min(p1.X, p2.X)) &&
            (p3.Y <= max(p1.Y, p2.Y)) && (p3.Y >= min(p1.Y, p2.Y)));
}

void solve() {
    
    P a1, b1;
    P a2, b2;
    double x, y;
    cin >> x >> y;
    a1 = {x, y};
    cin >> x >> y;
    b1 = {x, y};
    cin >> x >> y;
    a2 = {x, y};
    cin >> x >> y;
    b2 = {x, y};

    double A1 = a1.Y - b1.Y;
    double B1 = b1.X - a1.X;
    double C1 = a1.X*A1 + a1.Y*B1;

    double A2 = a2.Y - b2.Y;
    double B2 = b2.X - a2.X;
    double C2 = a2.X*A2 + a2.Y*B2;

    double det = A1*B2 - B1*A2;
    double detx = C1*B2 - B1*C2;
    double dety = A1*C2 - C1*A2;

    if (det == 0) {
        if (detx == 0 && dety == 0) {
            cout << "LINE" << "\n";
        } else {
            cout << "NONE" << "\n";
        }
    } else {
        double x = detx/det;
        double y = dety/det;
        cout << "POINT ";
        cout << fixed << setprecision(2)  << x << " " << y << "\n";
    }

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "INTERSECTING LINES OUTPUT" << "\n";
    ll t;
    cin >> t;
    while(t--)
        solve();
    cout << "END OF OUTPUT" << "\n";
    return 0;
}
