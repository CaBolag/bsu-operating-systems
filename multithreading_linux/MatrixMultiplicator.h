#ifndef MULTITHREADING__MATRIXMULTIPLICATOR_H_
#define MULTITHREADING__MATRIXMULTIPLICATOR_H_

#include <pthread.h>
#include "Matrix.h"

class MatrixMultiplicator
{
 public:
    MatrixMultiplicator() = default;
  Matrix Multiply(const Matrix& matrix1, const Matrix& matrix2);
  Matrix MultiplyByBlocks(const Matrix& matrix1, const Matrix& matrix2, int k);

 private:

    pthread_mutex_t lock_;

  struct MultiplyBlocksArguments
  {
      pthread_mutex_t& lock_;
    Matrix&  result_matrix_;
    const Matrix& matrix1_;
    const Matrix& matrix2_;
    int rows_amount1_;
    int columns_amount1_;
    int rows_amount2_;
    int columns_amount2_;
    int block_size_;

    MultiplyBlocksArguments(pthread_mutex_t& lock, Matrix& result_matrix, const Matrix& matrix1, const Matrix& matrix2,
                           int rows_amount_1, int columns_amount_1, int rows_amount_2, int columns_amount_2, int block_size);
  };

    static void* MultiplyBlocks(void* argument);
};

#endif //MULTITHREADING__MATRIXMULTIPLICATOR_H_
