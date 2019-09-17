#include <bits/stdc++.h>
#include "naive_bayes.hpp"

using namespace std;
//constructor to initialize number of dependent variables
class Naive_bayes{
public:	

Naive_bayes::Naive_bayes(int num,vector<int> categorical_cols);

arma::mat Naive_bayes::predict(arma::mat X_predict);

void Naive_bayes::train(arma::mat X_train, arma::mat y_train);

};
class Prob_table
{
	public:
		int rows,int cols;
		arma::mat table;
		Prob_table(int rows,int cols);
		
		void view();
}
