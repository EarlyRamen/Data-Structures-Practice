#include <unordered_set>
#include <queue>
#include <functional>

#include "problem.h"


#ifndef C18394B6_E259_42C7_B712_83CD6DFCD67B
#define C18394B6_E259_42C7_B712_83CD6DFCD67B

struct Node
{
    State state;
    uint64_t pathCost;
    Node* parent;

    bool operator==(const Node& n) {return n.state == state;}
    bool operator!=(const Node& n) {return !(n.state == state);}
};

struct Hash
{
    size_t operator()(const Node* n) const {return n->state.board;}
};

class UniformCostSearch
{
public:
    UniformCostSearch() : frontier{[](const Node* a, const Node* b) {return a->pathCost > b->pathCost;}} { }

    std::vector<State> start(const Problem&);

private:
    Node* createNode(Problem, Node*, const State&) const;
    void createPath(const Node*) const;
    std::unordered_set<Node*, Hash> explored;
    std::priority_queue<Node*, std::vector<Node*>, std::function<bool(const Node*, const Node*)>> frontier;
    mutable std::vector<State> shortestPath;
};

#endif /* C18394B6_E259_42C7_B712_83CD6DFCD67B */
