#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;
using namespace std::chrono;

struct Item {
    int peso, valor;
    double razao;
};

int algoritmoGuloso(int n, int Q, vector<Item> itens) {
    sort(itens.begin(), itens.end(), [](Item a, Item b) { return a.razao > b.razao; });
    int v = 0, p = 0;
    for (int i = 0; i < n; i++) {
        if (p + itens[i].peso <= Q) { p += itens[i].peso; v += itens[i].valor; }
    }
    return v;
}

int forcaBruta(int n, int Q, const vector<Item>& itens) {
    if (n == 0 || Q == 0) return 0;
    if (itens[n - 1].peso > Q) return forcaBruta(n - 1, Q, itens);
    return max(itens[n - 1].valor + forcaBruta(n - 1, Q - itens[n - 1].peso, itens), forcaBruta(n - 1, Q, itens));
}

int programacaoDinamica(int n, int Q, const vector<Item>& itens) {
    vector<int> dp(Q + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = Q; j >= itens[i].peso; j--) {
            dp[j] = max(dp[j], dp[j - itens[i].peso] + itens[i].valor);
        }
    }
    return dp[Q];
}

vector<Item> gerarItens(int n, int maxP) {
    vector<Item> itens(n);
    mt19937 gen(time(0));
    uniform_int_distribution<> dP(1, maxP), dV(1, 1000);
    for (int i = 0; i < n; i++) {
        itens[i].peso = dP(gen);
        itens[i].valor = dV(gen);
        itens[i].razao = (double)itens[i].valor / itens[i].peso;
    }
    return itens;
}

int main() {
    vector<vector<int>> casos = {{20, 10, 10}, {50, 30, 30}, {100, 30, 30}, {200, 50, 50}, {500, 10, 10}, {500, 100, 100}, {1000, 50, 50}, {10000, 100, 100}, {500000, 100, 100}};
    
    cout << fixed << setprecision(3);
    cout << "----------------------------------------------------------------------" << endl;
    cout << "| N      | Q   | Guloso (us) | F. Bruta (us)   | P. Din (us) |" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    for (auto& c : casos) {
        int n = c[0], Q = c[1];
        auto itens = gerarItens(n, c[2]);
        int repeticoes = (n < 1000) ? 1000 : 1;

        auto s = high_resolution_clock::now();
        for(int i=0; i<repeticoes; i++) algoritmoGuloso(n, Q, itens);
        auto e = high_resolution_clock::now();
        double tG = duration_cast<nanoseconds>(e - s).count() / (1000.0 * repeticoes);

        string tFB = "PROIBITIVO";
        if (n <= 22) {
            s = high_resolution_clock::now();
            forcaBruta(n, Q, itens);
            e = high_resolution_clock::now();
            tFB = to_string(duration_cast<nanoseconds>(e - s).count() / 1000.0);
        }

        s = high_resolution_clock::now();
        for(int i=0; i<repeticoes; i++) programacaoDinamica(n, Q, itens);
        e = high_resolution_clock::now();
        double tPD = duration_cast<nanoseconds>(e - s).count() / (1000.0 * repeticoes);

        cout << "| " << left << setw(7) << n << "| " << setw(4) << Q << "| " << setw(12) << tG << "| " << setw(16) << tFB << "| " << setw(12) << tPD << " |" << endl;
    }
    return 0;
}