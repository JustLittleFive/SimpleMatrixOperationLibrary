/*
 Copyright (c) 2022 SUSTech - JustLittleFive

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "header.h"

Matrix* createMatrix(int row, int line) {
  Matrix* matrix = NULL;
  if (row > 0 && line > 0) {
    matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->row = row;
    matrix->line = line;
    matrix->data = (float*)malloc(sizeof(float) * row * line);
    memset(matrix->data, 0, sizeof(float) * row * line);
    return matrix;
  } else
    return NULL;
}

void deleteMatrix(Matrix** matrix) {
  if (*matrix) {
    free((*matrix)->data);
    // &matrix->data = NULL;
    free(*matrix);
    *matrix = NULL;
    printf("释放成功\n");
  } else {
    printf("矩阵不存在! \n");
  }
}

Matrix* copyMatrix(Matrix* matrix_toCopy) {
  if (matrix_toCopy) {
    Matrix* matrix =
        createMatrix(matrix_toCopy->row, matrix_toCopy->line);
    memcpy(matrix->data, matrix_toCopy->data,
           matrix_toCopy->line * matrix_toCopy->row * sizeof(float));
    return matrix;
  } else {
    printf("矩阵不存在! \n");
    return NULL;
  }
}

void setMatrix(Matrix* matrix, float* array, int length) {
  if (matrix) {
    if (matrix->data != NULL) {
      memcpy(matrix->data, array, length);
    }
  } else {
    printf("矩阵不存在! \n");
  }
}

void printMatrix(Matrix* matrix) {
  if (matrix) {
    for (int i = 0; i < matrix->row * matrix->line; i++) {
      printf("%f\t", matrix->data[i]);
      if ((i + 1) % matrix->line == 0) printf("\n");
    }
  } else {
    printf("矩阵不存在! \n");
  }
}

Matrix* addScalar(Matrix* matrix, float num) {
  if (matrix) {
    Matrix* matrix_res = createMatrix(matrix->row, matrix->line);
    for (int i = 0; i < matrix->line; i++) {
      for (int j = 0; j < matrix->row; j++) {
        matrix_res->data[i * matrix_res->row + j] =
            matrix->data[i * matrix->row + j] + num;
      }
    }
    return matrix_res;
  } else {
    printf("矩阵不存在! \n");
    return NULL;
  }
}

Matrix* subtractScalar(Matrix* matrix, float num) {
  if (matrix) {
    Matrix* matrix_res = createMatrix(matrix->row, matrix->line);
    for (int i = 0; i < matrix->line; i++) {
      for (int j = 0; j < matrix->row; j++) {
        matrix_res->data[i * matrix_res->row + j] =
            matrix->data[i * matrix->row + j] - num;
      }
    }
    return matrix_res;
  } else {
    printf("矩阵不存在! \n");
    return NULL;
  }
}

Matrix* multiplyScalar(Matrix* matrix, float num) {
  if (matrix) {
    Matrix* matrix_res = createMatrix(matrix->row, matrix->line);
    for (int i = 0; i < matrix->line; i++) {
      for (int j = 0; j < matrix->row; j++) {
        matrix_res->data[i * matrix_res->row + j] =
            matrix->data[i * matrix->row + j] * num;
      }
    }
    return matrix_res;
  } else {
    printf("矩阵不存在! \n");
    return NULL;
  }
}

Matrix* addMatrix(Matrix* matrix_A, Matrix* matrix_B) {
  if (matrix_A && matrix_B) {
    if (matrix_A->row == matrix_B->row && matrix_A->line == matrix_B->line) {
      Matrix* matrix_res = createMatrix(matrix_A->row, matrix_A->line);
      for (int i = 0; i < matrix_A->line; i++) {
        for (int j = 0; j < matrix_A->row; j++) {
          matrix_res->data[i * matrix_res->row + j] =
              matrix_A->data[i * matrix_A->row + j] +
              matrix_B->data[i * matrix_A->row + j];
        }
      }
      return matrix_res;
    } else {
      printf("不可相加\n");
      return NULL;
    }
  } else {
    if (matrix_A) {
      printf("矩阵B不存在! \n");
    } else {
      printf("矩阵A不存在! \n");
    }
    return NULL;
  }
}

Matrix* subtractMatrix(Matrix* matrix_A, Matrix* matrix_B) {
  if (matrix_A && matrix_B) {
    if (matrix_A->row == matrix_B->row && matrix_A->line == matrix_B->line) {
      Matrix* matrix_res = createMatrix(matrix_A->row, matrix_A->line);
      for (int i = 0; i < matrix_A->line; i++) {
        for (int j = 0; j < matrix_A->row; j++) {
          matrix_res->data[i * matrix_res->row + j] =
              matrix_A->data[i * matrix_A->row + j] -
              matrix_B->data[i * matrix_A->row + j];
        }
      }
      return matrix_res;
    } else {
      printf("不可相减\n");
      return NULL;
    }
  } else {
    if (matrix_A) {
      printf("矩阵B不存在! \n");
    } else {
      printf("矩阵A不存在! \n");
    }
    return NULL;
  }
}

Matrix* multiplyMatrix(Matrix* matrix_A, Matrix* matrix_B) {
  if (matrix_A && matrix_B) {
    if (matrix_A->row == matrix_B->line) {
      Matrix* matrix_res = createMatrix(matrix_B->row, matrix_A->line);
      for (int i = 0; i < matrix_A->row; i++) {
        for (int j = 0; j < matrix_B->line; j++) {
          for (int k = 0; k < matrix_A->line; k++) {
            matrix_res->data[i * matrix_res->line + j] +=
                matrix_A->data[i * matrix_A->line + k] *
                matrix_B->data[k * matrix_B->row + j];
          }
        }
      }
      return matrix_res;
    } else {
      printf("不可相乘\n");
      return NULL;
    }
  } else {
    if (matrix_A) {
      printf("矩阵B不存在! \n");
    } else {
      printf("矩阵A不存在! \n");
    }
    return NULL;
  }
}

float minofMatrix(Matrix* matrix) {
  if (matrix) {
    float res = matrix->data[0];
    for (int i = 0; i < matrix->line; i++) {
      for (int j = 0; j < matrix->row; j++) {
        if (matrix->data[i * matrix->row + j] < res) {
          res = matrix->data[i * matrix->row + j];
        }
      }
    }
    return res;
  } else {
    printf("矩阵不存在! \n");
    return 0;
  }
}

float maxofMatrix(Matrix* matrix) {
  if (matrix) {
    float res = matrix->data[0];
    for (int i = 0; i < matrix->line; i++) {
      for (int j = 0; j < matrix->row; j++) {
        if (matrix->data[i * matrix->row + j] > res) {
          res = matrix->data[i * matrix->row + j];
        }
      }
    }
    return res;
  } else {
    printf("矩阵不存在! \n");
    return 0;
  }
}

void transMatrix(Matrix* matrix) {
  if (matrix) {
    if (matrix->row == matrix->line) {
      Matrix* matrixTemp = copyMatrix(matrix);

      for (int i = 0; i < matrix->row; i++) {
        for (int j = 0; j < matrix->line; j++) {
          matrix->data[i * matrix->row + j] =
              matrixTemp->data[j * matrix->row + i];
        }
      }
    } else {
      printf("转置的矩阵必须为方阵\n");
    }
  } else {
    printf("矩阵不存在! \n");
  }
}
