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
        data[i] = T(); // 기본값으로 초기화
    }
}

template<typename T>
inline SimpleVector<T>::SimpleVector(int capacity) : currentCapacity(capacity), currentSize(0) {
    data = new T[currentCapacity];
    for (int i = 0; i < currentCapacity; ++i) {
        data[i] = T(); // 기본값으로 초기화
    }
}

template<typename T>
inline SimpleVector<T>::SimpleVector(const SimpleVector& other) :currentSize(other.currentSize), currentCapacity(other.currentCapacity) {
    data = new T[currentCapacity];
    for (int i = 0; i < currentCapacity; ++i) {
        data[i] = other.data[i]; // 기존 데이터 복사
    }
}

template<typename T>
inline SimpleVector<T>::~SimpleVector() {
    delete[] data; // 동적 메모리 해제
}

template<typename T>
inline void SimpleVector<T>::resize() {
    int newCapacity = currentCapacity + 5; //기존 크기보다 5만큼 추가.
    T* newData = new T[newCapacity];

    for (int i = 0; i < currentSize; ++i) {
        newData[i] = data[i]; // 기존 데이터 복사
    }
    delete[] data; // 기존 메모리 해제
    data = newData;
    currentCapacity = newCapacity; //배열크기 초기화.
}

template<typename T>
inline void SimpleVector<T>::push_back(const T& value) {
    if (currentSize == currentCapacity) {
        resize(); // 용량 확장
    }
    data[currentSize] = value; // 데이터 추가
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


