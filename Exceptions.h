#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

using std::string;
using std::exception;

class LinkedListIndexError : public std::exception 
{
public:
    explicit LinkedListIndexError(const char* message) noexcept : msg(message) 
    { }
    explicit LinkedListIndexError(const LinkedListIndexError & other) noexcept : msg(other.msg) 
    { }
    const char* what() const noexcept override {return msg.c_str();}
    virtual ~LinkedListIndexError () = default;
protected:
    string msg;
};

class LinkedListEmptyError : public LinkedListIndexError 
{
public:
    explicit LinkedListEmptyError(const char* message = "List is empty.") noexcept : LinkedListIndexError(message) 
    { }
    virtual ~LinkedListEmptyError () = default;
};

class LinkedListNullPointerError : public LinkedListIndexError 
{
public:
    explicit LinkedListNullPointerError(const char* message = "Null pointer encountered.") noexcept : LinkedListIndexError(message) 
    { }
    virtual ~LinkedListNullPointerError() = default;
};

class LinkedListInvalidOperationError : public LinkedListIndexError 
{
public:
    explicit LinkedListInvalidOperationError(const char* message) noexcept : LinkedListIndexError(message) 
    { }
    virtual ~LinkedListInvalidOperationError() = default;
};

#endif /*EXCEPTIONS_H*/ 
