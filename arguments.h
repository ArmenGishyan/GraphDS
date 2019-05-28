#ifndef ARGUMENTS_H
#define ARGUMENTS_H
#include <string>

template <class T>
class Arguments
{
public:
    virtual ~Arguments() = 0;
    virtual void parseValue(const std::string& str) = 0;
    void setValue(const T& value)
    {
        m_value = value;
    }

    inline T getValue() const
    {
        return m_value;
    }
    std::string getName() {return m_name;}
    void setName(const std::string& name) {m_name = name;}

protected:
    T m_value;
    std::string m_name;
};

template <class T>
Arguments<T>::~Arguments()
{}

class IntArg : public Arguments<int>
{
public:
    void parseValue(const std::string& str) override;
};

#endif // ARGUMENTS_H
