#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <locale>

using namespace std;

int bfs(const vector<vector<int>>& adj, int start, int end) {
    vector<int> distance(adj.size(), INT_MAX);
    queue<int> q;
    q.push(start);
    distance[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (distance[neighbor] == INT_MAX) {
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
                if (neighbor == end) {
                    return distance[end];
                }
            }
        }
    }

    return -1;
}

int main() {
    
    setlocale(LC_ALL, "ru_RU.UTF-8");
    locale::global(locale("ru_RU.UTF-8"));
    wcout.imbue(locale("ru_RU.UTF-8"));

    int n, t;

    
    wcout << L"Ёта программа рассчитывает минимальное количество перемещений между планетами.\n";
    wcout << L"¬ведите количество планет (n) и количество компаний (t):\n";

    wcin >> n >> t;

    vector<vector<int>> companies(t);
    wcout << L"¬ведите количество планет, обслуживаемых каждой компанией, и номера этих планет:\n";
    for (int i = 0; i < t; ++i) {
        int k;
        wcin >> k;
        companies[i].resize(k);
        for (int j = 0; j < k; ++j) {
            wcin >> companies[i][j];
            companies[i][j]--;
        }
    }

    vector<vector<int>> adj(n);
    for (const auto& company : companies) {
        for (size_t i = 0; i < company.size(); ++i) {
            for (size_t j = i + 1; j < company.size(); ++j) {
                adj[company[i]].push_back(company[j]);
                adj[company[j]].push_back(company[i]);
            }
        }
    }

    int result = bfs(adj, 0, n - 1);
    if (result == -1) {
        wcout << L"Ќевозможно добратьс€ до планеты " << n << endl;
    }
    else {
        wcout << L"ћинимальное количество перемещений: " << result << endl;
    }

    return 0;
}
