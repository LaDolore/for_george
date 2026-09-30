#ifndef FOR_GEORGE_CUSTOMDYNAMICARRAY_H
#define FOR_GEORGE_CUSTOMDYNAMICARRAY_H
#include <string>

// void writeToNewFile(std::string fileName, CustomDynamicArray arr);

class CustomDynamicArray {
public:
    CustomDynamicArray();
    CustomDynamicArray(int size);
    CustomDynamicArray(const CustomDynamicArray& arr);
    void print() const;
    friend void writeArrayInNewFile(const std::string& fileName, const CustomDynamicArray& arr);
    CustomDynamicArray& operator=(const CustomDynamicArray& arr);
    CustomDynamicArray& operator++(int);
    friend CustomDynamicArray& operator-(CustomDynamicArray& arr, int number);
    ~CustomDynamicArray();
    // CustomDynamicArray& operator&(CustomDynamicArray& arr);
private:
    int m_size;
    int* m_arr = nullptr;

    int generateRandomNumbers() const;
    int m_minRandomNumber = -100;
    int m_maxRandomNumber = 100;
};


#endif //FOR_GEORGE_CUSTOMDYNAMICARRAY_H
