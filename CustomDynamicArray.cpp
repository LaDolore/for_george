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

CustomDynamicArray::CustomDynamicArray(int size) :
    m_size (size)
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

void CustomDynamicArray::print() {
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_arr[i] << " ";
    }
}

void writeArrayInNewFile(const std::string& fileName, const CustomDynamicArray& arr) {
    std::ofstream outFile;
    outFile.open(fileName);
    for (int i = 0; i < arr.m_size; ++i) {
        outFile << i + 1 << " = " << arr.m_arr[i] << std::endl;
    }
    outFile.close();
}

int CustomDynamicArray::generateRandomNumbers() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(m_minRandomNumber, m_maxRandomNumber);
    return dist(gen);
}
