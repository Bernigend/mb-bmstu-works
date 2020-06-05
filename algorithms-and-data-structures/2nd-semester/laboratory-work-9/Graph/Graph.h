#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nullptr"
//
// Created by Bernigend on 05.06.2020.
//

#ifndef LABORATORY_WORK_9_GRAPH_H
#define LABORATORY_WORK_9_GRAPH_H


#include <vector>
#include <ostream>
#include <queue>


#ifndef NULL
#define NULL 0
#endif

const std::size_t GRAPH_SIZE = 9;

enum NodeStatus {
    NOT_FOUND = 0,
    FOUND,
    VISITED,
};

class Graph {
protected:
    static NodeStatus* nodeStatus;

    static void dfs(unsigned int start, const bool (&map)[GRAPH_SIZE][GRAPH_SIZE], std::ostream& out)
    {
        out << start+1 << " ";
        Graph::nodeStatus[start] = VISITED;
        for (unsigned int i = 0; i < GRAPH_SIZE; i++) {
            if (map[start][i] != 0 && !Graph::nodeStatus[i]) Graph::dfs(i, map, out);
        }
    }

    static bool nullVisited(unsigned int num)
    {
        if (num == 0) return false;

        delete [] Graph::nodeStatus;
        Graph::nodeStatus = new NodeStatus [num];
        for (unsigned int i = 0; i < num; i++) Graph::nodeStatus[i] = NOT_FOUND;

        return true;
    }

public:
    static void searchDfs(unsigned int start, const bool (&map)[GRAPH_SIZE][GRAPH_SIZE], std::ostream& out)
    {
        if (start == 0) return;
        if (!Graph::nullVisited(GRAPH_SIZE)) return;
        Graph::dfs(start-1, map, out);
    }

    static void searchBfs(unsigned int start, const bool (&map)[GRAPH_SIZE][GRAPH_SIZE], std::ostream& out)
    {
        if (start == 0) return;
        if (!Graph::nullVisited(GRAPH_SIZE)) return;

        std::queue<unsigned int> queue;

        queue.push(start-1);
        while (!queue.empty()) {
            unsigned int temp = queue.front(); queue.pop();
            Graph::nodeStatus[temp] = VISITED;

            for (unsigned int i = 0; i < GRAPH_SIZE; i++) {
                if (map[temp][i] == 1 && Graph::nodeStatus[i] == NOT_FOUND) {
                    queue.push(i);
                    Graph::nodeStatus[i] = FOUND;
                }
            }

            out << temp + 1 << " ";
        }
    }
};


#endif //LABORATORY_WORK_9_GRAPH_H