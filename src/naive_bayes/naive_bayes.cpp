#include <bits/stdc++.h>
#include "naive_bayes.hpp"

using namespace std;
//constructor to initialize number of dependent variables
Naive_bayes::Naive_bayes(int num){
    number_of_variables = num;
	
}

arma::mat Naive_bayes::predict(arma::mat X_predict){

    return regpred;
}

void Naive_bayes::train(arma::mat X_train, arma::mat y_train){
        
}
