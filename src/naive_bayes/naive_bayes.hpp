//#include <bits/stdc++.h>
#include <armadillo>

using namespace std;

class Naive_bayes{
    public:
    int number_of_variables;
	vector<int> categorical_cols;
	vector<int> cont_cols;
    Naive_bayes(int num,vector<int> cat_cols);

    void train(arma::mat X_train, arma::mat y_train);

    arma::mat predict(arma::mat X_predict);
};
