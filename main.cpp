
#include "matriz.h"
int main( void ) {
time_t t;
srand((unsigned) time(&t));

int n = 2, m = 2;
Matrix matriz1(n, m);
Matrix matriz2(n, m);

cout << matriz1 << endl;
cout << matriz2 << endl;

matriz1.setStrategy(new RowProduct());
matriz2.setStrategy(new RowProduct());
Matrix matriz3 = matriz1 * matriz2;
cout << matriz3 << endl;

matriz1.setStrategy(new ColProduct());
matriz2.setStrategy(new ColProduct());
Matrix matriz4 = matriz1 * matriz2;
cout << matriz4;

return 0;
};