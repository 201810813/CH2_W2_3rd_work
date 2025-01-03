#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class SimpleVector {
private:
    T* data;
    int currentSize;
    int currentCapacity;
    void resize();

public:
    SimpleVector();
    SimpleVector(int capacity);
    SimpleVector(const SimpleVector& other);
    ~SimpleVector();
public:
    void push_back(const T& value);
    void pop_back();
    int size();
    int capacity();
    void sortData();
    T* getData();
};

template<typename T>
inline SimpleVector<T>::SimpleVector() : currentCapacity(10), currentSize(0) {
    data = new T[currentCapacity];
    for (int i = 0; i < currentCapacity; ++i) {
        data[i] = T(); // �⺻������ �ʱ�ȭ
    }
}

template<typename T>
inline SimpleVector<T>::SimpleVector(int capacity) : currentCapacity(capacity), currentSize(0) {
    data = new T[currentCapacity];
    for (int i = 0; i < currentCapacity; ++i) {
        data[i] = T(); // �⺻������ �ʱ�ȭ
    }
}

template<typename T>
inline SimpleVector<T>::SimpleVector(const SimpleVector& other) :currentSize(other.currentSize), currentCapacity(other.currentCapacity) {
    data = new T[currentCapacity];
    for (int i = 0; i < currentCapacity; ++i) {
        data[i] = other.data[i]; // ���� ������ ����
    }
}

template<typename T>
inline SimpleVector<T>::~SimpleVector() {
    delete[] data; // ���� �޸� ����
}

template<typename T>
inline void SimpleVector<T>::resize() {
    int newCapacity = currentCapacity + 5; //���� ũ�⺸�� 5��ŭ �߰�.
    T* newData = new T[newCapacity];

    for (int i = 0; i < currentSize; ++i) {
        newData[i] = data[i]; // ���� ������ ����
    }
    delete[] data; // ���� �޸� ����
    data = newData;
    currentCapacity = newCapacity; //�迭ũ�� �ʱ�ȭ.
}

template<typename T>
inline void SimpleVector<T>::push_back(const T& value) {
    if (currentSize == currentCapacity) {
        resize(); // �뷮 Ȯ��
    }
    data[currentSize] = value; // ������ �߰�
    ++currentSize;
}

template<typename T>
inline void SimpleVector<T>::pop_back() {
    if (currentSize > 0) {
        --currentSize;
        data[currentSize] = T();
    }
    return;
}

template<typename T>
inline int SimpleVector<T>::size() {
    return currentSize;
}

template<typename T>
inline int SimpleVector<T>::capacity() {
    return currentCapacity;
}

template<typename T>
inline void SimpleVector<T>::sortData()
{
    sort(data, data + currentSize);
}

template<typename T>
inline T* SimpleVector<T>::getData()
{
    return data;
}


