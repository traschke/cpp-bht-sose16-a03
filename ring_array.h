//
// Created by Khaled Reguieg on 05.06.2016.
//

#ifndef CPP_BHT_SOSE16_A03_RING_ARRAY_H
#define CPP_BHT_SOSE16_A03_RING_ARRAY_H

#include <cstddef>
#include "my_vector.h"

template <typename ValueT>
class ring_array {
public:

    /**
     * Der default constructor erzeugt ein leeres Ringarray (Größe 0).
     */
    ring_array(size_t size_ = 0)
        : vector_(my::vector<ValueT>(size_)), position_(0) {}

    // Copy-Const
    ring_array(const ring_array& rhs) {
        vector_ = rhs.vector_;
        position_ = rhs.position_;
    }

    ring_array operator=(const ring_array& rhs) {
        if (this != &rhs) {
            delete vector_;
            vector_ = rhs.vector_;
            position_ = rhs.position_;
        }
        return  *this;
    }

    /**
     * Eine Methode size() gibt die Länge des Ring-Arrays zurück.
     */
    size_t  size() const {
        return vector_.size();
    }

    /**
     * Eine Memberfunktion push(value) fügt einen Wert am Ende des
     * Ringarrays ein.
     */
    void push(const ValueT& value) {
        vector_[position_++] = value;
        position_ = position_ % vector_.capacity();
    }

    /**
     * Eine Methode resize() verändert die Länge des Arrays. Dabei sollen die
     * letzten eingefügten Werte in ihrer Reihenfolge erhalten bleiben. Wird das
     * Array länger so sind die hinzukommenden Werte undefiniert. Wird das
     * Array kürzer so sollen die ältesten Werte verworfen werden.
     */
    void resize(int newSize) {
        if (newSize > vector_.capacity()) {
            position_ += vector_.capacity();
            vector_.reserve(newSize);
        } else {
            my::vector<ValueT> tempVec = my::vector<ValueT>();
            int oldIndex = vector_.capacity() - (newSize - position_);
            for (int i = oldIndex; i < newSize + oldIndex; ++i ) {
                tempVec.push_back( this->operator [](i) );
            }
            position_ = 0;
            vector_ = tempVec;
        }

    }

    ValueT operator[] (size_t index) const {
        return vector_[(vector_.capacity() + index + position_) % vector_.capacity()];
    }

    ValueT& operator[] (size_t index) {
        size_t i = (index + position_ + vector_.capacity()) % vector_.capacity();
        return vector_[i];
    }

private:
    my::vector <ValueT> vector_;
    size_t position_;


};


#endif //CPP_BHT_SOSE16_A03_RING_ARRAY_H
