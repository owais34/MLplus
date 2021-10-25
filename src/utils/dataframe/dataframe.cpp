#include<vector>
#include<string>
#include<iomanip>
#include<unordered_map>

#ifndef ARMADILLO  //header guard for header file
#define ARMADILLO
#include<armadillo>
#include "dataframe.hpp"
#endif

using namespace std;

class Dataframe
{	
	bool isNumeric(string s){
		int count_dec = 0;
		if(s[0] == '"')
		s = s.substr(1, s.length() - 2);
		for(int j = 0; j < s.length(); j++){
			if((int)s[j] >= 48 && (int)s[j] <= 57){
				continue;
			}
			else if(s[j] == '.' && count_dec <= 1){
				count_dec++; continue;
			}
			else
			return false;
		}
		return true;
	}
	
	//in csv format
	Dataframe(string file, char delimiter){
	    ifstream fin;
  		string line; 
	    fin.open(&file[0]); 
    	int i = 0;
	int num_cols = 0;
	    while(fin){ 
    	    // Read a Line from standard input 
    	    getline(fin, line);
			line = line + ","; 
    	    //line contains data 
    	    if(i == 0){
    	    	string word = "";
    	    	for(int j = 0; j < line.length(); j++){
    	    		if(line[j] == delimiter || line[j] == '\n'){
    	    			if(word != "")
    	    			header.push_back(word);
    	    			word = "";
					}
					else
					word = word + line[j];
				}
				
			}
			else if(i==1){
				istext=std::vector<bool> (header.size(),true);
				string word="";Rows row;int k=0;
    	    	for(int j=0;j<line.length();j++){
    	    		if(line[j]==delimiter||line[j]=='\n'){
    	    			if(word!=""){
    	    				if(isNumeric(word)){
								row.numeric.push_back(stof(word));istext[k++]=false;
							}
    	    				else{
    	    					row.text.push_back(word);k++;
							}
						}
    	    			word="";
					}
					else
					word=word+line[j];
				}
				data.push_back(row);
			}
			else{
				string word="";int k=0;
				Rows row;
    	    	for(int j=0;j<line.length();j++){
    	    		if(line[j]==delimiter||line[j]=='\n'){
    	    			if(word!=""){
    	    				if(!istext[k]){
								row.numeric.push_back(stof(word));k++;
							}
    	    				else{
    	    					row.text.push_back(word);k++;
							}
						}
    	    			word="";
					}
					else
					word=word+line[j];
				}
					data.push_back(row);
			}
    	    i++;
    	}
		fin.close();
		// Here we initialize arma matrix
		Matrix=arma::mat(data.size(),data[0].numeric.size());
		//transferring data from vector to matrix
		for(int j=0;j<data.size();j++){
			for(int k=0;k<data[0].numeric.size();k++)
				Matrix(j,k)=data[j].numeric[k];
		}
	}
	
	void printDataframe(int rows){
		for(int i=0;i<header.size();i++){
			cout<<setw(10)<<i<<"|";
		}
		cout<<endl;
		for(int i=0;i<header.size();i++){
			if(!istext[i])
			cout<<setw(10)<<header[i]<<"|";
		}
		for(int i=0;i<header.size();i++){
			if(istext[i])
				cout<<setw(10)<<header[i]<<"|";
		}
		cout<<endl;
		for(int i=0;i<header.size()*11;i++)
			cout<<"-";
		cout<<endl;
		for(int i=0;i<rows;i++){
			for(int j=0;j<data[i].numeric.size();j++){
				cout<<setw(10)<<data[i].numeric[j]<<"|";
			}
			for (int j = 0; j < data[i].text.size(); j++){
				cout<<setw(10)<<data[i].text[j]<<"|";
			}
			cout<<endl;
		}
	}
	
	void printMatrix(int rows){
		cout<<Matrix.rows(0,rows-1);
	}
	
	//column numbering is from 0
	void integerEncode(int column){
		unordered_map<string,int > mp;
		int k=0;column=column-data[0].numeric.size();
		arma::mat colms=arma::mat(data.size(),1);
		for(int i=0;i<data.size();i++){
			if(mp.find(data[i].text[column])==mp.end()){
				mp.insert(make_pair(data[i].text[column],k));
				colms(i,0)=k;k++;
			}
			else{
				colms(i,0)=mp[data[i].text[column]];
			}
		}//finished creating encoded column
		//now appending columns created to global matrix
		Matrix.insert_cols(0,colms);
	}
};	
