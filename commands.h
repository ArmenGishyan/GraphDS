#ifndef COMMANDS_H
#define COMMANDS_H
#include <string>
#include <memory>
#include <utility>
#include <vector>
#include <unordered_set>

#include "arguments.h"

class ICommand
{
public:
    ICommand();
	ICommand(const std::string& name) : m_name(name) {}
    virtual ~ICommand() = 0;
    virtual void execute() = 0;
    virtual std::unique_ptr<ICommand> getInstance() const = 0;
	//std::string getName() { return m_name; }
	void setName(const std::string name) { m_name = name; }
    virtual void parseArguments(const std::vector<std::string>& str) = 0;

protected:
	virtual void initArguments() {}

private:
	std::string m_name;
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
        return "create_graph";
    }
	void initArguments() override;

private:
	//std::vector<Arguments*> m_argumentsList;
    IntArg m_nodeCount;

};

class Print : public ICommand
{
public:
	static std::string getName() { return "print"; }
	void execute() override;
	void parseArguments(const std::vector<std::string>& str) override {}
	std::unique_ptr<ICommand> getInstance() const override;
	void initArguments() override {}

};

class ConnectNodes : public ICommand
{
public:
	ConnectNodes();
	static std::string getName() { return "conn_nodes"; }
	void execute() override;
	void parseArguments(const std::vector<std::string>& str) override;
	std::unique_ptr<ICommand> getInstance() const override;
	void initArguments() override {}

private:
	StringArg m_firstNode;
	StringArg m_secondNode;
};

class SourceFile : public ICommand
{
public:
	SourceFile();
	static std::string getName() { return "source"; }
	void execute() override;
	void parseArguments(const std::vector<std::string>& str) override;
	std::unique_ptr<ICommand> getInstance() const override;
	void initArguments() override {}

private:  
	StringArg m_fileName;

};

#endif // COMMANDS_H
