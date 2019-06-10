#ifndef ARGUMENTS_H
#define ARGUMENTS_H
#include <string>

class Arguments
{
public:
	Arguments() {}
	Arguments(const std::string name) : m_name(name) {}
    virtual ~Arguments() = 0;
    virtual void parseValue(const std::string& str) = 0;
    std::string getName() {return m_name;}
    void setName(const std::string& name) {m_name = name;}


protected:
    std::string m_name;
};



class IntArg : public Arguments
{
public:
	IntArg() {}
	IntArg(const std::string name) : Arguments(name) {}
    void parseValue(const std::string& str) override;
	int getValue() { return m_value; }
	void setValue(int value) { m_value = value; }

private:
	int m_value;
};

class StringArg : public Arguments
{
public:
	StringArg() {}
	StringArg(const std::string name) : Arguments(name) {}
	void parseValue(const std::string& str) override;
	std::string getValue() { return m_value; }
	void setValue(const std::string& value) { m_value = value; }

private:
	std::string m_value;
};

#endif // ARGUMENTS_H
