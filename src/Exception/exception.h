#ifndef EXCEPTION_H
#define EXCEPTION_H

using namespace std;

class baseException {
    public:
        virtual const char *what() const throw() = 0;
};

class NumberInputException : public baseException
{
    const char *what() const throw()
    {
        return "\033[1;31mInput number not valid!\033[0m";
    }
};

class FileException : public baseException
{
    const char *what() const throw()
    {
        return "Input file not valid!";
    }
};

class AbilityException : public baseException
{
    const char *what() const throw()
    {
        return "Ability not valid";
    }
};

class playerException : public baseException
{
    const char *what() const throw()
    {
        return "Players input name not valid!";
    }
};

class inputException : public baseException
{
    const char *what() const throw()
    {
        return "Input not valid!";
    }
};

class abilitylessException : public baseException
{
    const char *what() const throw()
    {
        return "Input not valid!";
    }
};
#endif