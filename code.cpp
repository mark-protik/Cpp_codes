#include<bits/stdc++.h>
using namespace std;

void bfs(int** adjacency_matrix, int num_vertices, int starting_vertex, int* parent_vertices) {
    queue<int> vertex_queue;
    bool* visited_vertices = new bool[num_vertices];

    for(int i=0;i<num_vertices;i++) {
        visited_vertices[i] = false;
        parent_vertices[i] = -1;
    }


    visited_vertices[starting_vertex] = true;

    vertex_queue.push(starting_vertex);

    while(!vertex_queue.empty()) {
        int current_vertex = vertex_queue.front();
        vertex_queue.pop();
        
        for(int i=0;i<num_vertices;i++) {
            if(adjacency_matrix[current_vertex][i] == 1 && !visited_vertices[i]) {
                visited_vertices[i] = true;
                parent_vertices[i] = current_vertex;
                vertex_queue.push(i);
            }
        }
    }
    delete[] visited_vertices;
}

int main() {
    int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;
    int** adjacency_matrix = new int*[num_vertices];

    for(int i=0;i<num_vertices;i++) {
        adjacency_matrix[i] = new int[num_vertices];

        for(int j=0;j<num_vertices;j++) {
            adjacency_matrix[i][j] = 0;
        }
    }
    for(int i=0;i<num_edges;i++) {
        int vertex_a, vertex_b;
        cin >> vertex_a >> vertex_b;
        adjacency_matrix[vertex_a][vertex_b] = 1;
        adjacency_matrix[vertex_b][vertex_a] = 1;
    }
    int* parent_vertices = new int[num_vertices];

    bfs(adjacency_matrix, num_vertices, 0, parent_vertices);

    for(int i=0;i<num_vertices;i++) {
        cout << "Parent of vertex " << i << " is " << parent_vertices[i] << endl;
    }
    for(int i=0;i<num_vertices;i++) {
        delete[] adjacency_matrix[i];
    }
    delete[] adjacency_matrix;
    delete[] parent_vertices;
    return 0;
}
