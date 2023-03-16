#ifndef EXCEPTION_H
#define EXCEPTION_H

using namespace std;

class BaseException {
    public:
        virtual const char *what() const throw() = 0;
};

class NumberInputException : public BaseException
{
    const char *what() const throw()
    {
        return "\033[1;31mInput number not valid!\033[0m";
    }
};

class FileException : public BaseException
{
    const char *what() const throw()
    {
        return "\033[1;31mInput file not valid!\033[0m";
    }
};

class AbilityException : public BaseException
{
    const char *what() const throw()
    {
        return "\033[1;31mAbility not valid\033[0m";
    }
};

class PlayerException : public BaseException
{
    public:
        const char *what() const throw()
        {
            return "\033[1;31mPlayers input name not valid!\033[0m";
        }
};

class InputException : public BaseException
{
    const char *what() const throw()
    {
        return "\033[1;31mInput not valid!\033[0m";
    }
};

class AbilitylessException : public BaseException
{
    const char *what() const throw()
    {
        return "\033[1;31mInput not valid!\033[0m";
    }
};

class AbilityNotAvailableException : public BaseException
{
    public :
        const char *what() const throw()
        {
            return "\033[1;31mThis ability is inactive! You can't use it anymore.\033[0m";
        }
};

class AbilityNotHaveException : public BaseException
{
    public:
        const char *what() const throw()
        {
            return "\033[1;31mYou don't have this ability : \033[0m";
        }
};
#endif