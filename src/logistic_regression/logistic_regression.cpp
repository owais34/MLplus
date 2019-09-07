#include <bits/stdc++.h>
#include "logistic_regression.hpp"

using namespace std;
//constructor to initialize number of dependent variables
LogisticRegression::LogisticRegression(int num){
    number_of_variables = num;
    weights = arma::mat(number_of_variables + 1, 1);
    weights.randu();
}

arma::mat LogisticRegression::predict(arma::mat X_predict){
    arma::mat x = X_predict;
    x.insert_cols(0, arma::ones<arma::mat>(X_predict.n_rows, 1));
    arma::mat regpred = x * weights;
    
    for(int i=0;i<X_predict.n_rows;i++)
    {
        regpred(i,0)=(1/(1+exp(-regpred(i,0))));
    }
    return regpred;
}

void LogisticRegression::train(arma::mat X_train, arma::mat y_train, float alpha, int epochs){
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