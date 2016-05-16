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
        }

        vector(size_t n) {
            this->array = new ValueT[n];
        }

        vector(size_t n, const ValueT& val) {
            this->array = new ValueT[n];
            this->push_back(val);
        }

        virtual ~vector() {

        }

        bool empty() const noexcept {

        }

        size_t size() const noexcept {

        }

        size_t capacity() const noexcept {

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
    };
}
#endif //CPP_BHT_SOSE16_A03_MY_VECTOR_H
