//#include <bits/stdc++.h>
#include "prob_table.hpp"

using namespace std;
//constructor to initialize number of dependent variables

Probability_table::Probability_table(int rows,int cols)
{
	table=arma::mat (rows,cols);
}
Probability_table::view()
{
	cout<<table;
}
