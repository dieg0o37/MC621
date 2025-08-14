#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    int k;
    std::cin >> n >> k;

    std::vector<long long> a(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> a[i];
    }

    long long total_divisibles = 0;

    for (int i = 1; i < (1 << k); ++i) {
        long long product = 1;
        int subset_size = 0;

        for (int j = 0; j < k; ++j) {
            // Se o j-ésimo bit de 'i' está ligado, o j-ésimo primo faz parte do subconjunto
            if ((i >> j) & 1) {
                // Verificação de overflow antes da multiplicação
                // Se product > n / a[j], então product * a[j] > n.
                if (product > n / a[j]) {
                    product = n + 1; // Marca como inválido (maior que n)
                    break;
                }
                product *= a[j];
                subset_size++;
            }
        }

        if (product > n) {
            continue; // Se o produto já ultrapassou n, não há divisores.
        }

        // Princípio da Inclusão-Exclusão:
        if (subset_size % 2 == 1) {
            total_divisibles += n / product;
        } else {
            total_divisibles -= n / product;
        }
    }

    std::cout << total_divisibles << std::endl;

    return 0;
}