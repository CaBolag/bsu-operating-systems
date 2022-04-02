#include "MatrixMultiplicator.h"

Matrix MatrixMultiplicator::Multiply(const Matrix& matrix1, const Matrix& matrix2)
{
  if (matrix1.GetSize().second!=matrix2.GetSize().first)
  {
    throw std::invalid_argument("Invalid matrix size");
  }
  Matrix result_matrix = Matrix(matrix1.GetSize().first, matrix2.GetSize().second);

  for (int i = 0; i < result_matrix.GetSize().first; i++)
  {
    for (int j = 0; j < result_matrix.GetSize().second; j++)
    {
      for (int k = 0; k < result_matrix.GetSize().second; k++)
      {
        double result_element= matrix1.GetElement(i,k) * matrix2.GetElement(k,j);
        result_matrix.IncreaseElement(result_element,i,j);
      }
    }
  }
  return result_matrix;
}

Matrix MatrixMultiplicator::MultiplyByBlocks(const Matrix& matrix1, const Matrix& matrix2, int blocks_number)
{
  if (matrix1.GetSize().second!=matrix2.GetSize().first)
  {
    throw std::invalid_argument("Invalid matrix size");
  }

  if (matrix1.GetSize().first!=matrix1.GetSize().second || matrix2.GetSize().first!=matrix2.GetSize().second) {
    throw new std::invalid_argument("Matrices are not square");
  }

  if (matrix1.GetSize().first % blocks_number != 0)
  {
    throw std::invalid_argument("Invalid block number");
  }

  int block_size = matrix1.GetSize().first / blocks_number;
  Matrix result_matrix = Matrix(matrix1.GetSize().first, matrix2.GetSize().second);
  std::vector<std::thread> threads;
  for (int i = 0; i < result_matrix.GetSize().first; i += block_size)
  {
    for (int j = 0; j < result_matrix.GetSize().second; j += block_size)
    {
      for (int k = 0; k < result_matrix.GetSize().second; k += block_size)
      {
        std::thread thread(&MatrixMultiplicator::MultiplyBlocks, this,
                           std::ref(result_matrix),std::ref(matrix1), std::ref(matrix2),
                           i, k, k, j, block_size);
        threads.push_back(std::move(thread));
      }
    }
  }
  for (int i=0;i<threads.size();i++)
  {
    threads[i].join();
  }
  return result_matrix;
}


void MatrixMultiplicator::MultiplyBlocks(Matrix& result_matrix, const Matrix& matrix1, const Matrix& matrix2,
                                         int rows_amount_1, int columns_amount_1,
                                         int rows_amount_2, int columns_amount_2,
                                         int block_size)
{
  for (int i = rows_amount_1; i < rows_amount_1 + block_size; i++)
  {
    for (int j = columns_amount_2; j < columns_amount_2 + block_size; j++)
    {
      double sum = 0.;
      for (int k = 0; k < block_size; k++)
      {
        sum += matrix1.GetElement(i, columns_amount_1 + k) * matrix2.GetElement(rows_amount_2 + k, j);
      }
      lock_.lock();
      result_matrix.IncreaseElement(sum,i,j);
      lock_.unlock();
    }
  }
}