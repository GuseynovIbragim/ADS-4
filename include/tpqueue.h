// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
  // Сюда помещается описание структуры "Очередь с приоритетами"
public:
void push(const T &data) {
TQueue<T> new_queue;

while (!queue_.isEmpty() && queue_.get().prior >= data.prior) {
new_queue.push(queue_.pop());
}

new_queue.push(data);

while (!queue_.isEmpty()) {
new_queue.push(queue_.pop());
}


while (!new_queue.isEmpty()) {
queue_.push(new_queue.pop());
}
}

T pop() { return queue_.pop(); }

void print() {
TQueue<T> tmp;
while (!queue_.isEmpty()) {
tmp.push(queue_.get());
std::cout << queue_.pop() << ' ';
}
std::cout << '\n';

while (!tmp.isEmpty()) {
queue_.push(tmp.pop());
}
}
private:
TQueue<T> queue_;
};

struct SYM {
  char ch;
  int  prior;
};

template<typename T>
class TQueue {
private:
    T *arr;
    int size;
    int begin,
        end;
    int count;
public:
    TQueue(int = 100);
    ~TQueue();

    void push(const T &);
    T pop();
    T get() const;
    bool isEmpty() const;
    bool isFull() const;
};

template<typename T>
TQueue<T>::TQueue(int sizeQueue) :
    size(sizeQueue),
    begin(0), end(0), count(0) {
    arr = new T[size + 1];
}

template<typename T>
TQueue<T>::~TQueue() {
    delete [] arr;
}

template<typename T>
void TQueue<T>::push(const T & item) {
    assert( count < size );

    arr[end++] = item;
    count++;

    if (end > size)
        end -= size + 1;
}

template<typename T>
T TQueue<T>::pop() {
    assert( count > 0 );

    T item = arr[begin++];
    count--;

    if (begin > size)
        begin -= size + 1;

    return item;
}

template<typename T>
T TQueue<T>::get() const {
    assert( count > 0 );
    return arr[begin];
}

template<typename T>
bool TQueue<T>::isEmpty() const {
  return count==0;
}

template<typename T>
bool TQueue<T>::isFull() const {
  return count==size;
}

ostream & operator<<(std::ostream &os, const SYM &s) {
    return os << '{' << s.ch << ", " << s.prior << '}';
}

#endif // INCLUDE_TPQUEUE_H_
