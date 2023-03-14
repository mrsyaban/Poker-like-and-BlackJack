#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
using namespace std;

struct NumberInputException : public exception
{
    const char *what() const throw()
    {
        return "Input number not valid!";
    }
};

struct FileException : public exception
{
    const char *what() const throw()
    {
        return "Input file not valid!";
    }
};

struct AbilityException : public exception
{
    const char *what() const throw()
    {
        return "Ability not valid";
    }
};

struct playerException : public exception
{
    const char *what() const throw()
    {
        return "Players input name not valid!";
    }
};

#endif