#ifndef ENGINE_H
#define ENGINE_H

#include "graph.h"
#include <memory>

//class Graph

class Engine
{
public:
    void createGraph(int nodeCount);
    static std::unique_ptr<Engine> getInstance();
    Engine();

// private methods
private:

private:
    static std::unique_ptr<Engine> m_engine;
    std::unique_ptr<Graph<int>> m_graph;
};

#endif // ENGINE_H
