#include "engine.h"

std::unique_ptr<Engine> Engine::m_engine;

std::unique_ptr<Engine> Engine::getInstance()
{
    if(m_engine.get() == nullptr) {
        m_engine = std::make_unique<Engine>();
    }
    return std::move(m_engine);
}

Engine::Engine()
{
}

void Engine::createGraph(int nodeCount)
{
    m_graph = std::make_unique<Graph<int>>(nodeCount);
}
