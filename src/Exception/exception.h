#ifndef EXCEPTION_H
#define EXCEPTION_H

using namespace std;

class baseException {
    protected:
        virtual const char *what() const throw() = 0;
};

class NumberInputException : public baseException
{
    const char *what() const throw()
    {
        return "Input number not valid!";
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

#endif