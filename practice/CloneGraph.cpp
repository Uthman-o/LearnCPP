#include <cassert>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

/************************************************
Problem type: Graph traversal + graph copy
Containers: queue<Node*> + unordered_map<Node*, Node*>

Core issue: each original node must map to exactly one cloned node.

Interview questions
  Can the input node be nullptr?
  Can the graph contain cycles? Yes.
  Can nodes have self-loops or duplicate neighbors?
  Do I need a deep copy? Yes.
Complexity: O(V+E) time and O(V) worst-case queue space.

The key interview sentence:

“I use a hash map from original node pointer to cloned node pointer.
BFS visits each node once, creates missing clones, and connects the cloned adjacency lists.”
***************************************************/

using namespace std;

class Node {
   public:
    int val;
    vector<Node*> neighbors;

    Node() : val(0) {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        unordered_map<Node*, Node*> clones;
        queue<Node*> q;

        clones[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* neighbor : curr->neighbors) {
                // Haven't cloned this node yet
                if (clones.find(neighbor) == clones.end()) {
                    clones[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                // Connect cloned current node to cloned neighbor
                clones[curr]->neighbors.push_back(clones[neighbor]);
            }
        }

        return clones[node];
    }
};
