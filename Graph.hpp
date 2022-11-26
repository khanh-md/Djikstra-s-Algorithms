#ifndef GRAPH_H
#define GRAPH_H

#include "GraphBase.hpp"
#include <map>
#include <queue>
#include <iostream>

using namespace std;

class Graph : public GraphBase {
    public:
        Graph(){};
        ~Graph(){};
        void addVertex(std::string label);
        void removeVertex(std::string label);
        void addEdge(std::string label1, std::string label2, unsigned long weight);
        void removeEdge(std::string label1, std::string label2);
        unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path);

    private:
        map<string, map<string, unsigned long>> adjList;

};

#endif