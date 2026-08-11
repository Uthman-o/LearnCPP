#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

class Matrix {
   private:
    size_t rows_;
    size_t cols_;
    std::vector<int> data_;

    size_t index(size_t row, size_t col) const {
        if (row >= rows_ || col >= cols_) {
            throw std::out_of_range("Matrix index out of range");
        }

        return row * cols_ + col;
    }

   public:
    Matrix(std::size_t rows, std::size_t cols) : rows_(rows), cols_(cols), data_(rows * cols_, 0) {}

    void set(size_t row, size_t col, int value) { data_[index(row, col)] = value; }

    int get(size_t row, size_t col) const { return data_[index(row, col)]; }

    void print() const {
        for (size_t r = 0; r < rows_; ++r) {
            for (size_t c = 0; c < cols_; ++c) {
                std::cout << get(r, c);

                if (c + 1 < cols_) {
                    std::cout << " ";
                }
            }
            std::cout << '\n';
        }
    }

    void transpose() {
        std::vector<int> transposed(data_.size());
        for (size_t r = 0; r < rows_; ++r) {
            for (size_t c = 0; c < cols_; ++c) {
                size_t oldIndex = r * cols_ + c;
                size_t newIndex = c * rows_ + r;

                transposed[newIndex] = data_[oldIndex];
            }
        }
        data_.swap(transposed);
        std::swap(rows_, cols_);
    }

    size_t rows() const { return rows_; }
    size_t cols() const { return cols_; }

    ~Matrix() { std::cout << "Matrix done\n"; }
};

int main() {
    Matrix A(2, 3);

    int v = 1;

    for (size_t r = 0; r < 2; ++r) {
        for (size_t c = 0; c < 3; ++c) {
            A.set(r, c, v++);
        }
    }
    // A.get(3, 1);
    A.transpose();

    assert(A.rows() == 3 && A.cols() == 2);
    assert(A.get(0, 0) == 1 && A.get(0, 1) == 4);
    assert(A.get(1, 0) == 2 && A.get(1, 1) == 5);
    assert(A.get(2, 0) == 3 && A.get(2, 1) == 6);

    A.transpose();

    assert(A.rows() == 2 && A.cols() == 3 && A.get(1, 2) == 6);

    // A.set(0, 0, 1);
    // A.set(0, 1, 2);
    // A.set(0, 2, 3);
    //
    // A.set(1, 0, 4);
    // A.set(1, 1, 5);
    // A.set(1, 2, 6);

    // A.transpose();

    A.print();

    return 0;
}
