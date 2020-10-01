//#include <bits/stdc++.h> Please only include the required files to prevent unnecessary enlarging of binaries
#include <iostream>
#include "naive_bayes.hpp"

using namespace std;
//constructor to initialize number of dependent variables

Naive_bayes::Naive_bayes(int num, vector<int> cat_cols){
    //categorical
}

arma::mat Naive_bayes::predict(arma::mat X_predict){
	arma::mat x = X_predict;
    arma::mat regpred;
    //TODO: Check the prediction formula
    x.insert_cols(0, arma::ones<arma::mat>(X_predict.n_rows, 1));
    regpred = x * categorical_cols;
    return regpred;
}

void Naive_bayes::train(arma::mat X_train, arma::mat y_train){
    //TODO: Iterative training on the categorical_cols for training of naive bayes
}
