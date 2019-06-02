#ifndef ENGINE_H
#define ENGINE_H

#include "graph.h"
#include <memory>

//class Graph

class Engine
{
public:
    void createGraph(int nodeCount);
	void printGraph() const;
	void connNodes(const std::string& fisrt, const std::string& second);
    static std::shared_ptr<Engine> getInstance();
    Engine();

// private methods
private:

private:
    static std::shared_ptr<Engine> m_engine;
    std::shared_ptr<Graph<int>> m_graph;
};

#endif // ENGINE_H
