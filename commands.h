#ifndef COMMANDS_H
#define COMMANDS_H
#include <string>
#include <memory>
#include <utility>
#include <vector>

#include "arguments.h"

class ICommand
{
public:
    ICommand();
    virtual ~ICommand() = 0;
    virtual void execute() = 0;
    virtual std::unique_ptr<ICommand> getInstance() const = 0;
    static std::string getName();
    virtual void parseArguments(const std::vector<std::string>& str) = 0;

};

class CreateGraph : public ICommand
{
public:
    CreateGraph();
    void execute() override;
    void parseArguments(const std::vector<std::string>& str) override;
    std::unique_ptr<ICommand> getInstance() const override;
    static std::string getName()
    {
        return "Create_Graph";
    }

private:
    IntArg m_nodeCount;

};


#endif // COMMANDS_H
