#include <iostream>
#include <limits>
#include <vector>

using namespace std;

const int SIZE = 11;

// Функція для знаходження вершини з найменшою відстанню, яка ще не була відвідана
int findMinDistanceVertex(const double dist[], const bool visited[]) {
    double minDist = numeric_limits<double>::max();
    int minIndex = -1;

    for (int i = 0; i < SIZE; ++i) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void outResult( int startVertex, double dist[SIZE], vector<int> path[SIZE]) {
   
    // Виводимо результати
    cout << "Distances and paths to all vertices from the vertex " << startVertex + 1 << ":" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "Top " << i + 1 << ": ";
        if (dist[i] != numeric_limits<double>::max()) {
            cout << "distance - " << dist[i] << "; \t way - ";
            for (int j = 0; j < path[i].size(); ++j) {
                cout << path[i][j] + 1; // Додати 1 до індексів для нумерації з 1
                if (j < path[i].size() - 1) {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
        else {
            cout << "impossible to achieve" << endl;
        }
    }
}

// Функція для виведення найкоротших шляхів до всіх вершин з використанням алгоритму Дейкстри
void dijkstra(const double graph[SIZE][SIZE], int startVertex) {
    double dist[SIZE]; // Масив для зберігання найкоротших відстаней до вершин
    bool visited[SIZE]; // Масив, що вказує, чи була відвідана вершина
    vector<int> path[SIZE]; // Масив для зберігання шляхів до вершин

    // Ініціалізуємо масиви
    for (int i = 0; i < SIZE; ++i) {
        dist[i] = numeric_limits<double>::max(); // Встановлюємо відстань до всіх вершин на початку як нескінченність
        visited[i] = false; // Жодна вершина ще не відвідана
    }

    // Відстань до стартової вершини завжди 0
    dist[startVertex] = 0;
    path[startVertex].push_back(startVertex); // Шлях до початкової вершини

    // Знаходимо найкоротший шлях для кожної вершини
    for (int count = 0; count < SIZE - 1; ++count) {
        int u = findMinDistanceVertex(dist, visited); // Знаходимо вершину з найменшою відстанню
        visited[u] = true; // Позначаємо вершину як відвідану

        // Оновлюємо відстані до сусідніх вершин, якщо вони ще не відвідані і відстань до них через поточну вершину коротша
        for (int v = 0; v < SIZE; ++v) {
            if (!visited[v] && graph[u][v] != -1 && dist[u] != numeric_limits<double>::max() && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                path[v] = path[u]; // Копіюємо шлях до вершини u
                path[v].push_back(v); // Додаємо вершину v до шляху
            }
        }
    }

    // Виводимо результати
    cout << "Distances and paths to all vertices from the vertex " << startVertex + 1 << ":" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "Top " << i + 1 << ": ";
        if (dist[i] != numeric_limits<double>::max()) {
            cout << "distance - " << dist[i] << ";\t cost - "<< dist[i] * 6 << "; \t way - ";
            for (int j = 0; j < path[i].size(); ++j) {
                cout << path[i][j] + 1; // Додати 1 до індексів для нумерації з 1
                if (j < path[i].size() - 1) {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
        else {
            cout << "impossible to achieve" << endl;
        }
    }

    //outResult(startVertex, &dist[SIZE], &path[SIZE]);
}

int main() {
    double graph[SIZE][SIZE] = {
        {-1, -1, -1, 0.5, -1, -1, 3, -1, -1, -1, -1},
        {-1, -1, 0.5, -1, -1, 0.4, -1, -1, -1, -1, 0.3},
        {-1, 0.5, -1, -1, 0.5, 0.2, -1, -1, 0.5, -1, -1},
        {0.5, -1, -1, -1, -1, -1, -1, 0.5, 0.5, -1, -1},
        {-1, -1, 0.5, -1, -1, -1, -1, 0.4, 0.5, 0.3, -1},
        {-1, 0.4, 0.2, -1, -1, -1, -1, -1, -1, -1, 0.5},
        {3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, 0.5, 0.4, -1, -1, -1, -1, 0.6, -1},
        {-1, -1, 0.5, 0.5, 0.5, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, 0.3, -1, -1, 0.6, -1, -1, -1},
        {-1, 0.3, -1, -1, -1, 0.5, -1, -1, -1, -1, -1}
    };

    // Застосовуємо алгоритм Дейкстри для знаходження найкоротших шляхів від вершини 1
    dijkstra(graph, 6);

    return 0;
}
