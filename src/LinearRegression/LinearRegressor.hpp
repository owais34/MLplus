#include <bits/stdc++.h>

using namespace std;
class LinearRegressor{
    public:
    int number_of_variables;
    vector<float> weights;

    LinearRegressor();
    
    void setNumberofVariables(int vars);

    float h_theta(vector<float> row);

    void train(vector< vector<float> > X_train,vector<float> y_train,float alpha,int epochs);

    vector<float> predict(vector<vector<float> > X_test);
};