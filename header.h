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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int row, line;
  float* data;
} Matrix;

Matrix* createMatrix(int, int);
void deleteMatrix(Matrix**);
Matrix* copyMatrix(Matrix*);
void setMatrix(Matrix*, float*, int);
void printMatrix(Matrix*);

Matrix* addScalar(Matrix*, float);
Matrix* subtractScalar(Matrix*, float);
Matrix* multiplyScalar(Matrix*, float);

Matrix* addMatrix(Matrix*, Matrix*);
Matrix* subtractMatrix(Matrix*, Matrix*);
Matrix* multiplyMatrix(Matrix*, Matrix*);

float minofMatrix(Matrix*);
float maxofMatrix(Matrix*);

void transMatrix(Matrix*);

// https://blog.csdn.net/Beking17113/article/details/100547735
