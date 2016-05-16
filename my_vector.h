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

        //Buggy
        vector(size_t n, const ValueT& val) {
            this->array = new ValueT[n];
            this->push_back(val);
            this->size_ = 1;
            this->capacity_ = n;
        }

        virtual ~vector() {

        }

        bool empty() const noexcept {

        }

        size_t size() const noexcept {
            return this->size_;
        }

        size_t capacity() const noexcept {
            return this->capacity_;
        }

        void clear() noexcept {

        }

        void reserve(size_t new_capacity) {

        }

        void shrink_to_fit() {

        }

        void push_back(const ValueT& val) {

        }

        ValueT pop_back() {

        }

        ValueT operator[](size_t i) const {

        }

        ValueT& operator[](size_t i) {

        }

        /**
         * Same as operator[], checks if index is valid, throws std::out_of_bounds if not.
         */
        ValueT at(size_t i) const {

        }

        vector(vector<ValueT> const &) = delete;
        vector<ValueT>& operator = (vector<ValueT> const &) = delete;
    private:
        ValueT* array;
        size_t size_;
        size_t capacity_;
    };
}
#endif //CPP_BHT_SOSE16_A03_MY_VECTOR_H
