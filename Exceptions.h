#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

using std::string;
using std::exception;

/**
 * @brief Базовый класс для исключений связанных с односвязным списком.
 * 
 * Этот класс является производным от std::exception и используется как базовый класс для всех специфических исключений списка.
 * Он хранит сообщение об ошибке в виде строки.
 * 
 * @details Base class for exceptions related to the linked list.
 * This class is derived from std::exception and serves as a base class for all specific list exceptions.
 * It stores the error message as a string.
 */
class LinkedListIndexError : public std::exception 
{
public:

    explicit LinkedListIndexError () noexcept = default;
    /**
     * @brief Конструктор, принимающий строковое сообщение об ошибке.
     * 
     * @param message Сообщение об ошибке (const char*).
     * 
     * @details Constructor that accepts an error message.
     * @param message Error message (const char*).
     */
    explicit LinkedListIndexError(const char *message) noexcept : msg(message) 
    { }

    /**
     * @brief Копирующий конструктор для создания копии объекта исключения.
     * 
     * @param other Исключение, которое нужно скопировать.
     * 
     * @details Copy constructor for creating a copy of the exception object.
     * @param other The exception to copy.
     */
    explicit LinkedListIndexError(const LinkedListIndexError & other) noexcept : msg(other.msg) 
    { }

    /**
     * @brief Возвращает сообщение об ошибке в виде C-строки.
     * 
     * @return const char* - Указатель на строку с сообщением об ошибке.
     * 
     * @details Returns the error message as a C-string.
     * @return const char* - Pointer to the error message string.
     */
    const char *what() const noexcept override {return msg.c_str();}

    /**
     * @brief Виртуальный деструктор для обеспечения корректного освобождения памяти.
     * 
     * @details Virtual destructor to ensure proper memory cleanup.
     */
    virtual ~LinkedListIndexError() noexcept = default;

protected:
    /**
     * @brief Хранит сообщение об ошибке.
     * 
     * @details Stores the error message.
     */
    string msg;
};

/**
 * @brief Исключение, возникающее при попытке доступа к пустому списку.
 * 
 * Это исключение наследуется от LinkedListIndexError и используется, когда происходит попытка выполнить операцию над пустым списком.
 * 
 * @details Exception thrown when attempting to access an empty list.
 * This exception inherits from LinkedListIndexError and is used when an operation is attempted on an empty list.
 */
class LinkedListEmptyError : public LinkedListIndexError 
{
public:
    /**
     * @brief Конструктор с предустановленным сообщением "List is empty."
     * 
     * @details Constructor with a predefined message "List is empty."
     */
    explicit LinkedListEmptyError(const char *message="List is empty.") noexcept : LinkedListIndexError(message) { }

    /**
     * @brief Виртуальный деструктор для обеспечения корректного освобождения памяти.
     * 
     * @details Virtual destructor to ensure proper memory cleanup.
     */
    virtual ~LinkedListEmptyError() noexcept = default;
};

/**
 * @brief Исключение, возникающее при встрече нулевого указателя.
 * 
 * Это исключение наследуется от LinkedListIndexError и используется, когда происходит попытка работы с нулевым указателем.
 * 
 * @details Exception thrown when a null pointer is encountered.
 * This exception inherits from LinkedListIndexError and is used when a null pointer is encountered during operations.
 */
class LinkedListNullPointerError : public LinkedListIndexError 
{
public:
    /**
     * @brief Конструктор с предустановленным сообщением "Null pointer encountered."
     * 
     * @details Constructor with a predefined message "Null pointer encountered."
     */
    explicit LinkedListNullPointerError(const char *message="Null pointer encountered.") noexcept : LinkedListIndexError(message) { }

    /**
     * @brief Виртуальный деструктор для обеспечения корректного освобождения памяти.
     * 
     * @details Virtual destructor to ensure proper memory cleanup.
     */
    virtual ~LinkedListNullPointerError()=default;
};

/**
 * @brief Исключение, возникающее при попытке выполнения недопустимой операции.
 * 
 * Это исключение наследуется от LinkedListIndexError и используется, когда выполняется операция, которая не поддерживается или невозможна в текущем контексте.
 * 
 * @details Exception thrown when an invalid operation is attempted.
 * This exception inherits from LinkedListIndexError and is used when an operation is attempted that is not supported or impossible in the current context.
 */
class LinkedListInvalidOperationError : public LinkedListIndexError 
{
public:
    explicit LinkedListInvalidOperationError() noexcept = default;
    /**
     * @brief Конструктор, принимающий строковое сообщение об ошибке.
     * 
     * @param message Сообщение об ошибке (const char*).
     * 
     * @details Constructor that accepts an error message.
     * @param message Error message (const char*).
     */
    explicit LinkedListInvalidOperationError(const char *message) noexcept : LinkedListIndexError(message) { }

    /**
     * @brief Виртуальный деструктор для обеспечения корректного освобождения памяти.
     * 
     * @details Virtual destructor to ensure proper memory cleanup.
     */
    virtual ~LinkedListInvalidOperationError()=default;
};

#endif /*EXCEPTIONS_H*/
