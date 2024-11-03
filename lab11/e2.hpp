#include <memory>
#include <vector>
#include <iostream>
class Matrix
{
private:
    int m_rows;
    int m_cols;
    std::shared_ptr<float> m_data;

public:
    // Constructor
    Matrix(int rows = 0, int cols = 0) : m_rows(rows), m_cols(cols), m_data(new float[rows * cols]) {}
    // copy constructor
    Matrix(const Matrix &other) : m_rows(other.m_rows), m_cols(other.m_cols), m_data(other.m_data) {}
    // assignment operator
    Matrix &operator=(const Matrix &other)
    {
        m_rows = other.m_rows;
        m_cols = other.m_cols;
        m_data = other.m_data;
        return *this;
    }
    // read and write
    float &operator()(int row, int col)
    {
        return m_data.get()[row * m_cols + col];
    }
    // read only
    float operator()(int row, int col) const
    {
        return m_data.get()[row * m_cols + col];
    }
    // add
    Matrix operator+(const Matrix &other) const
    {
        Matrix result(m_rows, m_cols);
        for (int i = 0; i < m_rows * m_cols; ++i)
        {
            result.m_data.get()[i] = m_data.get()[i] + other.m_data.get()[i];
        }
        return result;
    }
};
