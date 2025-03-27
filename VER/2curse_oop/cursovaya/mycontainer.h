#ifndef MYCONTAINER_H
#define MYCONTAINER_H

#include <vector>
#include <algorithm>

template<typename T>
class MyContainer {
public:
    class Iterator {
    public:
        Iterator(typename std::vector<T>::iterator it) : current(it) {}
        T &operator*() { return *current; }
        T *operator->() { return &(*current); }
        Iterator &operator++() { ++current; return *this; }
        bool operator!=(const Iterator &other) const { return current != other.current; }
    private:
        typename std::vector<T>::iterator current;
    };

    class ConstIterator {
    public:
        ConstIterator(typename std::vector<T>::const_iterator it) : current(it) {}
        const T &operator*() const { return *current; }
        const T *operator->() const { return &(*current); }
        ConstIterator &operator++() { ++current; return *this; }
        bool operator!=(const ConstIterator &other) const { return current != other.current; }
    private:
        typename std::vector<T>::const_iterator current;
    };

    void push_back(const T &value) { data.push_back(value); }

    template<typename Pred>
    void erase_if(Pred pred) {
        data.erase(std::remove_if(data.begin(), data.end(), pred), data.end());
    }

    void clear() { data.clear(); }

    Iterator begin() { return Iterator(data.begin()); }
    Iterator end() { return Iterator(data.end()); }

    ConstIterator begin() const { return ConstIterator(data.begin()); }
    ConstIterator end() const { return ConstIterator(data.end()); }

    int size() const { return (int)data.size(); }
    bool empty() const { return data.empty(); }

    T &operator[](int index) { return data[index]; }
    const T &operator[](int index) const { return data[index]; }

private:
    std::vector<T> data;
};

#endif // MYCONTAINER_H
