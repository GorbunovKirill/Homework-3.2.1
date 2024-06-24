﻿#include <iostream>
#include <memory>

class smart_array {
private:
    int* data;
    int size;
    int capacity; 

public:
    explicit smart_array(int n) : size(0), capacity(n) {
        data = new int[capacity];
    }

    ~smart_array() {
        delete[] data;
    }

    void add_element(int value) {
        if (size >= capacity) {
            capacity *= 2;
            int* new_data = new int[capacity];
            for (int i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }

            delete[] data;
            data = new_data;
        }
        data[size] = value;

        size++;
    }

    int get_element(int index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }
};

int main() {
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    } catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
