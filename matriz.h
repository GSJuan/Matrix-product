#include <iostream>
#include <cstdlib>
#include <ctime>
#include "estrategias.h"


class Matrix {
public: 
   Matrix() {imp_ = nullptr;}; //constructor por defecto
   

   Matrix(int n_, int m_) { //constructor por tamaño de n filas y m columnas
     imp_ = NULL;
     n = n_;
     m = m_;
     matrix.resize(n);

     for (int i = 0; i < n; i++) {
       matrix[i].resize(m);
       for(int j = 0; j < m; j++) {
         matrix[i][j] = rand();
       }
     }
   };

   Matrix(const Matrix& newMatrix) { //constructor de copia
     imp_ = newMatrix.getStrategy();
     n = newMatrix.n; 
     m = newMatrix.m;
     matrix.resize(n);

     for (int i = 0; i < n; ++i) {
       matrix[i].resize(m);
       for (int j = 0; j < m; ++j) {
         matrix[i][j] = newMatrix.matrix[i][j];
       }
     }
   };

   Matrix(const vector<vector<int>> &newMatrix) { //constructor en base a un vector de vectores
     imp_ = nullptr;
     n = newMatrix.size(); 
     m = newMatrix[0].size();
     matrix.resize(n);
     for (int i = 0; i < n; ++i) {
       matrix[i].resize(m);
       for (int j = 0; j < m; ++j) {
         matrix[i][j] = newMatrix[i][j];
       }
     }
   };

   ~Matrix(){ //destructor
     delete this->imp_;
   }

   //getters 
   int getN() {return n;} //numero de filas
   int getM() {return m;} //numero de columnas

   int getN() const {return n;}
   int getM() const {return m;}

   vector<vector<int>> getMatrix() { //devuelve el vector que almacena la matriz
     return matrix;
   }

   vector<vector<int>> getMatrix() const {
     return matrix;
   }

   Strategy* getStrategy() { //devuelve el puntero a la estrategia
     return imp_;
   }
   Strategy* getStrategy() const {
     return imp_;
   }

   void setStrategy(Strategy* newImp){
     delete this->imp_;
     this->imp_ = newImp;
   }

   Matrix multiply(const vector<vector<int>>& a){
     return Matrix(imp_->product(matrix , a));

   }
   
   Matrix multiply (const vector<vector<int>>& a) const {
     return Matrix(imp_->product(matrix , a));
   }

   Matrix& operator=(const Matrix newMatrix) {
    if (this == &newMatrix) {
        return *this;
    }
    if (n != newMatrix.n || m != newMatrix.m) { //comprueba que sean de igual tamaño
      n = newMatrix.n; 
      m = newMatrix.m;
      matrix.resize(n);

      for(int i = 0; i < n; i++) {
        matrix[n].resize(m);
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        matrix[i][j] = newMatrix.matrix[i][j];
      }
    }
    return *this;
   };

   vector<int> operator [] (int i) const {return matrix[i];}
   vector<int>& operator [] (int i) {return matrix[i];}

   friend Matrix operator*(const Matrix& a, const Matrix& b) {
     return a.multiply(b.getMatrix());
   }

   friend ostream& operator<<(ostream& os, const Matrix& outputMatrix) {
     for (int i = 0; i < outputMatrix.getN(); ++i) {
       os << outputMatrix[i][0];
       for (int j = 1; j < outputMatrix.getM(); ++j) {
         os << " " << outputMatrix[i][j];
       }
       os << endl;
     }
     return os;
   }   

private:
   int n, m;
   vector<vector<int>> matrix;
   Strategy *imp_;
};






