//#include <iostream>
//#include <vector>
//#include <windows.h>
//
//using namespace std;
//
//
//const int numVertices = 11;
//
//void floydWarshall(vector<vector<double>>& graph, vector<vector<int>>& next) {
//    for (int k = 0; k < numVertices; k++) {
//        for (int i = 0; i < numVertices; i++) {
//            for (int j = 0; j < numVertices; j++) {
//                if (graph[i][k] != -1 && graph[k][j] != -1 &&
//                    (graph[i][j] == -1 || graph[i][k] + graph[k][j] < graph[i][j])) {
//                    graph[i][j] = graph[i][k] + graph[k][j];
//                    next[i][j] = k;
//                }
//            }
//        }
//    }
//}
//
//void printPath(int i, int j, const vector<vector<int>>& next) {
//    if (next[i][j] == -1) {
//        cout << j << " ";
//        return;
//    }
//
//   // printPath(i, next[i][j], next);
//    cout << next[i][j] << " ";
//    printPath(next[i][j], j, next);
//}
//
//int main() {
//    // підключення української локалізації
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    // Ініціалізація графу з вагами ребер
//    vector<vector<double>> graph = {
//           
//        {-1, -1, -1, 0.5, -1, -1, 3, -1, -1, -1, -1},
//        {-1, -1, 0.5, -1, -1, 0.4, -1, -1, -1, -1, 0.3},
//        {-1, 0.5, -1, -1, 0.5, 0.2, -1, -1, 0.5, -1, -1},
//        {0.5, -1, -1, -1, -1, -1, -1, 0.5, 0.5, -1, -1},
//        {-1, -1, 0.5, -1, -1, -1, -1, 0.4, 0.5, 0.3, -1},
//        {-1, 0.4, 0.2, -1, -1, -1, -1, -1, -1, -1, 0.5},
//        {3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//        {-1, -1, -1, 0.5, 0.4, -1, -1, -1, -1, 0.6, -1},
//        {-1, -1, 0.5, 0.5, 0.5, -1, -1, -1, -1, -1, -1},
//        {-1, -1, -1, -1, 0.3, -1, -1, 0.6, -1, -1, -1},
//        {-1, 0.3, -1, -1, -1, 0.5, -1, -1, -1, -1, -1}
//    
//    };
//
//    // Ініціалізація матриці next для відстеження шляху
//    vector<vector<int>> next(numVertices, vector<int>(numVertices, -1));
//
//    floydWarshall(graph, next);
//
//    // Виведення мінімальних відстаней для кожної пари вершин
//    cout << "Мінімальні відстані між вершинами:\n";
//    for (int i = 0; i < numVertices; i++) {
//        for (int j = 0; j < numVertices; j++) {
//            cout << graph[i][j] << "\t";
//        }
//        cout << endl;
//    }
//
//    int startVertex = 6; // Вершина, з якої починається обхід
//
//    // Виведення мінімального шляху для обходу всіх вершин, починаючи зі стартової вершини
//    cout << "\nМінімальний шлях для обходу всіх вершин, починаючи з " << startVertex << " вершини:\n";
//    for (int j = 0; j < numVertices; j++) {
//        if (j != startVertex) {
//            cout << startVertex << " -> " << j << ": ";
//            if (graph[startVertex][j] != -1) {
//                cout << startVertex << " ";
//                printPath(startVertex, j, next);
//            }
//            else {
//                cout << "Немає шляху";
//            }
//            cout << "\n";
//        }
//    }
//
//    return 0;
//}