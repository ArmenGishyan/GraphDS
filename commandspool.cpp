#include "commandspool.h"
#include "commands.h"
#include <memory>
#include <cassert>

CommandsPool* CommandsPool::m_commandPool = nullptr;
std::mutex CommandsPool::m_mutex;

CommandsPool::CommandsPool()
{
    
}

CommandsPool* CommandsPool::getInstance()
{
    CommandsPool::m_mutex.lock();

    if(m_commandPool == nullptr) {
        m_commandPool = new CommandsPool;
    }

    CommandsPool::m_mutex.unlock();
    return m_commandPool;
}



void CommandsPool::init()
{
    CommandsPool* pool = CommandsPool::getInstance();
	pool->registrateCommand<CreateGraph>();
	pool->registrateCommand<Print>();
	pool->registrateCommand<ConnectNodes>();
	pool->registrateCommand<SourceFile>();
	pool->registrateCommand<HasEulerianCircle>();
}

std::shared_ptr<ICommand> CommandsPool::findCommand(const std::string& str)
{
    auto command = m_commandPoolStorage.find(str);
    if(command == m_commandPoolStorage.end()) {
        return std::shared_ptr<ICommand>();
    }
    if(command->second.get() == nullptr)
    {
        //m_commandPoolStorage[str] = std::move(command->second.getInstance());
    }
    return m_commandPoolStorage[str];
}
