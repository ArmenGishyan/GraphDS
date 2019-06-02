#include "commands.h"
#include "commandspool.h"
#include "engine.h"
#include "application.h"
#include "commandLine.h"
#include <cassert>
#include <iostream>
#include <fstream>

ICommand::ICommand()
{

}

ICommand::~ICommand()
{
	int volatile x = 10;
}

CreateGraph::CreateGraph() : ICommand()
{
	m_nodeCount.setName("-node_count");
}
void CreateGraph::execute()
{
    std::shared_ptr<Engine> engine = Engine::getInstance();
    engine->createGraph(m_nodeCount.getValue());
}

void CreateGraph::parseArguments(const std::vector<std::string>& str)
{

    const std::string argName = m_nodeCount.getName();
    auto arg =  std::find(str.begin(), str.end(), argName);
    if(Application::getMode() == Application::Mode::DEBUG) {
        assert(arg != str.end());
    }
    m_nodeCount.parseValue(*(++arg));
}

std::unique_ptr<ICommand> CreateGraph::getInstance() const
{
    return std::make_unique<CreateGraph>();
}

void CreateGraph::initArguments()
{
	m_nodeCount = IntArg("-node_count");
	//m_argumentsList.insert(new IntArg(("-node_count")));
}

void Print::execute()
{
	std::shared_ptr<Engine> engine = Engine::getInstance();
	engine->printGraph();
}

std::unique_ptr<ICommand> Print::getInstance() const
{
	return std::make_unique<Print>();
}

ConnectNodes::ConnectNodes()
{
	m_firstNode.setName("-fname");
	m_secondNode.setName("-sname");
}

void ConnectNodes::execute()
{
	std::shared_ptr<Engine> engine = Engine::getInstance();
	engine->connNodes(m_firstNode.getValue(), m_secondNode.getValue());
}

void ConnectNodes::parseArguments(const std::vector<std::string>& vec)
{
	std::vector<std::string>::const_iterator itFirst = std::find(vec.begin(), vec.end(), m_firstNode.getName());
	std::vector<std::string>::const_iterator itSecond = std::find(vec.begin(), vec.end(), m_secondNode.getName());
	if (itFirst != vec.end() && itSecond != vec.end())
	{
		m_firstNode.parseValue(*(++itFirst));
		m_secondNode.parseValue(*(++itSecond));
	}
	
}

std::unique_ptr<ICommand> ConnectNodes::getInstance() const
{
	return std::make_unique<ConnectNodes>();
}

SourceFile::SourceFile()
{
	m_fileName.setName("-file");
}

void SourceFile::execute()
{
	ExecuteCommand commandLine;
	std::ifstream ifs(m_fileName.getValue(), std::ifstream::in);

	std::string str;
	assert(ifs.is_open());
	while (ifs.good()) {
		std::getline(ifs, str);
		commandLine.execute(str);
	}

}

void SourceFile::parseArguments(const std::vector<std::string>& str) 
{
	std::vector<std::string>::const_iterator it =  std::find(str.begin(), str.end(), m_fileName.getName());
	if (it != str.end()) {
		m_fileName.parseValue(*(++it));
	}
}

std::unique_ptr<ICommand> SourceFile::getInstance() const
{
	return std::make_unique<SourceFile>();
}

