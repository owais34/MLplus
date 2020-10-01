//#include <bits/stdc++.h>
#include <armadillo>

using namespace std;

class Probability_table{
public:
    int rows,cols;
    arma::mat table;
    
    //Member functions
    Probability_table(int rows,int cols);
    void view();
};
