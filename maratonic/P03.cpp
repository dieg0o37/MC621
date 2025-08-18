#include <iostream>
#include <vector>
using namespace std;
/*
Itera do fim ao início

*/

int inicio = 0;

int main () {
    
    int N;
    cin >> N;
    string seq;
    cin >> seq;
    int aberto = 0, fechar = 0;
    for (int i = N - 1; i > inicio ; i--) { 
        if (seq[i] == ')') {
            fechar++;
        } else if (seq[i] == '(') {
            if (fechar > 0) {
                fechar--;
            }
            else {
                aberto++;
                while (aberto > 0) {
                    if (seq[inicio] == ')') {
                        aberto--;
                    } else {
                        aberto++;
                    }
                    inicio++;
                }
            }
            
        }
    }
    cout << inicio << endl;
}