#include <iostream>
#include "linear_regression.hpp"

using namespace std;
//constructor to initialize number of dependent variables
LinearRegression::LinearRegression(int num){
    number_of_variables = num;
    weights = arma::mat(number_of_variables + 1, 1);// arma::randu<arma::mat>(number_of_variables + 1, 1);
    weights.randu();
}

arma::mat LinearRegression::predict(arma::mat& X_predict){
    arma::mat x = X_predict;
    x.insert_cols(0, arma::ones<arma::mat>(X_predict.n_rows, 1));
    return x * weights;
}

void LinearRegression::train(arma::mat& X_train, arma::mat& y_train, float alpha, int epochs){
        arma::mat x = X_train;
        x.insert_cols(0, arma::ones<arma::mat>(X_train.n_rows, 1));
        for(int i=1;i<=epochs;i++)
        {   
             //updating weights using gradient descent method
            arma::mat delta=(x.t() * (predict(X_train)-y_train));
            weights -= ((alpha * delta)/X_train.n_rows);
            cout<<"Epoch completed = "<<i<<weights<< " " << endl;
        }
}