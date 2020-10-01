#include <armadillo>

using namespace std;

class Rows{
	public:
	vector<string> text;
	vector<float> numeric;
};

class Dataframe{
public:
	vector<Rows> data;vector<bool> istext;vector<string> header;
	arma::mat Matrix;
	
	//Member functions
	bool isNumeric(string s);
	Dataframe(string file,char delimiter);
	void printDataframe(int rows);
	void printMatrix(int rows);
	void integerEncode(int column);
}
