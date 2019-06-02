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
    static void init();
    static CommandsPool* getInstance();
    std::shared_ptr<ICommand> findCommand(const std::string& str);

private:
	template <class T>
    void registrateCommand();

private:
    std::map<std::string, std::shared_ptr<ICommand>> m_commandPoolStorage;
    static CommandsPool* m_commandPool;
    static std::mutex m_mutex;
};

template <class T>
void CommandsPool::registrateCommand()
{
	m_commandPoolStorage[T::getName()] = std::make_shared<T>();
}

#endif // COMMANDSPOOL_H
