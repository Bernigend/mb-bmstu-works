#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nullptr"
//
// Created by Bernigend on 05.06.2020.
//

#ifndef LABORATORY_WORK_9_GRAPH_H
#define LABORATORY_WORK_9_GRAPH_H


#include <ostream>


#ifndef NULL
#define NULL 0
#endif

enum NodeStatus {
    NOT_FOUND = 0,
    FOUND,
    VISITED,
};

class Graph {
protected:
    static NodeStatus* nodeStatus;

    static void dfs(unsigned int start, const bool map[], unsigned int size, std::ostream& out);
    static bool nullVisited(unsigned int num);

public:
    static void searchDfs(unsigned int start, const bool map[], unsigned int size, std::ostream& out);
    static void searchBfs(unsigned int start, const bool map[], unsigned int size, std::ostream& out);
};


#endif //LABORATORY_WORK_9_GRAPH_H