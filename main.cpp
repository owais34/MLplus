#include <bits/stdc++.h>

using namespace std;
class Linear{
//
public:
int number_of_variables;
vector<float> weights;
//
Linear()
{
    number_of_variables=1;
}
void setNumberofVariables(int vars)
{
    number_of_variables=vars+1;
    for(int i=0;i<number_of_variables;i++)
        weights.push_back(0);

}
float h_theta(vector<float> row)
{
    float out=0;
    for(int i=1;i<weights.size();i++)
    {

        out+=(weights[i]*row[i-1]);
    }
    return out+weights[0];
}
void train(vector< vector<float> > X_train,vector<float> y_train,float alpha,int epochs)//alpha is the learning rate
{
    setNumberofVariables(X_train[0].size());
    long nrows=X_train.size();
    for(int i=1;i<=epochs;i++)
    {
        vector<float> sum(nrows,0);
        for(int j=0;j<nrows;j++)
        {

            for(int k=0;k<number_of_variables;k++)
            {

                sum[k]+=((h_theta(X_train[j])-y_train[j])/nrows)*X_train[j][k];
            }
        }
        for(int j=0;j<number_of_variables;j++)
            weights[j]-=sum[j]*alpha;

    }
}
vector<float> predict(vector<vector<float> > X_test)
{
    vector<float> output;
    for(int i=0;i<X_test.size();i++)
    {
        output.push_back(h_theta(X_test[i]));
    }
    return output;
}

};

int main()
{
    Linear model;
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
