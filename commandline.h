#ifndef COMMANDLINE_H
#define COMMANDLINE_H
#include <string>
#include "commands.h"

class ExecuteCommand;

        class CommandLine
{
public:
    enum class  Status
    {
      RUNNING,
      STOPED
    };
    CommandLine();
    void exec();
    void stop();

private:
    Status m_status;
    ExecuteCommand* m_execCommand;
};

class ExecuteCommand
{
public:
    std::shared_ptr<ICommand> findCommand(const std::string commandName);
    void execute(const std::string& str);
};
#endif // COMMANDLINE_H
