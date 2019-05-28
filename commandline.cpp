#include "commandline.h"
#include "helperfunctions.h"
#include "application.h"
#include <cassert>
#include "commandspool.h"
#include <memory>
#include <iostream>

CommandLine::CommandLine()
{
    m_status = Status::STOPED;
    m_execCommand = new ExecuteCommand;
}

void CommandLine::exec()
{
    m_status = Status::RUNNING;
    while (m_status == Status::RUNNING) {
        std::cout<<">>";
        std::string str;
        std::cin>>str;
        m_execCommand->execute(str);
    }
}

void ExecuteCommand::execute(const std::string &str)
{
    if(Application::getMode() == Application::Mode::DEBUG) {
        assert(!str.empty());
    }
    std::vector<std::string> vector = Helper::splitString(str);
    std::unique_ptr<ICommand> command = findCommand(vector[0]);
    if(Application::getMode() == Application::Mode::DEBUG) {
        assert(command.get()!= nullptr);
    }

    command->parseArguments(vector);
    command->execute();

}

std::unique_ptr<ICommand> ExecuteCommand::findCommand(const std::string commandName)
{
    CommandsPool* cPool = CommandsPool::getInstance();
    return std::move(cPool->findCommand(commandName));
}
