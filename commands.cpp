#include "commands.h"
#include "commandspool.h"
#include "engine.h"
#include "application.h"
#include <cassert>

ICommand::ICommand()
{

}

ICommand::~ICommand()
{}

CreateGraph::CreateGraph()
{

}
void CreateGraph::execute()
{
    std::unique_ptr<Engine> engine = Engine::getInstance();
    engine->createGraph(m_nodeCount.getValue());
}

void CreateGraph::parseArguments(const std::vector<std::string>& str)
{
    const std::string argName = m_nodeCount.getName();
    auto arg =  std::find(str.begin(), str.end(), argName);
    if(Application::getMode() == Application::Mode::DEBUG) {
        assert(arg != str.end());
    }
    m_nodeCount.parseValue(*(arg++));
}

std::unique_ptr<ICommand> CreateGraph::getInstance() const
{
    return std::make_unique<CreateGraph>();
}
