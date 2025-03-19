#include <iostream>
#include <vector>
#include <queue>
#include <fstream>


void bfs(std::vector<std::vector<int>>& edges, int start){
    std::queue<int> bfs_queue;
    int edges_size = edges.size();
    //пусть -1 будет означать бесконечность
    std::vector<int> dist(edges_size, -1);
    dist[start] = 0;
    int v;
    bfs_queue.push(start);
    while(!bfs_queue.empty()){
        v = bfs_queue.front();
        bfs_queue.pop();
        for (auto elem : edges[v]){
            if (dist[elem] == -1){
                bfs_queue.push(elem);
                dist[elem] = dist[v] + 1;
            }
        }
    }
    for (int i = 0; i < edges_size; i++){
        std::cout << "The distance from vertex " << start << " to the vertex " << i << " is ";
        std::cout << dist[i] << "\n";
    }
}


int main(){
    std::ifstream file("graph.txt");
    if (!file.is_open()) {
        std::cerr << "Can't open file!" << std::endl;
        return 1;
    }
    int v, e, start;

    file >> v;
    file >> e;

    std::vector<std::vector<int>> edges(v);
    int a, b;

    for (int i = 0; i < e; i++){
        file >> a;
        file >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    file >> start;
    file.close();

    bfs(edges, start);

    return 0;
}