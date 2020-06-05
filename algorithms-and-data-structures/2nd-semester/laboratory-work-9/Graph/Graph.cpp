#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nullptr"
//
// Created by Bernigend on 05.06.2020.
//

#include <queue>
#include "Graph.h"


// --------------------- //
// СТАТИЧЕСКИЕ СВОЙСТВА
// --------------------- //


NodeStatus* Graph::nodeStatus = NULL;


// --------------------- //
// СТАТИЧЕСКИЕ МЕТОДЫ
// --------------------- //


void Graph::dfs(unsigned int start, const bool map[], unsigned int size, std::ostream& out)
{
    out << start+1 << " ";
    Graph::nodeStatus[start] = VISITED;
    for (unsigned int row = 0; row < size; row++) {
        if (map[row * size + start] != 0 && !Graph::nodeStatus[row]) Graph::dfs(row, map, size, out);
    }
}


bool Graph::nullVisited(unsigned int num)
{
    if (num == 0) return false;

    delete [] Graph::nodeStatus;
    Graph::nodeStatus = new NodeStatus [num];
    for (unsigned int i = 0; i < num; i++) Graph::nodeStatus[i] = NOT_FOUND;

    return true;
}


void Graph::searchDfs(unsigned int start, const bool map[], unsigned int size, std::ostream& out)
{
    if (start == 0) return;
    if (!Graph::nullVisited(size)) return;
    Graph::dfs(start-1, map, size, out);
}


void Graph::searchBfs(unsigned int start, const bool map[], unsigned int size, std::ostream& out)
{
    if (start == 0) return;
    if (!Graph::nullVisited(size)) return;

    std::queue<unsigned int> queue;

    queue.push(start-1);
    while (!queue.empty()) {
        unsigned int temp = queue.front(); queue.pop();
        Graph::nodeStatus[temp] = VISITED;

        for (unsigned int row = 0; row < size; row++) {
            if (map[row * size + temp] == 1 && Graph::nodeStatus[row] == NOT_FOUND) {
                queue.push(row);
                Graph::nodeStatus[row] = FOUND;
            }
        }

        out << temp + 1 << " ";
    }
}