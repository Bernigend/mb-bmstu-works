#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-auto"

#include <iostream>
#include "Graph/Graph.h"

int main() {
    const unsigned int GRAPH_SIZE = 9;

    // изображение указанного графа находится в папке images
    bool map[GRAPH_SIZE][GRAPH_SIZE] = {
        { false, false, true,  true,  false, false, false, true,  true  },
        { false, false, false, false, false, true,  true,  false, false },
        { true,  false, false, false, true,  true,  false, true,  false },
        { true,  false, false, false, false, false, false, false, true  },
        { false, false, true,  false, false, false, false, false, false },
        { false, true,  true,  false, false, false, false, false, false },
        { false, true,  false, false, false, false, false, true,  false },
        { true,  false, true,  false, false, false, true,  false, false },
        { true,  false, false, true,  false, false, false, false, false }
    };

    bool* pMap = reinterpret_cast<bool*>(map);
    unsigned int start;

    do {

        std::cout << "Enter start point: ";
        std::cin >> start;

        std::cout << "DFS: ";
        Graph::searchDfs(start, pMap, GRAPH_SIZE, std::cout);
        std::cout << std::endl;

        std::cout << "BFS: ";
        Graph::searchBfs(start, pMap, GRAPH_SIZE, std::cout);
        std::cout << std::endl;
        std::cout << std::endl;

    } while (start != 0);
}