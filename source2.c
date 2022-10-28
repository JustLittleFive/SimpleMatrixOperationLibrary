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

float value1[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9};
float value2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

int main(int argc, char* argv[]) {
  Matrix* matrix1 = createMatrix(3, 3, -1.0f);
  Matrix* matrix2 = createMatrix(3, 3, 5.0f);

  setMatrix(matrix1, value1);
  printf("矩阵1: \n");
  printMatrix(matrix1);
  setMatrix(matrix2, value2);
  printf("矩阵2: \n");
  printMatrix(matrix2);

  printf("矩阵1最小值: ");
  printf("%lf\n", minofMatrix(matrix1));
  printf("矩阵2最大值: ");
  printf("%lf\n", maxofMatrix(matrix2));

  printf("矩阵1 乘以 矩阵2: \n");
  Matrix* matrix3 = multiplyMatrix(matrix1, matrix2);
  printMatrix(matrix3);
  printf("矩阵1 加上 矩阵2: \n");
  Matrix* matrix4 = addMatrix(matrix1, matrix2);
  printMatrix(matrix4);

  printf("矩阵1加5: \n");
  Matrix* matrix5 = addScalar(matrix1, 5);
  printMatrix(matrix5);
  printf("矩阵1拉长-2倍: \n");
  Matrix* matrix6 = multiplyScalar(matrix1, -2);
  printMatrix(matrix6);

  printf("复制矩阵1: \n");
  Matrix* matrix7 = copyMatrix(matrix1);
  printMatrix(matrix7);

  printf("矩阵1进行转置: \n");
  transMatrix(matrix1);
  printMatrix(matrix1);

  printf("删除矩阵1: \n");
  deleteMatrix(&matrix1);
  printf("尝试打印矩阵1: \n");
  printMatrix(matrix1);
  printf("尝试再次删除矩阵1: \n");
  deleteMatrix(&matrix1);

  printf("删除其他矩阵: \n");
  deleteMatrix(&matrix2);
  deleteMatrix(&matrix3);
  deleteMatrix(&matrix4);
  deleteMatrix(&matrix5);
  deleteMatrix(&matrix6);
  deleteMatrix(&matrix7);

  matrix1 = createMatrix(3, 3, -1.0f);
  setMatrix(matrix1, value1);
  printf("再次创建矩阵1: \n");
  printMatrix(matrix1);

  printf("删除矩阵1: \n");
  deleteMatrix(&matrix1);

  return 0;
}