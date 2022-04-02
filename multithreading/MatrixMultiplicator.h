#ifndef MULTITHREADING__MATRIXMULTIPLICATOR_H_
#define MULTITHREADING__MATRIXMULTIPLICATOR_H_

#include <mutex>
#include <thread>
#include <string>
#include "Matrix.h"

class MatrixMultiplicator
{
 public:
  Matrix Multiply(const Matrix& matrix1, const Matrix& matrix2);
  Matrix MultiplyByBlocks(const Matrix& matrix1, const Matrix& matrix2, int k);

 private:
  std::mutex lock_;

  void MultiplyBlocks(Matrix& result_matrix, const Matrix& matrix1, const Matrix& matrix2,
                                           int rows_amount_1, int columns_amount_1,
                                           int rows_amount_2, int columns_amount_2,
                                           int block_size);
};

#endif //MULTITHREADING__MATRIXMULTIPLICATOR_H_
