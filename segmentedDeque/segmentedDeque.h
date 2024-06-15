#pragma once
#include "../base/sequence/implementations/arraySequenceImpl/arraySequence.h"

//заранее выделять буфер(с запасом)
template<typename T>
class SegmentedDeque {
private:
    MutableArraySequence<MutableArraySequence<T> *> *segments;
    int segmentSize{10}; // длина 1 сегмента
    int currentSize{1}; // сколько используется сегментов на данный момент - 500 индекс
    int capacity{1000}; // длина резерва
    int start{500};
    int last{}; // index самого последнего элемента
    int first{}; // index самого первого эдемента
public:
    SegmentedDeque() = default;
    SegmentedDeque(int segmentSize = int()) {
        if (segmentSize <= 0) {
            throw std::invalid_argument("Segment currentSize and total length must be positive.");
        }

        this -> segmentSize = segmentSize;
        this -> segments = new MutableArraySequence<MutableArraySequence<T> *>();
        this -> last = segmentSize / 2;
        this -> first = segmentSize / 2;

        for (int i = 0; i < capacity; i++) {
            this -> segments -> append(new MutableArraySequence<T>(segmentSize));
        }
    }

    ~SegmentedDeque() {
        for (int i = 0; i < this -> segments -> getLength(); i ++) {
            delete segments -> get(i);
        }
    }

    int getSegmentSize() const;
    int getCurrentSize() const;
    int getCapacity() const;
    SegmentedDeque<T> *pushBack(T element);
    SegmentedDeque<T> *pushFront(T element);
    T *popBack();
    T *popFront();
    T peekBack() const;
    T peekFront() const;
};

template<typename T>
int SegmentedDeque<T>::getCapacity() const {
    return this -> capacity;
}

template<typename T>
int SegmentedDeque<T>::getCurrentSize() const {
    return this -> currentSize;
}

template<typename T>
int SegmentedDeque<T>::getSegmentSize() const {
    return this -> segmentSize;
}

template<typename T>
SegmentedDeque<T> *SegmentedDeque<T>::pushBack(T element) {
    MutableArraySequence<T> *lastSegment = this -> segments -> get(start + getCurrentSize() - 1);

    if(last == getSegmentSize() - 1) {
        this -> last = 0;

        if (start + this -> getCurrentSize() == capacity) {
            this -> segments -> append(new MutableArraySequence<T>(segmentSize)) -> getLast() -> set(last, element);
            this -> currentSize += 1;

            for (int i = 0; i < this -> getCapacity() / 2; i++) {
                 this -> segments -> append(new MutableArraySequence<T>());
            }

            return this;
        }

        this -> currentSize += 1;
        this -> segments -> get(start + getCurrentSize() - 1) -> set(last, element);

        return this;
    }

    this -> last += 1;
    lastSegment -> set(last, element);

    return this;
}

template<typename T>
SegmentedDeque<T> *SegmentedDeque<T>::pushFront(T element) {
    MutableArraySequence<T> *firstSegment = this -> segments -> get(start);

    if (first == 0) {
        this -> first = segmentSize - 1;

        if (start == 0) {
            this -> segments -> prepend(new MutableArraySequence<T>(segmentSize));
            this -> currentSize += 1;
            this -> start += this -> getCapacity() / 2;  // Сдвигаем start

            for (int i = 0; i < this -> getCapacity() - 1; i++) {
                this -> segments -> prepend(new MutableArraySequence<T>(segmentSize));
            }
        } else {
            this -> start -= 1;
            this -> currentSize += 1;
        }

        this -> segments -> get(start) -> set(first, element);
        return this;
    }

    this -> first -= 1;
    firstSegment -> set(first, element);

    return this;
}


template<typename T>
T SegmentedDeque<T>::peekFront() const {
    return this -> segments -> get(start) -> get(first);
}

template<typename T>
T SegmentedDeque<T>::peekBack() const {
    return this -> segments -> get(start + getCurrentSize() - 1) -> get(last);
}

template<typename T>
T *SegmentedDeque<T>::popFront() {
    MutableArraySequence<T> *firstSegment = this -> segments -> get(start);
    T *element = new T(firstSegment -> get(first));

    if (first == segmentSize - 1) {
        this -> first = 0;
        start += 1; // сегмент с интексом fisrt больше не успользуется
        this -> currentSize -= 1;
    }
    else {
        this -> first += 1;
    }

    return element;
}

template<typename T>
T *SegmentedDeque<T>::popBack() {
    MutableArraySequence<T> *lastSegment = this -> segments -> get(start + getCurrentSize() - 1);
    T *element = new T(lastSegment -> get(last));
    // подумать над удалением

    if (last == 0) {
        last = segmentSize - 1;
        this -> currentSize -= 1;
    }
    else {
        this -> last -= 1;
    }

    return element;
}