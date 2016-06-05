//
// Created by Timo Raschke and Khaled Reguieg on 09.05.2016.
//

#ifndef CPP_BHT_SOSE16_A03_MY_VECTOR_H
#define CPP_BHT_SOSE16_A03_MY_VECTOR_H

namespace my {
    template <typename ValueT>
    class vector {
    public:
        vector() {
            this->array = new ValueT[0];
            this->size_ = 0;
            this->capacity_ = 0;
        }

        vector(size_t n) {
            this->array = new ValueT[n];
            this->size_ = 0;
            this->capacity_ = n;
        }

        vector(size_t n, const ValueT& val) {
            this->array = new ValueT[n];
            this->capacity_ = n;
            this->size_ = n;
            for (int i = 0; i < n; ++i) {
                this->array[i] = val;
            }
        }

        /**
         * Copy-Constructor
         */
        vector(const vector& rhs)
                : size_(rhs.size_),
                  capacity_(rhs.capacity_)
        {
            array = new ValueT[capacity_];
            for (int i = 0; i < capacity_; ++i) {
                array[i] = rhs.array[i];
            }
        }

        /**
         * Copy-Assignment
         */
        vector& operator= (const vector& rhs) {
            this->size_ = rhs.size_;
            this->capacity_ = rhs.capacity_;
            delete[] array;
            array = new ValueT[capacity_];
            for (int i = 0; i < capacity_; ++i) {
                array[i] = rhs.array[i];
            }
            return *this;
        }

        virtual ~vector() {
            delete[] this->array;
        }

        /**
         * Liefert zurück, ob sich Elemente in dem Array befinden.
         */
        bool empty() const noexcept {
            return this->size_ == 0;
        }

        /**
         * Liefert die Anzahl der enthaltenen Elemente zurück
         */
        size_t size() const noexcept {
            return this->size_;
        }

        /**
         * Liefert die Anzahl der Elemente zurück, für die insgesamt Platz in dem Array reserviert ist.
         */
        size_t capacity() const noexcept {
            return this->capacity_;
        }

        /**
         * Löscht die enthaltenen Elemente und ändert nichts an der Kapazität.
         */
        void clear() noexcept {
            this->size_= 0;
        }

        /**
         * Reserviert Platz für mindestens die angegebene Menge von Elementen
         */
        void reserve(size_t new_capacity) {
            if(new_capacity == this->capacity_)
                return;
            ValueT* tempArray = new ValueT[new_capacity];
            if (new_capacity >= size_) {
                this->capacity_ = new_capacity;
                for (int i = 0; i < size_; ++i) {
                    tempArray[i] = this->array[i];
                }
            } else {
                for (int i = 0; i < new_capacity; ++i) {
                    tempArray[i] = this->array[i];
                }
            }
            delete[] this->array;
            this->array = tempArray;
        }

        /**
         * Reduziert den reservierten Speicherplatz so, dass gerade die aktuell enthaltenen Elemente hinein passen
         */
        void shrink_to_fit() {
            reserve(this->size_);
        }

        /**
         * fügt ein neues Element als letztes Element des Arrays ein. Dazu muss der reservierte Platz ggf.
         * (smart) vergrößert werden.
         */
        void push_back(const ValueT& val) {
            if (this->size_ == this->capacity_) {
                reserve(this->capacity_ + 1);
            }
            this->array[this->size_++] = val;
        }

        /**
         * nimmt das letzte Element aus dem Arrays heraus und liefert es zurück.
         * Dabei soll der reservierte Platz nicht schrumpfen.
         */
        ValueT pop_back() {
            return this->array[--this->size_];
        }

        /**
         * liefert eine Referenz auf das gewünschte Element aus dem Array zurück.
         * Dies soll sowohl lesend (auch für c onst- Objekte) als auch schreibend möglich sein.
         */
        ValueT operator[](size_t i) const {
            return this->array[i];
        }

        ValueT& operator[](size_t i) {
            return this->array[i];
        }

        /**
         * Funktioniert wie der operator[], prüft jedoch, ob der angegebene Index gültig ist, und wirft eine
         * aussagekräftige Exception vom Typ std::out_of_bounds wenn nicht.
         */
        ValueT at(size_t i) const {
            if (i > (this->size_ - 1) || i < 0) {
                throw std::out_of_range("Undefined index.");
            } else {
                return this->array[i];
            }
        }

        ValueT& at(size_t i) {
            if (i > (this->size_ - 1) || i < 0) {
                throw std::out_of_range("Undefined index.");
            } else {
                return this->array[i];
            }
        }

        // vector(vector<ValueT> const &) = delete;
        // vector<ValueT>& operator = (vector<ValueT> const &) = delete;
    private:
        ValueT* array;
        size_t size_;
        size_t capacity_;
    };
}
#endif //CPP_BHT_SOSE16_A03_MY_VECTOR_H
