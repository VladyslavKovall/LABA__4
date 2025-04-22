#include <iostream>
using namespace std;

const int ROWS = 4;
const int COLS = 4;

template <typename T>
class Analyzer {
public:
   T m[ROWS][COLS];

   Analyzer(T arr[ROWS][COLS]) {
      for (int i = 0; i < ROWS; i++)
         for (int j = 0; j < COLS; j++)
            m[i][j] = arr[i][j];
   }

   int zerosInCols() {
      int count = 0;
      for (int j = 0; j < COLS; j++) {
         for (int i = 0; i < ROWS; i++) {
            if (m[i][j] == 0) {
               count++;
               break;
            }
         }
      }
      return count;
   }

   int rowWithSame() {
      int maxLen = 0;
      int rowIdx = 0;
      for (int i = 0; i < ROWS; i++) {
         int len = 1;
         for (int j = 1; j < COLS; j++) {
            if (m[i][j] == m[i][j - 1]) {
               len++;
               if (len > maxLen) {
                  maxLen = len;
                  rowIdx = i;
               }
            }
            else {
               len = 1;
            }
         }
      }
      return rowIdx;
   }

   void sortMatrix() {
      for (int i = 0; i < ROWS; i++) {
         T temp[COLS];
         int idx = 0;

         int j = 0;
         while (j < COLS) {
            int k = j + 1;
            while (k < COLS && m[i][k] == m[i][j]) k++;
            if (k - j > 1) {
               for (int l = j; l < k; l++)
                  temp[idx++] = m[i][j];
            }
            j = k;
         }

         j = 0;
         while (j < COLS) {
            int k = j + 1;
            while (k < COLS && m[i][k] == m[i][j]) k++;
            if (k - j == 1) {
               temp[idx++] = m[i][j];
            }
            j = k;
         }

         for (int j = 0; j < COLS; j++) {
            m[i][j] = temp[j];
         }
      }
   }

   void show() {
      for (int i = 0; i < ROWS; i++) {
         for (int j = 0; j < COLS; j++) {
            cout << m[i][j] << " ";
         }
         cout << endl;
      }
   }
};

int main() {
   int mat[ROWS][COLS] = {
       {1, 0, 3, 3},
       {4, 5, 6, 6},
       {0, 8, 8, 8},
       {7, 0, 9, 10}
   };

   Analyzer<int> a(mat); 

   cout << "Columns with one zero: " << a.zerosInCols() << endl;
   cout << "The number of the row that contains the longest sequence of identical elements: " << a.rowWithSame() << endl;
   cout << "Matrix after sorting sequences:\n";

   a.sortMatrix();
   a.show();

   return 0;
}
