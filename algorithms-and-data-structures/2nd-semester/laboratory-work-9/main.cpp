#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-auto"

#include <iostream>
#include "Graph/Graph.h"

int main() {
    const unsigned int GRAPH_SIZE = 9;

    bool map[GRAPH_SIZE][GRAPH_SIZE] = {
        { 0, 0, 1, 1, 0, 0, 0, 1, 1 },
        { 0, 0, 0, 0, 0, 1, 1, 0, 0 },
        { 1, 0, 0, 0, 1, 1, 0, 1, 0 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 0, 0, 1, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 1, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0, 0, 1, 0 },
        { 1, 0, 1, 0, 0, 0, 1, 0, 0 },
        { 1, 0, 0, 1, 0, 0, 0, 0, 0 }
    };

    bool* pMap = reinterpret_cast<bool*>(map);

    unsigned int start = 2;

    Graph::searchDfs(start, pMap, GRAPH_SIZE, std::cout);
    std::cout << std::endl;
    Graph::searchBfs(start, pMap, GRAPH_SIZE, std::cout);

//    do {
//
//        std::cout << "Enter start point: ";
//        std::cin >> start;
//
//        std::cout << "DFS: ";
//        Graph::searchDfs(start, map, std::cout);
//        std::cout << std::endl;
//
//        std::cout << "BFS: ";
//        Graph::searchBfs(start, map, std::cout);
//        std::cout << std::endl;
//        std::cout << std::endl;
//
//    } while (start != 0);
}


//#include <iostream>
//using namespace std;
//int mas[7][7] = { { 0, 1, 1, 0, 0, 0, 1 }, // матрица смежности
//                  { 1, 0, 1, 1, 0, 0, 0 },
//                  { 1, 1, 0, 0, 0, 0, 0 },
//                  { 0, 1, 0, 0, 1, 0, 0 },
//                  { 0, 0, 0, 1, 0, 1, 0 },
//                  { 0, 0, 0, 0, 1, 0, 1 },
//                  { 1, 0, 0, 0, 0, 1, 0 } };
//int nodes[7]; // вершины графа
//void search(int st, int n)
//{
//    int r;
//    cout << st + 1 << " ";
//    nodes[st] = 1;
//    for (r = 0; r < n; r++)
//        if (nodes[r] == 0)
//            search(r, n);
//}
//int main()
//{
//    for (int i = 0; i < 7; i++) // исходно все вершины равны 0
//        nodes[i] = 0;
//    search(0, 7);
//    cin.get();
//    return 0;
//}
#pragma clang diagnostic pop