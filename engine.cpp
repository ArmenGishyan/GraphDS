
#include "engine.h"
#include <cassert>

std::shared_ptr<Engine> Engine::m_engine;

std::shared_ptr<Engine> Engine::getInstance()
{
    if(m_engine.get() == nullptr) {
        m_engine = std::make_shared<Engine>();
    }
    return m_engine;
}

Engine::Engine()
{
}

void Engine::createGraph(int nodeCount)
{
    m_graph = std::make_shared<Graph<int>>(nodeCount);
}

void Engine::printGraph() const
{
	//assert(m_graph.get() != nullptr);
	if (m_graph.get() != nullptr) {
  		m_graph->print();
	}
}


void Engine::connNodes(const std::string& first, const std::string& second)
{
	if (m_graph.get() != nullptr) {
		m_graph->connNodes(first, second);
	}
}

