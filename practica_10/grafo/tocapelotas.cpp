#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool esBipartito(int V, vector<vector<int>>& grafo) {
    vector<int> color(V, -1); // -1 = no coloreado
    queue<int> cola;

    for (int i = 0; i < V; ++i) {
        if (color[i] == -1) {
            color[i] = 0;
            cola.push(i);

            while (!cola.empty()) {
                int actual = cola.front();
                cola.pop();

                for (int vecino : grafo[actual]) {
                    if (color[vecino] == -1) {
                        color[vecino] = color[actual] ^ 1; // Alternar 0 <-> 1
                        cola.push(vecino);
                    } else if (color[vecino] == color[actual]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int V, A;
    while (cin >> V && V != 0) {
        cin >> A;
        vector<vector<int>> grafo(V);

        for (int i = 0; i < A; ++i) {
            int u, v;
            cin >> u >> v;
            grafo[u].push_back(v);
            grafo[v].push_back(u);
        }

        cout << (esBipartito(V, grafo) ? "SI" : "NO") << endl;
    }
    return 0;
}