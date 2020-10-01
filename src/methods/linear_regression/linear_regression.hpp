#include <armadillo>

using namespace std;

class LinearRegression{
    public:
    int number_of_variables;
    arma::mat weights;

    LinearRegression(int num);

    void train(arma::mat& X_train, arma::mat& y_train, float alpha, int epochs);

    arma::mat predict(arma::mat& X_predict);
};
