#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>    // for size_t
#include <stdexcept>  // for out_of_range

template <typename T>
class Vector {
private:
    T* data_;
    size_t size_;
    size_t capacity_;

public:
    Vector() : data_(nullptr), size_(0), capacity_(0) {}

    Vector(size_t size) : data_(new T[size]), size_(size), capacity_(size) {}

    Vector(const Vector& other) : data_(new T[other.capacity_]), size_(other.size_), capacity_(other.capacity_) {
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    ~Vector() {
        delete[] data_;
    }

    bool empty() const {
        return size_ == 0;
    }

    T& back() {
        if (size_ == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data_[size_ - 1];
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data_;
            data_ = new T[other.capacity_];
            size_ = other.size_;
            capacity_ = other.capacity_;
            for (size_t i = 0; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }

    void push_back(const T& value) {
        if (size_ == capacity_) {
            size_t new_capacity = capacity_ == 0 ? 1 : capacity_ * 2;
            resizeCapacity(new_capacity);
        }
        data_[size_++] = value;
    }

    void pop_back() {
        if (size_ == 0) {
            throw std::out_of_range("Vector is empty");
        }
        --size_;
    }

    void clear() {
        delete[] data_;
        data_ = nullptr;
        size_ = 0;
        capacity_ = 0;
    }

    size_t size() const {
        return size_;
    }

    T& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    T* begin() const {
        return data_;
    }

    T* end() const {
        return data_ + size_;
    }

    void resizeCapacity(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = std::move(data_[i]);
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

    void resize(size_t new_size, const T& value = T()) {
        if (new_size < size_) {
            size_ = new_size;
        } else if (new_size > size_) {
            if (new_size > capacity_) {
                resizeCapacity(new_size);
            }
            for (size_t i = size_; i < new_size; ++i) {
                data_[i] = value;
            }
            size_ = new_size;
        }
    }

    void erase(T* first, T* last) {
        if (first < data_ || last > data_ + size_ || first >= last) {
            // Invalid range or pointers
            return;
        }

        size_t elementsToRemove = last - first;
        T* newEnd = first;

        // Shift elements to the left to overwrite the removed range
        std::move(last, data_ + size_, newEnd);

        // Update the size of the vector
        size_ -= elementsToRemove;
    }
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T* pointer;
    typedef const T* const_pointer;

    // Define iterator types
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    // Allow std::back_insert_iterator to access private members
    friend class std::back_insert_iterator<Vector>;
};
template<typename T>
class VectorInsertIterator {
private:
    Vector<T>& vec_;

public:
    explicit VectorInsertIterator(Vector<T>& vec) : vec_(vec) {}

    VectorInsertIterator& operator=(const T& value) {
        vec_.push_back(value);
        return *this;
    }


};
#endif
