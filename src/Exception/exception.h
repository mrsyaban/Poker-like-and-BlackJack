#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
using namespace std;

struct NumberInputException : public exception
{
    const char *what() const throw()
    {
        return "Angka masukan tidak valid";
    }
};

struct FileException : public exception
{
    const char *what() const throw()
    {
        return "File masukan tidak valid";
    }
};

struct AbilityException : public exception
{
    const char *what() const throw()
    {
        return "Ability tidak valid";
    }
};

#endif