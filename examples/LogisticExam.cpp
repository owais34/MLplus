#include <bits/stdc++.h>
#include <MLplus/logistic_regression/logistic_regression.hpp>

using namespace std;

int main()
{
    LogisticRegression model(1);
    double alpha;
    int epochs;
    cout<<"alpha and epochs ,choose alpha less than .05 \n";
    cin>>alpha>>epochs;
    arma::mat X_train(1000, 1);
    arma::mat y_train(1000, 1);
    for(int i=0;i<1000;i++)
    {
        X_train(i, 0) = i;
        y_train(i, 0) = (i < 500) ? 1 : 0;
    }
    model.train(X_train,y_train,alpha,epochs);

    arma::mat out=model.predict(X_train);
    cout<<out<<endl;
    return 0;
}