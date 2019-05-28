#include "commandspool.h"
#include "commands.h"
#include <memory>
#include <cassert>

CommandsPool* CommandsPool::m_commandPool = nullptr;
std::mutex CommandsPool::m_mutex;

CommandsPool::CommandsPool()
{
    generateCommand<CreateGraph>();
}

CommandsPool* CommandsPool::getInstance()
{
    //CommandsPool::m_mutex.lock();

    if(m_commandPool == nullptr) {
        m_commandPool = new CommandsPool;
    }

    //CommandsPool::m_mutex.unlock();
    return m_commandPool;
}


void CommandsPool::registrateCommand(const std::string &name, std::unique_ptr<ICommand> command)
{
    assert(false);
    m_commandPoolStorage[name] = std::move(command);
}

void CommandsPool::init()
{
    CommandsPool::getInstance();
}

std::unique_ptr<ICommand> CommandsPool::findCommand(const std::string& str)
{
    auto command = m_commandPoolStorage.find(str);
    if(command == m_commandPoolStorage.end()) {
        return std::unique_ptr<ICommand>();
    }
    if(command->second.get() == nullptr)
    {
        m_commandPoolStorage[str] = std::move(command->second->getInstance());
    }
    return std::move(m_commandPoolStorage[str]);
}
