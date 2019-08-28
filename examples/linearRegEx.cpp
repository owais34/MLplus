#include <bits/stdc++.h>
#include <LinearRegressor.hpp>

using namespace std;

int main()
{
    LinearRegressor model;
    cout<<model.number_of_variables<<endl;
    model.setNumberofVariables(10);
    for(int i=0;i<model.weights.size();i++)
        cout<<model.weights[i]<<" ";
    cout<<endl;

    vector<vector<float> > X_train;
    vector<float> y_train;
    for(int i=0;i<10;i++)
    {
        float x,y;
        cin>>x>>y;
        vector<float> f;f.push_back(x);X_train.push_back(f);y_train.push_back(y);
    }
    model.train(X_train,y_train,0.1,10000);
    cout<<model.number_of_variables<<endl;

    vector<float> out=model.predict(X_train);
    for(int i=0;i<out.size();i++)
        cout<<out[i]<<endl;
    return 0;
}
