#include  <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, a, b) for(int i = a; i < b; i++)
#define Fr(i, a, b) for(int i = a; i >=b; i--)
typedef complex<ll> P;
typedef complex<double> Pb;

#define Y imag() 
#define X real()
bool sort_x(Pb s1, Pb s2) {
    return (s1.X < s2.X);
}
bool sort_y(Pb s1, Pb s2) {
    return (s1.Y < s2.Y);
}

int main() {
    Pb q = {1,50}, q1 = {2, 50}, q3 = {300,20}, q4 = {7, 23};
    q *= 1i;
    vector<Pb> v;
    v.push_back(q);
    v.push_back(q1);
    v.push_back(q3);
    v.push_back(q4);
    sort(v.begin(), v.end(), sort_x);
    for(auto u: v) {
        cout << u << " ";
    }
    cout << "\n";
    sort(v.begin(), v.end(), sort_y);
    for(auto u: v) {
        cout << u << " ";
    }
    cout << "\n";
    cout << q.X << "    " << q.Y << "\n";
    cout << abs(q) << "\n";
    cout << arg(q) << "\n";
    
}