#include <iostream>
#include <vector>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int vec[N];
    for (int i = 0; i < N; ++i) {
        cin >> vec[i];
    }
    int seq = 1, numero_atual = vec[0];
    int max_seq = seq;
    for (int i = 1; i < N; ++i) {
        if (numero_atual + 1 == vec[i]) {
            seq++;
        } else {
            if (seq > max_seq) max_seq = seq;
            seq = 1;
        }
        numero_atual = vec[i];
    }
    if (seq > max_seq) max_seq = seq;
    cout << max_seq << endl;
    return 0;
    
}