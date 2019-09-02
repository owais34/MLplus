#include <bits/stdc++.h>
#include "LinearRegressor.hpp"

using namespace std;

LinearRegressor::LinearRegressor(int num){
    number_of_variables = num;
    weights = arma::randu<arma::mat>(number_of_variables + 1, 1);
}

arma::mat LinearRegressor::predict(arma::mat X_predict){
    X_predict.insert_cols(0, arma::ones<arma::mat>(X_predict.n_rows, 1));
    return X_predict * weights;
}

void LinearRegressor::train(arma::mat X_train, arma::mat y_train, float alpha, int epochs){
        //alpha is the learning rate
        X_train.insert_cols(0, arma::ones<arma::mat>(X_train.n_rows, 1));
        for(int i=1;i<=epochs;i++)
        {
            arma::mat delta_weight = X_train.t() * (y_train - predict(X_train));
            weights -= delta_weight;
            cout<<"Epoch completed = "<<i<<endl;
        }
}