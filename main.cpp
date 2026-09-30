#include <iostream>
#include <ostream>

#include "CustomDynamicArray.h"

int main() {
    //Создание массива конструктором по умолчанию
    CustomDynamicArray a;
    //Создаём массив конструктором с параметром
    CustomDynamicArray b(10);
    //Проверяем конструктор копирования
    CustomDynamicArray c(b);
    //Проверяем функцию вывода на экран
    a.print();
    //Проверяем что массив динамический
    int length;
    std::cout << "Введите длину массива: ";
    std::cin >> length;
    CustomDynamicArray d(length);
    d.print();
    //Проверяем глобальную функцию записи массива в файл
    writeArrayInNewFile("newFile", d);
    //Проверяем операцию присваиания
    CustomDynamicArray e = c;
    e.print();
    //Проверяем постфиксный "++"
    e++;
    e.print();
    //Проверяем "-"
    e - 5;
    e.print();

}