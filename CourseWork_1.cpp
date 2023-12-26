
#include <iostream>
#include <cstdlib>
using namespace std;


#define SIZE 10

class Node {
    int _key;
    Node* p;
    Node(int _key)
        : _key(_key) , p(nullptr){}
    ~Node() {
        delete p;
    }
};
// Класс для представления stack
class Stack
{
    int* arrow;
    int head;
    int cap;

public:
    Stack(int size = SIZE);         // конструктор
    ~Stack();
    void push(int);
    int pop();
    int peek();

    int size();
    bool isEmpty();
    bool isFull();
};

// Конструктор для инициализации stack
Stack::Stack(int size)
{
    arrow = new int[size];
    cap = size;
    head = -1;
}

Stack::~Stack() {                    // Деструктор для освобождения памяти
    delete[] arrow;
}

// функция для добавления элемента `new_element` в стек
void Stack::push(int new_element)
{
    if (isFull())
    {
        cout << "Переолнен  " << endl;
        return;
    }

    cout << "Добавили  " << new_element << endl;
    arrow[++head] = new_element;
}

// Вспомогательная функция для извлечения верхнего элемента из стека
int Stack::pop()
{
    // проверка на опустошение stack
    if (isEmpty())
    {
        cout << "Пустой  "<< endl;
        return 0;
    }

    cout << "Удален  " << peek() << endl;

    // уменьшаем размер стека на 1 
    return arrow[head--];
}

// функция для верхнего элемента стека
int Stack::peek()
{
    if (!isEmpty()) {
        return arrow[head];
    }
    else {
        return 0;
    }
}

// функция размера стека
int Stack::size() {
    return head + 1;
}

// функция для проверки, пуст стек
bool Stack::isEmpty() {
    return size() == 0;               
}

// функция для проверки, заполнен ли стек
bool Stack::isFull() {
    return size() == cap;
}




int main()
{
    setlocale(LC_ALL, "ru");
    Stack stack(5);

    stack.push(10);
    stack.push(20);
    stack.pop();
    stack.pop();
    stack.push(30);
    stack.pop();
    stack.push(40);
    stack.push(50);
    cout << "Верхний элемент " << stack.peek() << endl;
    cout << "Размер стека " << stack.size() << endl;

    stack.pop();

    if (stack.isEmpty()) {
        cout << "Стек пустой\n";
    }
    else {
        cout << "Стек не пустой\n";
    }

    return 0;
}





