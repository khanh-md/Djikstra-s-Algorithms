//Anh Luu U08722141
//Khanh Dong U14837275

#include "Graph.hpp"
#define INT_MAX 1000000

void Graph::addVertex(std::string label) {
    for(auto itr : adjList){
        if(itr.first == label) {
            return;
        }
    }
    adjList[label];
};

void Graph::removeVertex(std::string label) {
    adjList.erase(label);
};

void Graph::addEdge(std::string label1, std::string label2, unsigned long weight) {
    int exist1 = 0, exist2 = 0;
    for (auto itr : adjList) {
        if(itr.first == label1) {
            exist1 = 1;
        }
        if (itr.first == label2) {
            exist2 = 1;
        }
    }
    if (exist1 == 1 && exist2==1) {
         adjList[label1][label2] = weight;
         adjList[label2][label1] = weight;
    }
};

void Graph::removeEdge(std::string label1, std::string label2) {
    int exist1 = 0, exist2 = 0;
    for (auto itr : adjList) {
        if(itr.first == label1) {
            exist1 = 1;
        }
        if (itr.first == label2) {
            exist2 = 1;
        }
    }
    if (exist1 == 1 && exist2==1) {
        adjList[label1].erase(label2);
        adjList[label2].erase(label1);
    }
};

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) {
    map<string, unsigned long> dist; //map for the shortest distance

    queue<string> unvisited;
    map<string, bool> visited; //for bfs

    map<string, string> reverse_path; //store the shortest path pointing to any given node

    for(auto itr : adjList) {
        if(itr.first == startLabel) {
            dist[itr.first] = 0;
            visited[itr.first] = true;
            reverse_path[itr.first] = startLabel;
        }
        else{
            dist[itr.first] = INT_MAX;
            visited[itr.first] = false;
        }
        
    }
    unvisited.push(startLabel);

    while(!unvisited.empty()) {
        string temp = unvisited.front();
        
        for(auto itr : adjList[temp]) {
            string node = itr.first;
            if (visited[node] == false ) {
                unvisited.push(node);
            }
            unsigned long current_dist = dist[temp] + itr.second;
            if (current_dist < dist[node]) {
                dist[node] = current_dist;
                reverse_path[node] = temp;
            }
        }

        unvisited.pop();
        visited[temp] = true;
    }

    string temp = endLabel;
    while (temp != startLabel) {
        path.insert(path.begin(), temp);
        temp = reverse_path[temp];
    }
    path.insert(path.begin(), startLabel);
    
    return dist[endLabel];
};