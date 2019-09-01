#include <bits/stdc++.h>
#include "LinearRegressor.hpp"

using namespace std;

LinearRegressor::LinearRegressor(){
        number_of_variables=1;
}

void LinearRegressor::setNumberofVariables(int vars){
        number_of_variables=vars+1;
        for(int i=0;i<number_of_variables;i++)
            weights.push_back(0);
}

float LinearRegressor::h_theta(vector<float> row){
        float out=0;
        for(int i=1;i<weights.size();i++)
        {

            out+=(weights[i]*row[i-1]);
        }
        return out+weights[0];
}

void LinearRegressor::train(vector< vector<float> > X_train,vector<float> y_train,float alpha,int epochs){
        //alpha is the learning rate
        setNumberofVariables(X_train[0].size());
        long nrows=X_train.size();
        for(int i=1;i<=epochs;i++)
        {
            vector<float> sum(number_of_variables,0);
            for(int j=0;j<nrows;j++)
            {

                for(int k=0;k<number_of_variables;k++)
                {
                    if(k==0){
                        sum[k]+=((h_theta(X_train[j])-y_train[j])/nrows);
                    }else{
                        sum[k]+=((h_theta(X_train[j])-y_train[j])/nrows)*X_train[j][k-1];
                    }
                }
            }
            for(int j=0;j<number_of_variables;j++)
                weights[j]-=sum[j]*alpha;

        }
}

vector<float> LinearRegressor::predict(vector<vector<float> > X_test){
        vector<float> output;
        for(int i=0;i<X_test.size();i++)
        {
            output.push_back(h_theta(X_test[i]));
        }
        return output;
}

// class LinearRegressor{

// public:
//     int number_of_variables;
//     vector<float> weights;

//     LinearRegressor(){
//         number_of_variables=1;
//     }
    
//     void setNumberofVariables(int vars){
//         number_of_variables=vars+1;
//         for(int i=0;i<number_of_variables;i++)
//             weights.push_back(0);
//     }

//     float h_theta(vector<float> row){
//         float out=0;
//         for(int i=1;i<weights.size();i++)
//         {

//             out+=(weights[i]*row[i-1]);
//         }
//         return out+weights[0];
//     }

//     void train(vector< vector<float> > X_train,vector<float> y_train,float alpha,int epochs){
//         //alpha is the learning rate
//         setNumberofVariables(X_train[0].size());
//         long nrows=X_train.size();
//         for(int i=1;i<=epochs;i++)
//         {
//             vector<float> sum(nrows,0);
//             for(int j=0;j<nrows;j++)
//             {

//                 for(int k=0;k<number_of_variables;k++)
//                 {

//                     sum[k]+=((h_theta(X_train[j])-y_train[j])/nrows)*X_train[j][k];
//                 }
//             }
//             for(int j=0;j<number_of_variables;j++)
//                 weights[j]-=sum[j]*alpha;

//         }
//     }

//     vector<float> predict(vector<vector<float> > X_test){
//         vector<float> output;
//         for(int i=0;i<X_test.size();i++)
//         {
//             output.push_back(h_theta(X_test[i]));
//         }
//         return output;
//     }

// };