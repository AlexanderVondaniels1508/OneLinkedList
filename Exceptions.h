#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

using std::string;
using std::exception;

class LinkedListIndexError : public std::exception 
{
public:
    explicit LinkedListIndexError(const char* message) : msg(message) 
    {   }
    const char* what() const noexcept override {return msg.c_str();}
protected:
    std::string msg;
};

class LinkedListEmptyError : public std::exception 
{
public:
    explicit LinkedListEmptyError(const char* message = "List is empty.") : msg(message) 
    {   }
    const char* what() const noexcept override {return msg.c_str();}
protected:
    std::string msg;
};

class LinkedListNullPointerError : public std::exception 
{
public:
    explicit LinkedListNullPointerError(const char* message = "Null pointer encountered.") : msg(message) 
    {   }
    const char* what() const noexcept override {return msg.c_str();}
protected:
    std::string msg;
};

class LinkedListInvalidOperationError : public std::exception 
{
public:
    explicit LinkedListInvalidOperationError(const char* message) : msg(message) 
    {   }
    const char* what() const noexcept override {return msg.c_str();}
protected:
    std::string msg;
};

#endif /*EXCEPTIONS_H*/ 