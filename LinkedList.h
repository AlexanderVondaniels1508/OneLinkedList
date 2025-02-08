#ifndef ONE_LINKED_LIST_HPP // the name this file
#define ONE_LINKED_LIST_HPP

#include <bits/stdc++.h> // or #include <iostream>
#include <string>
#include <memory>
#include "Exceptions.h" /* exception file of this class */

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <class T>
class Object 
{
public:
    T data{0};
    std::shared_ptr<Object<T>> next;

public:
   explicit Object() = default;

   explicit Object(T data) 
    {
        this->data = data;
        this->next = nullptr;
    }

    T get_data(void) const {
        return data;
    }

    std::shared_ptr<Object<T>> get_next(void) const {
        return next;
    }
};

template <class T>
class OneLinkedList 
{
public:
    using shared_ptr_obj = std::shared_ptr<Object<T>>;
    using type_item = T;
    using type_item_ptr = T*;
    using type_item_list = T&;

    shared_ptr_obj head{nullptr};
    shared_ptr_obj tail{nullptr};

    unsigned int count{0};

    shared_ptr_obj get_head(void) const 
    {
        return head;
    }
    shared_ptr_obj get_tail(void) const 
    {
        return tail;
    }
    class Iterator 
    {

    public:
        explicit Iterator(shared_ptr_obj node) : current(node) 
        { }
        Iterator& operator++(void) 
        {
            if (current) current = current->next;
            return *this;
        }
        Iterator operator++(int) 
        {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }
        bool operator==(const Iterator& other) const 
        {
            return current == other.current;
        }
        bool operator!=(const Iterator& other) const 
        {
            return !(*this == other);
        }
        type_item_list operator*() const 
        {
            if (!current) throw LinkedListNullPointerError("Iterator points to null.");
            return current->data;
        }

    private:
        shared_ptr_obj current;
    };

public:
    explicit OneLinkedList()
    {
        this->head = this->tail = nullptr;
    }
    explicit OneLinkedList(const OneLinkedList & other)
    {
        addlist(other);
    } 
    ~OneLinkedList() 
    {
        clear();
    }
    void pop_front(void)
    {
        if(head == nullptr)
            return;
            
        if(head == tail){
            head = tail = nullptr;
            return;
        }
        shared_ptr_obj node = head;
        head = node->next;
        if(head == nullptr)
            tail = nullptr;
        
    }

    void push_back(type_item data)
    {
        shared_ptr_obj node = std::make_shared<Object<T>>(data);
        if(head == nullptr) head = node;
        if(tail != nullptr) tail->next = node;
        tail = node;
        if(head == nullptr)
            head = node;
        
    }

    void push_front(type_item data)
    {
        shared_ptr_obj node = std::make_shared<Object<T>>(data);
        node->next = head;
        head = node;
        if(tail == nullptr) tail = node;
        count++;
    }

    void pop_back(void) 
    {
        if(tail == nullptr)
            return;
        
        if(head == tail){
            head = tail = nullptr;
            return;
        }
        shared_ptr_obj node = head;
        for( ; node->next != tail; node = node->next);
        node->next = nullptr;
        tail = node;
    }

    shared_ptr_obj getAt(int index)
    {
        if(index < 0)
            throw LinkedListIndexError("Invalid element index.");
        
        if(index == 0)
            return head;
        
        shared_ptr_obj node = head;
        int cnt{0};
        while(node != nullptr && cnt != index && node->next != nullptr){
            node = node->next;
            cnt++;
        }
        return (index == cnt) ? node : throw LinkedListIndexError("Invalid element index.");
    }

    void insert(int index, type_item data)
    {
        if(index < 0)
            throw LinkedListIndexError("Invalid element index.");
        
        if(index == 0)
            push_front(data);
            return;
        
        shared_ptr_obj left = getAt(index-1);
        if(left == nullptr) 
            return;
        
        shared_ptr_obj right = left->next;
        if(right == nullptr)
            return;
        
        shared_ptr_obj node = std::make_shared<Object<T>>(data);
        if(node == nullptr)
            return;
        
        left->next = node;
        node->next = right;
        if(right == nullptr) tail = node;
    }

    void erase(int index) 
    {
        if (index < 0) 
            throw LinkedListIndexError("Invalid element index.");
        if (index == 0) 
        {
            pop_front();
            return;
        }
        shared_ptr_obj left = getAt(index - 1);
        shared_ptr_obj node = left->next;
        if (!node) 
            return;
        
        left->next = node->next;
        if (node == tail) 
            tail = left;
    }

    void print() const {
        if(head == nullptr)
            return;
        
        shared_ptr_obj node = head;
        for(; node != nullptr; node = node->next)
        {
            std::cout << node->data << " ";
        }
        std::cout << std::endl;
    }

    type_item& operator[](int index)
    {
        if(index < 0)
        {
            throw LinkedListIndexError("Invalid element index.");
        }
        shared_ptr_obj node = getAt(index);
        return node->data;
    }

    void add_list(const OneLinkedList& other)
    {
        std::shared_ptr<Object<T>> curr = other.head;

        while (curr) 
        {
            push_back(curr->get_data());
            curr = curr->get_next();
        }
    }

    void clear(void) 
    {
        while (head) {
            shared_ptr_obj temp = head;
            head = head->next;
            temp.reset();
        }
        tail = nullptr; 
        count = 0; 
    }

    bool is_empty(void)
    {
        if(head == nullptr)
            return true;
        else
            return false;
    }

    bool contains(const T& value) const 
    {
    if (!head) 
        return false;
    shared_ptr_obj current = head;
    while (current) {
        if (current->data == value) 
            return true;
        current = current->next;
    }
    return false;
}

    OneLinkedList<T> clone() const 
    {
        OneLinkedList<T> newList;
        shared_ptr_obj current = head;
        while (current) {
            newList.push_back(current->data);
            current = current->next;
        }
    return newList;
}

};

#endif /* ONE_LINKED_LIST_HPP */
