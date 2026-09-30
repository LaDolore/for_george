#include "CustomDynamicArray.h"

#include <fstream>
#include <iostream>
#include "random"

CustomDynamicArray::CustomDynamicArray() {
    m_size = 100;
    m_arr = new int[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = generateRandomNumbers();
    }
}

CustomDynamicArray::CustomDynamicArray(const int size) :
        m_size(size)
{
    if (m_size < 1) {
        std::cerr << "Значение массива должно быть больше чем 0" << std::endl;
        return;
    }
    m_arr = new int[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = generateRandomNumbers();
    }
}

CustomDynamicArray::CustomDynamicArray(const CustomDynamicArray &arr) :
        m_size(arr.m_size)
{
    m_arr = new int[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = arr.m_arr[i];
    }
}

void CustomDynamicArray::print() const {
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_arr[i] << " ";
    }
    std::cout << std::endl;
}

void writeArrayInNewFile(const std::string& fileName, const CustomDynamicArray& arr) {
    std::ofstream outFile;
    outFile.open(fileName);
    for (int i = 0; i < arr.m_size; ++i) {
        outFile << i + 1 << " = " << arr.m_arr[i] << std::endl;
    }
    outFile.close();
}

CustomDynamicArray & operator-(CustomDynamicArray &arr, const int number) {
    if (arr.m_size < 1 || number == 0) {
            return arr;
        }else {
            for (int i = 0; i < arr.m_size; ++i) {
                arr.m_arr[i] -= number;
            }
        }
        return arr;
}

CustomDynamicArray& CustomDynamicArray::operator=(const CustomDynamicArray &arr) {
    if (this != &arr) {
        delete[] m_arr;
        m_size = arr.m_size;
        m_arr = new int[m_size];
        for (int i = 0; i < m_size; ++i) {
            m_arr[i] = arr.m_arr[i];
        }
    }
    return *this;
}

CustomDynamicArray& CustomDynamicArray::operator++(int) {
    if (m_size < 1) {
        return *this;
    }else {
        for (int i = 0; i < m_size; ++i) {
            if (i % 2 == 1) {
                ++m_arr[i];
            }
        }
    }
    return *this;
}

CustomDynamicArray::~CustomDynamicArray() {
    delete[] m_arr;
    m_arr = nullptr;
}

// CustomDynamicArray & CustomDynamicArray::operator&(CustomDynamicArray &arr) {
//     if (m_size < 1 || arr.m_size < 1) {
//         return m_arr <= arr.m_arr ? arr : *this;
//     }else {
//
//     }
// }

int CustomDynamicArray::generateRandomNumbers() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(m_minRandomNumber, m_maxRandomNumber);
    return dist(gen);
}