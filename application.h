#ifndef APPLICATION_H
#define APPLICATION_H


class Application
{
public:
    Application();
    enum class Mode
    {
       DEBUG,
       REALISE
    };
    static Mode getMode();
};

#endif // APPLICATION_H
