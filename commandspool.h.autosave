
#ifndef COMMANDSPOOL_H
#define COMMANDSPOOL_H

#include <map>
#include <string>
#include <mutex>
#include <memory>
#include "commands.h"
#include <cassert>


class CommandsPool
{

private:
    CommandsPool();

public:
    template<class T>
    static void generateCommand();
    static void init();
    static CommandsPool* getInstance();
    std::unique_ptr<ICommand> findCommand(const std::string& str);

private:
    void registrateCommand(const std::string& name, std::unique_ptr<ICommand> command);

private:
    std::map<std::string, std::unique_ptr<ICommand>> m_commandPoolStorage;
    static CommandsPool* m_commandPool;
    static std::mutex m_mutex;
};

template <class T>
void CommandsPool::generateCommand()
{
    CommandsPool* pool = CommandsPool::getInstance();
    pool->registrateCommand(T::getName(), std::unique_ptr<T>());
}

#endif // COMMANDSPOOL_H
