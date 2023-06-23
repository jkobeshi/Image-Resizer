// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

TEST(test_fill_basic_2) {
    Matrix* mat = new Matrix; // create a Matrix in dynamic memory

    const int width = 1;
    const int height = 1;
    const int value = 42;
    Matrix_init(mat, 1, 1);
    Matrix_fill(mat, value);

    for (int r = 0; r < height; ++r) {
        for (int c = 0; c < width; ++c) {
            ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
        }
    }

    delete mat; // delete the Matrix
}

TEST(test_matrix_width) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 5, 4);
    ASSERT_EQUAL(Matrix_width(mat), 5);
    delete mat;
}
TEST(test_matrix_height) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 5, 4);
    ASSERT_EQUAL(Matrix_height(mat), 4);
    delete mat;
}
TEST(test_matrix_row) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 100, 150);
    int* ptr = Matrix_at(mat, 52, 35);
    ASSERT_EQUAL(Matrix_row(mat, ptr), 52);
    delete mat;
}
TEST(test_matrix_col) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 100, 150);
    int* ptr = Matrix_at(mat, 52, 35);
    ASSERT_EQUAL(Matrix_column(mat, ptr), 35);
    delete mat;
}
TEST(test_matrix_at) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 100, 150);
    Matrix_fill(mat, 1);
    int* ptr = Matrix_at(mat, 149, 99);
    *ptr = 19;
    const int *cptr = Matrix_at(mat, 149, 99);
    ASSERT_EQUAL(*cptr, 19);
    delete mat;
}
TEST(test_matrix_at_2) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 500, 500);
    Matrix_fill(mat, 1);
    int* ptr = Matrix_at(mat, 0, 0);
    *ptr = 300;
    const int* cptr = Matrix_at(mat, 0, 0);
    ASSERT_EQUAL(*cptr, 300);
    delete mat;
}
TEST(test_matrix_print_2) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 2, 2);
    *Matrix_at(mat, 0, 0) = 42;
    *Matrix_at(mat, 0, 1) = 41;
    *Matrix_at(mat, 1, 0) = 40;
    *Matrix_at(mat, 1, 1) = 39;
    ostringstream expected;
    expected << "2 2\n"
        << "42 41 \n"
        << "40 39 \n";
    ostringstream actual;
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());
    delete mat;
}
TEST(test_matrix_print_3) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            *Matrix_at(mat, i, j) = i * j;
        }
    }
    ostringstream expected;
    expected << "3 3\n"
        << "0 0 0 \n"
        << "0 1 2 \n"
        << "0 2 4 \n";
    ostringstream actual;
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());
    delete mat;
}
TEST(test_matrix_fill) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 2, 2);
    Matrix_fill(mat, 255);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ASSERT_EQUAL(*Matrix_at(mat, i, j), 255);
        }
    }
    delete mat;
}
TEST(test_matrix_fill_border_3) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 50, 50);
    Matrix_fill(mat, 0);
    for (int i = 0; i < 50; i++) {
        Matrix* aux = new Matrix;
        Matrix_init(aux, i + 1, i + 1);
        Matrix_fill(aux, 0);
        Matrix_fill_border(aux, 1);
        for (int j = 0; j < i + 1; j++) {
            for (int k = 0; k < i + 1; k++) {
                if (k == 0 || j == 0 || j == i || k == i) {
                    *Matrix_at(mat, j, k) = *Matrix_at(aux, j, k);
                }
            }
        }
        delete aux;
    }
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            ASSERT_EQUAL(*Matrix_at(mat, 1, 1), 1);
        }
    }
    delete mat;
}
TEST(test_matrix_fill2) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 3, 3);
    Matrix_fill(mat, 355);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ASSERT_EQUAL(*Matrix_at(mat, i, j), 355);
        }
    }
    delete mat;
}
TEST(test_matrix_fill_border) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 4, 4);
    Matrix_fill(mat, 255);
    Matrix_fill_border(mat, 1);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 0 || i == 3 || j == 0 || j == 3) {
                ASSERT_EQUAL(*Matrix_at(mat, i, j), 1);
            }
            else {
                ASSERT_EQUAL(*Matrix_at(mat, i, j), 255);
            }
        }
    }
    delete mat;
}
TEST(test_matrix_fill_border2) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 10, 10);
    Matrix_fill(mat, 0);
    Matrix_fill_border(mat, 3000);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0 || i == 9 || j == 0 || j == 9) {
                ASSERT_EQUAL(*Matrix_at(mat, i, j), 3000);
            }
            else {
                ASSERT_EQUAL(*Matrix_at(mat, i, j), 0);
            }
        }
    }
    delete mat;
}
TEST(test_matrix_max) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 5, 4);
    Matrix_fill(mat, 1);
    *Matrix_at(mat, 3, 2) = 15;
    ASSERT_EQUAL(Matrix_max(mat), 15);
    delete mat;
}
TEST(test_matrix_max2) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 500, 500);
    Matrix_fill(mat, 1000);
    *Matrix_at(mat, 3, 2) = 1001;
    ASSERT_EQUAL(Matrix_max(mat), 1001);
    delete mat;
}
TEST(test_matrix_column_of_min_value_in_row) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 5, 4);
    Matrix_fill(mat, 15);
    *Matrix_at(mat, 3, 2) = 1;
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 3, 1, 3), 2);
    delete mat;
}
TEST(test_matrix_min_value_in_row) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 5, 4);
    Matrix_fill(mat, 15);
    *Matrix_at(mat, 3, 2) = 1;
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 3, 0, 3), 1);
    delete mat;
}
TEST(test_matrix_column_of_min_value_in_row2) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 10, 10);
    Matrix_fill(mat, 30);
    *Matrix_at(mat, 9, 9) = 50;
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 9, 4, 10), 4);
    delete mat;
}
TEST(test_matrix_column_of_min_value_in_row3) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 10, 10);
    Matrix_fill(mat, 30);
    *Matrix_at(mat, 9, 9) = 5;
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 9, 4, 10), 9);
    delete mat;
}
TEST(test_matrix_column_of_min_value_in_row4) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 10, 10);
    Matrix_fill(mat, 30);
    *Matrix_at(mat, 9, 9) = 50;
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 9, 0, 10), 0);
    delete mat;
}
TEST(test_matrix_min_value_in_row2) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 10, 10);
    Matrix_fill(mat, 30);
    *Matrix_at(mat, 9, 9) = 10;
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 9, 4, 10), 10);
    delete mat;
}
TEST(test_matrix_min_value_in_row3) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 10, 10);
    Matrix_fill(mat, 5);
    *Matrix_at(mat, 9, 9) = 10;
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 9, 0, 10), 5);
    delete mat;
}
TEST(test_matrix_print) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 1, 1);

    *Matrix_at(mat, 0, 0) = 42;
    ostringstream expected;
    expected << "1 1\n"
        << "42 \n";
    ostringstream actual;
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());

    delete mat;
}


TEST(test_matrix_basic) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 5, 5);

  ASSERT_EQUAL(Matrix_width(mat), 5);
  ASSERT_EQUAL(Matrix_height(mat), 5);

  Matrix_fill(mat, 0);

  int *ptr = Matrix_at(mat, 2, 3);
  ASSERT_EQUAL(Matrix_row(mat, ptr), 2);
  ASSERT_EQUAL(Matrix_column(mat, ptr), 3);
  ASSERT_EQUAL(*ptr, 0);
  *ptr = 42;

  const int *cptr = Matrix_at(mat, 2, 3);
  ASSERT_EQUAL(*cptr, 42);

  Matrix_fill_border(mat, 2);
  ASSERT_EQUAL(*Matrix_at(mat, 0, 0), 2);

  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 2, 0, 4), 1);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 2, 0, 4), 0);
  
  ASSERT_EQUAL(Matrix_max(mat), 42);
  Matrix_fill(mat, 255);
  ASSERT_EQUAL(Matrix_max(mat), 255);
  delete mat;
}
TEST(col_of_min_val) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 10, 10);
    Matrix_fill(mat, 1);
    Matrix_fill_border(mat, 11);
    *Matrix_at(mat, 3, 2) = 40;
    *Matrix_at(mat, 4, 5) = 41;
    ASSERT_EQUAL(*Matrix_at(mat, 3, Matrix_column_of_min_value_in_row(mat, 3, 1, 9)), Matrix_min_value_in_row(mat, 3, 1, 9));
    ASSERT_EQUAL(*Matrix_at(mat, 4, Matrix_column_of_min_value_in_row(mat, 4, 1, 9)), Matrix_min_value_in_row(mat, 4, 1, 9));
    delete mat;
}
// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.


// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
