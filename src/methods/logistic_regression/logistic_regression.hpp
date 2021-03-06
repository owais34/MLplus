#include <bits/stdc++.h>
#include <armadillo>

using namespace std;
class LogisticRegression{
    public:
    int number_of_variables;
    arma::Col<double> weights;

    LogisticRegression(int num);

    void train(arma::mat X_train, arma::mat y_train, float alpha, int epochs);

    arma::mat predict(arma::mat X_predict);
};