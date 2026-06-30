#include  <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, a, b) for(int i = a; i < b; i++)
#define Fr(i, a, b) for(int i = a; i >=b; i--)
typedef complex<ll> P;
typedef complex<double> Pd;
#define Y imag() 
#define X real()
bool sort_x(Pd s1, Pd s2) {return (s1.X < s2.X);}
bool sort_y(Pd s1, Pd s2) {return (s1.Y < s2.Y);}
#define epsilon (double)1e9


ll na_linha(const P& p1, const P& p2, const P& p3) {
    return ((p3.X <= max(p1.X, p2.X)) && (p3.X >= min(p1.X, p2.X)) &&
            (p3.Y <= max(p1.Y, p2.Y)) && (p3.Y >= min(p1.Y, p2.Y)));
}

ll li(const P& a, const P& p1, const P& p2) {
    // novo sist de coordenadas
    P np1 = {p1.X - a.X, p1.Y - a.Y};
    P np2 = {p2.X - a.X, p2.Y - a.Y};
    ll dy = np1.Y - np2.Y;
    if (dy == 0) {
        if (na_linha(p1, p2, a)) {
            return -1;
        } else {
            return 0;
        }
    }

    ll dx = np1.X - np2.X;
   
    ll m = np1.X*dy - np1.Y*dx;
    if (dy < 0) m *= -1;
    
    bool o1 =(np1.Y >0);
    bool o2 = (np2.Y > 0);
    if (m < 0) {
        return 0;
    } else if (m == 0) {
        if (na_linha(p1, p2, a))
            return -1;
        else return 0;
    } else {
        if (o1 != o2)
            return 1;
        else 
            return 0;
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    ll xf, yf;
    vector<P> pol(n + 1);
    cin >> xf >> yf;
    pol[0] = {xf, yf};
    pol[n] = {xf, yf};
    F(i, 1, n) {
        cin >> xf >> yf;
        pol[i] = {xf, yf};
    }
    
    F(i, 0, m) {
        ll num_intersec = 0;
        bool boundary = false;
        cin >> xf >> yf;
        P b = {xf, yf};
        F(i, 0, n) {
            ll res = li(b, pol[i], pol[i + 1]);
            if (res == 1) { // intersec
                num_intersec++;
            } else if (res == -1) { // fronteira
                cout << "BOUNDARY" << "\n";
                boundary = true;
                break;
            }
        }
        if (!boundary){
            if (num_intersec%2 == 0) {
                cout << "OUTSIDE" << "\n";
            } 
            else{
                cout << "INSIDE" <<"\n";
            }
        }
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
