#include <bits/stdc++.h>
#include "../src/LinearRegression/LinearRegressor.hpp"

using namespace std;

int main()
{
    LinearRegressor model(1);
    double alpha;
    int epochs;
    cout<<"alpha and epochs\n";
    cin>>alpha>>epochs;
    arma::mat X_train(10, 1);
    arma::mat y_train(10, 1);
    for(int i=0;i<10;i++)
    {
        X_train(i, 0) = i;
        y_train(i, 0) = 2 * i;
    }
    model.train(X_train,y_train,alpha,epochs);

    arma::mat out=model.predict(X_train);
    cout<<out<<endl;
    return 0;
}
