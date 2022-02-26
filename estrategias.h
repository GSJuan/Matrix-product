#include <vector>
using namespace std;
class Strategy {
  public:
    virtual ~Strategy(){}
    virtual vector<vector<int>> product(const vector<vector<int>>& a, const vector<vector<int>>& b) const = 0;
};


class RowProduct : public Strategy {
public:
  vector<vector<int>> product(const vector<vector<int>>& a, const vector<vector<int>>& b) const {
    int a_n = a.size(), a_m = a[0].size(); //filas y columnas de la matriz a
    int b_n = b.size(), b_m = b[0].size(); //filas y columnas de la matriz b
    vector<vector<int>> result(a_n, vector<int>(b_m));

    if(a[0].size() == b.size()) {
      for(int i = 0; i < a_n; i++){ //primero se recorren las filas
        for(int j = 0; j < b_m; j++) { //luego se recorren las columnas
          result[i][j] = 0;
          for(int k = 0; k < b_n; k++) {
            result[i][j] += a[i][k] * b[k][j];
          }
        }
      }
    } else { cout << "ERROR Matrix a row number isnt equal to b Matrix's column number";}
    return result;
  }
};

class ColProduct : public Strategy{
public:
  vector<vector<int>> product(const vector<vector<int>>& a, const vector<vector<int>>& b) const {
    int a_n = a.size(), a_m = a[0].size(); //filas y columnas de la matriz a
    int b_n = b.size(), b_m = b[0].size(); //filas y columnas de la matriz b
    vector<vector<int>> result(a_n, vector<int>(b_m));

    if(a[0].size() == b.size()) {
      for(int j = 0; j < b_m; j++) { // se recorren primero las columnas
        for(int i = 0; i < a_n; i++) { // luego se recorren las filas
          result[i][j] = 0;
          for(int k = 0; k < b_n; k++) {
            result[i][j] += a[i][k] * b[k][j];
          }
        }
      }
    } else { cout << "ERROR Matrix a row number isnt equal to b Matrix's column number";}
    return result;
  }
};
