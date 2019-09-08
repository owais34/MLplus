#include<bits/stdc++.h>

using namespace std;
class Rows{
	public:
	vector<string> text;
	vector<float> numeric;
};
class Dataframe
{	public:
	vector<Rows> data;vector<bool> istext;vector<string> header;
	bool isNumeric(string s)
	{   int count_dec=0;
		for(int j=0;j<s.length();j++)
		{
			if((int)s[j]>=48&&(int)s[j]<=57)
			{
				continue;
			}
			else if(s[j]=='.'&&count_dec<=1)
			{
				count_dec++;continue;
			}
			else
			return false;
		}
		return true;
	}
	Dataframe(string file,char delimiter)//in csv format
	{
	
    ifstream fin; 
  
    string line; 
    fin.open(&file[0]); 
    int i=0;int num_cols=0;
    while (fin) { 
        // Read a Line from standard input 
        getline(fin, line);
		line=line+","; 
        //line contains data 
        if(i==0)
        {   string word="";
        	for(int j=0;j<line.length();j++)
        	{
        		if(line[j]==delimiter||line[j]=='\n')
        		{
        			if(word!="")
        			header.push_back(word);
        			word="";
				}
				else
				word=word+line[j];
			}
			
		}
		else if(i==1)
		{
			istext=std::vector<bool> (header.size(),true);
			string word="";Rows row;int k=0;
        	for(int j=0;j<line.length();j++)
        	{
        		if(line[j]==delimiter||line[j]=='\n')
        		{
        			if(word!="")
        			{
        				if(isNumeric(word))
        				{
						row.numeric.push_back(stof(word));istext[k++]=false;}
        				else
        				{
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
		else
		{
		string word="";int k=0;
		Rows row;
        	for(int j=0;j<line.length();j++)
        	{
        		if(line[j]==delimiter||line[j]=='\n')
        		{
        			if(word!="")
        			{
        				if(!istext[k])
        				{
						row.numeric.push_back(stof(word));k++;}
        				else
        				{
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
	}
	void print(int rows)
	{
		for(int i=0;i<header.size();i++)
		{
			if(!istext[i])
			cout<<header[i]<<"  |";
		}
		for(int i=0;i<header.size();i++)
		{
			if(istext[i])
			cout<<header[i]<<"  |";
		}
		cout<<endl;
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<data[i].numeric.size();j++)
			{
				cout<<data[i].numeric[j]<<"  |";
			}
			for (int j = 0; j < data[i].text.size(); j++)
			{
				cout<<data[i].text[j]<<"   |";
			}
			cout<<endl;
		}

	}
};
int main()
{	cout<<"Enter file name\n";
	string s;
 	cin>>s;
	Dataframe d1(s,',');
	d1.print(30);
	cout<<d1.header.size()<<endl;
	
	return 0;
}

