#include <bits/stdc++.h> // or #include <iostream>

#include "Exceptions.h" // exceptions file
#include "LinkedList.h" // one linked list file

signed int main(void) {
    try {
        // Создание списка
        OneLinkedList<int> list;

        // Добавление элементов
        std::cout << "Adding elements to the list..." << std::endl;
        list.push_back(10);
        list.push_back(20);
        list.push_front(5);

        std::cout << "List after adding elements: ";
        list.print(); // Output: 5 10 20

        // Доступ по индексу
        std::cout << "\nAccessing element at index 1: " << list[1] << std::endl; // Output: 10

        // Вставка элемента
        std::cout << "\nInserting element 15 at index 1..." << std::endl;
        list.insert(1, 15);

        std::cout << "List after insertion: ";
        list.print(); // Output: 5 15 10 20

        // Удаление элемента
        std::cout << "\nErasing element at index 2..." << std::endl;
        list.erase(2);

        std::cout << "List after erasure: ";
        list.print(); // Output: 5 15 20

        // Проверка наличия элемента
        std::cout << "\nChecking if list contains 15: " 
                  << (list.contains(15) ? "Yes" : "No") << std::endl; // Output: Yes

        // Очистка списка
        std::cout << "\nClearing the list..." << std::endl;
        list.clear();

        std::cout << "List after clearing: ";
        list.print(); // Output: (пустой список)

    } 
    catch(const LinkedListInvalidOperationError & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const LinkedListNullPointerError & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const LinkedListEmptyError & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const LinkedListIndexError & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0; 
}
