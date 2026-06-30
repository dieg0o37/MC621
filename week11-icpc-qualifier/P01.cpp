#include <iostream>
using namespace std;


int main() {
    int v_r, v_d, v_m, v_l, N;
    cin >> v_r >> v_l >> v_d >> v_m >> N;
    int total = (v_d+v_l+v_m+v_r+N);
    int vencedor = 0;
    if (2*(v_d + N) > total) {
        cout << "Donatello" << endl;
        vencedor = 1;
    }
    if (2*(v_l + N) > total) {
        cout << "Leonardo" << endl;
        vencedor = 1;
    }
    if (2*(v_m + N) > total) {
        cout << "Michelangelo" << endl;
        vencedor = 1;
    }
    
    if (2*(v_r + N) > total) {
        cout << "Rafael" << endl;
        vencedor = 1;
    }
    if (!vencedor) {
        cout << "sem vencedores" << endl;
    }
    return 0;
}