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

void solve() {
    while(true) {
        string line;
        getline(cin, line, '\n');
        if (line.empty()) {
            break;
        }
        stringstream ss(line);
        Pd p_common, p_end1, p_end2;
        Pd p_in[4];
        double x, y;
        for(int i = 0; i < 4; i++) {
            ss >> x >> y;
            p_in[i] = {x, y};
        }

        if (p_in[1] == p_in[2]) {       
            p_common = p_in[1];
            p_end1 = p_in[0];
            p_end2 = p_in[3];
        } else if (p_in[1] == p_in[3]) { 
            p_common = p_in[1];
            p_end1 = p_in[0];
            p_end2 = p_in[2];
        } else if (p_in[0] == p_in[2]) {
            p_common = p_in[0];
            p_end1 = p_in[1];
            p_end2 = p_in[3];
        } else {                     
            p_common = p_in[0];
            p_end1 = p_in[1];
            p_end2 = p_in[2];
        }
        Pd p4 = p_end1 + p_end2 - p_common;
        
        cout << fixed << setprecision(3) << p4.X << " " << p4.Y <<"\n";

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
