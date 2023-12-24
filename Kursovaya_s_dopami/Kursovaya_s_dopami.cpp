#include <iostream>
#include <vector>

class Node {
public:
    int key;
    Node* p;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->key = value;
        newNode->p = top;
        top = newNode;
    }

    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
            top = top->p;
            std::cout << "Вы удалили элемент: " << temp->key << std::endl;
            delete temp;
        }
        else {
            std::cout << "Стек пуст." << std::endl;
        }
    }

    void remove() {
        while (!isEmpty()) {
            pop();
        }
        std::cout << "Стек удален." << std::endl;
    }

    void copy(Stack& otherStack) {
        Node* temp = top;
        while (temp != nullptr) {
            otherStack.push(temp->key);
            temp = temp->p;
        }
        std::cout << "Стек скопирован." << std::endl;
    }

    int length() {
        int count = 0;
        Node* temp = top;
        while (temp != nullptr) {
            count++;
            temp = temp->p;
        }
        return count;
    }

    void displayContent() {
        Node* temp = top;
        std::cout << "Содержимое стека: ";
        while (temp != nullptr) {
            std::cout << temp->key << " ";
            temp = temp->p;
        }
        std::cout << std::endl;
    }
    //Доп. задание
    void reverse() {                   //Инвертирование
        std::vector<int> elements;

        // Помещаем элементы стека в вектор
        Node* temp = top;
        while (temp != nullptr) {
            elements.push_back(temp->key);
            temp = temp->p;
        }

        // Очищаем стек
        remove();

        // Помещаем элементы обратно в стек, инвертированно
        for (int i = elements.size() - 1; i >= 0; i--) {
            push(elements[i]);
        }
        std::cout << "Стек инвертирован." << std::endl;
    }
    void merge(Stack& otherStack) {                             //Сложение      
        // Помещаем элементы из второго стека в текущий
        Node* temp = otherStack.top;
        while (temp != nullptr) {
            push(temp->key);
            temp = temp->p;
        }
        std::cout << "Стеки сложены." << std::endl;
    }
    void removeDuplicates() {                                   //Удаление дубликатов
        std::vector<int> elements;
        Node* temp = top;
        while (temp != nullptr) {
            elements.push_back(temp->key);
            temp = temp->p;
        }

        // Очищаем стек
        remove();

        // Помещаем уникальные элементы обратно в стек
        for (int i = 0; i < elements.size(); i++) {
            bool isDuplicate = false;
            for (int j = i + 1; j < elements.size(); j++) {
                if (elements[i] == elements[j]) {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate) {
                push(elements[i]);
            }
        }
        std::cout << "Дубликаты в стеке удалены." << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Stack myStack;
    Stack newStack;

    while (true) {
        std::cout << "\nВыберите операцию:\n";
        std::cout << "1. Добавить элемент\n";
        std::cout << "2. Удалить элемент и вывести на экран\n";
        std::cout << "3. Очистить весь стек\n";
        std::cout << "4. Получить длину стека\n";
        std::cout << "5. Вывести содержимое стека\n";
        std::cout << "6. Скопировать стек в новый объект\n";
        std::cout << "7. Инвертировать стек\n";
        std::cout << "8. Сложить стеки\n";
        std::cout << "9. Удалить дубликаты\n";
        std::cout << "10. Выйти из программы\n";
        std::cout << "Выбор: ";

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            int element;
            std::cout << "Введите элемент для добавления: ";
            std::cin >> element;
            myStack.push(element);
            std::cout << "Элемент добавлен." << std::endl;
            break;

        case 2:
            myStack.pop();
            break;

        case 3:
            myStack.remove();
            break;

        case 4:
            std::cout << "Длина стека: " << myStack.length() << std::endl;
            break;

        case 5:
            myStack.displayContent();
            break;

        case 6:
            myStack.copy(newStack);
            std::cout << "Новый стек создан." << std::endl;
            break;
        case 7:
            myStack.reverse();
            break;

        case 8:
            std::cout << "Сливаем текущий стек с новым...\n";
            myStack.merge(newStack);
            break;

        case 9:
            myStack.removeDuplicates();
            break;

        case 10:
            return 0;


        default:
            std::cout << "Такой опции нет." << std::endl;
            break;
        }
    }


    return 0;
}