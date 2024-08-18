#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <utility>

using namespace std;

// Function to find the shortest path using BFS
pair<bool, vector<char>> findShortestPath(
    const unordered_map<char, vector<char>>& graph, 
    char start, 
    char end) 
{
    // Check if start or end nodes are not in the graph
    if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
        return {false, {}};
    }

    // Queue to hold the current node and the path to it
    queue<pair<char, vector<char>>> queue;
    // Set to keep track of visited nodes
    set<char> visited;

    // Start BFS from the start node
    queue.push({start, {start}});
    visited.insert(start);

    while (!queue.empty()) {
        char current_node = queue.front().first;
        vector<char> current_path = queue.front().second;
        queue.pop();

        // If reached the end node, return the path
        if (current_node == end) {
            return {true, current_path};
        }

        // Explore neighbors
        for (char neighbor : graph.at(current_node)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                vector<char> new_path = current_path;
                new_path.push_back(neighbor);
                queue.push({neighbor, new_path});
            }
        }
    }

    // No path found
    return {false, {}};
}

int main() {
    
    unordered_map<char, vector<char>> graph = {
        {'A', {'B'}},
        {'B', {'C','D','E','A'}},
        {'C', {'F'}},
        {'D', {'E','G'}},
        {'E', {'F'}},
        {'F', {'G', 'B'}},
        {'G', {}},
        {'H', {}}
    };

    char start;
    char end;
    cout<<"Enter start node: ";
    cin>>start;

    cout<<"Enter end node: ";
    cin>>end;

    auto result = findShortestPath(graph, start, end);
    cout <<"Path Exists: "<<(result.first ? "True" : "False") << endl;
    if (result.first) {
        cout<<"Path: ";
        for (char node : result.second) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
