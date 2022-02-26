#include <chrono> 
#include <fstream>

#include "matriz.h"

int main( void ) {
time_t t;
srand((unsigned) time(&t));

std::ofstream csv; 
csv.open ("comparative.csv"); //abrimos o creamos el archivo.csv
csv << "Tamaño,Row Product Time microseconds,Column Product Time microseconds\n"; //columnas del csv

int n = 10; //inicializamos el numero de filas (n) y columnas(m)
int m = 10;

while(n < 2010) { // 2010 es el valor que ha mi me ha parecido a partir del cual va demasiado lento
    n += 100;
    m += 100;
    Matrix matriz1(n, m);
    Matrix matriz2(n, m);

    cout << "Multiplying matrices of dimensions " << n << "*" << m << " : " << endl; 

    matriz1.setStrategy(new RowProduct());
    matriz2.setStrategy(new RowProduct());

    auto start1 = chrono::high_resolution_clock::now(); //empezamos el chrono
    Matrix matriz3 = matriz1 * matriz2; //hacemos el producto
    auto stop1 = chrono::high_resolution_clock::now(); //lo paramos
    auto duration1 = chrono::duration_cast<chrono::microseconds>(stop1 - start1); //calculamos lo que ha tardado en micro segundos
    cout << "\tWith Row Product: " << duration1.count() << " microseconds" << endl;

    matriz1.setStrategy(new ColProduct());
    matriz2.setStrategy(new ColProduct());

    auto start2 = chrono::high_resolution_clock::now(); //empezamos el chrono
    Matrix matriz4 = matriz1 * matriz2; //hacemos el producto
    auto stop2 = chrono::high_resolution_clock::now(); //lo paramos
    auto duration2 = chrono::duration_cast<chrono::microseconds>(stop2 - start2);
    cout << "\tWith Column Product: " << duration2.count() << " microseconds" << endl; //calculamos lo que ha tardado en micro segundos

    csv << n << "x" << m << "," << duration1.count() << "," << duration2.count() << "\n";
}

csv.close(); //cerramos el archivos
return 0;
};