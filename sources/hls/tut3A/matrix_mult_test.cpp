#include <iostream>
#include "matrix_mult.h"

using namespace std;

int main(int argc, char **argv)
{
   mat_a in_mat_a[5][5] = {
      {0, 0, 0, 0, 1},
	  {0, 0, 0, 1, 0},
	  {0, 0, 1, 0, 0},
      {0, 1, 0, 0, 0},
      {1, 0, 0, 0, 0}
   };
   mat_b in_mat_b[5][5] = {
      {1, 1, 1, 1, 1},
      {0, 1, 1, 1, 1},
      {0, 0, 1, 1, 1},
	  {0, 0, 0, 1, 1},
	  {0, 0, 0, 0, 1}
   };
   mat_prod hw_result[5][5], sw_result[5][5];
   int error_count = 0;

   // Generate the expected result
   // Iterate over the rows of the A matrix
   for(int i = 0; i < IN_A_ROWS; i++) {
      for(int j = 0; j < IN_B_COLS; j++) {
         // Iterate over the columns of the B matrix
         sw_result[i][j] = 0;
         // Do the inner product of a row of A and col of B
         for(int k = 0; k < IN_B_ROWS; k++) {
            sw_result[i][j] += in_mat_a[i][k] * in_mat_b[k][j];
         }
      }
   }

#ifdef HW_COSIM
   // Run the Vivado HLS matrix multiplier
   matrix_mult(in_mat_a, in_mat_b, hw_result);
#endif

   // Print product matrix
   for (int i = 0; i < IN_A_ROWS; i++) {
      for (int j = 0; j < IN_B_COLS; j++) {
#ifdef HW_COSIM
         // Check result of HLS vs. expected
         if (hw_result[i][j] != sw_result[i][j]) {
            error_count++;
         }
#else
         cout << sw_result[i][j];
#endif
      }
   }

#ifdef HW_COSIM
   if (error_count)
      cout << "TEST FAIL: " << error_count << "Results do not match!" << endl;
   else
      cout << "Test passed!" << endl;
#endif
   return error_count;
}

