#include "CustomDynamicArray.h"

int main() {
    CustomDynamicArray array(100);
    array.print();
    writeArrayInNewFile("test", array);
}