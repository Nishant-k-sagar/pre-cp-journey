#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent a node in the graph
struct Node {
  int vertex;
  int distance;

  Node(int vertex, int distance) {
    this->vertex = vertex;
    this->distance = distance;
  }
};

// Comparator for the priority queue
struct NodeComparator {
  bool operator()(const Node& a, const Node& b) const {
    return a.distance > b.distance;
  }
};

// Function to implement Dijkstra's algorithm
vector<int> dijkstra(vector<vector<int>>& graph, int source) {
  // Initialize the distance of all nodes to infinity
  vector<int> distance(graph.size(), INT_MAX);

  // Create a priority queue to store the nodes
  priority_queue<Node, vector<Node>, NodeComparator> pq;

  // Add the source node to the priority queue
  pq.push(Node(source, 0));

  // While the priority queue is not empty
  while (!pq.empty()) {
    // Get the node with the shortest distance from the priority queue
    Node node = pq.top();
    pq.pop();

    // If the distance of the current node is less than the distance in the distance vector, update the distance in the distance vector
    if (node.distance < distance[node.vertex]) {
      distance[node.vertex] = node.distance;

      // Iterate over all the neighbors of the current node
      for (int i = 0; i < graph[node.vertex].size(); i++) {
        // Get the neighbor node and its distance from the current node
        int neighbor = graph[node.vertex][i];
        int neighborDistance = node.distance + graph[node.vertex][i];

        // If the distance of the neighbor node is greater than the neighbor distance, update the distance of the neighbor node and add it to the priority queue
        if (distance[neighbor] > neighborDistance) {
          distance[neighbor] = neighborDistance;
          pq.push(Node(neighbor, neighborDistance));
        }
      }
    }
  }

  // Return the distance vector
  return distance;
}

// Main function
int main() {
  // Create a graph
  vector<vector<int>> graph = {
    {0, 4, 0, 0, 0},
    {4, 0, 3, 5, 0},
    {0, 3, 0, 1, 7},
    {0, 5, 1, 0, 2},
    {0, 0, 7, 2, 0}
  };

  // Find the shortest path from the source node 0 to all other nodes
  vector<int> distance = dijkstra(graph, 0);

  // Print the shortest path
  for (int i = 0; i < distance.size(); i++) {
    cout << "The shortest path from 0 to " << i << " is " << distance[i] << endl;
  }

  return 0;
}