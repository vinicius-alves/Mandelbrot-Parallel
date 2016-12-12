#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<string> explode(const string& s, const char& c)
{
	string buff{""};
	vector<string> v;
	
	for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);
	
	return v;
}

int main(){

float matriz[24000][3];

string data = "{-0.500,0.0000,300.0},{-0.500,0.5000,300.0},{0.0000,0.0000,300.0},{0.0000,0.5000,300.0},{0.5000,0.0000,5.000},{0.5000,0.5000,5.000},{-1.500,0.5000,3.000},{-1.000,0.0000,300.0},{-1.000,0.5000,5.000},{-2.000,0.0000,300.0},{-2.000,0.5000,2.000},{-1.500,0.0000,300.0},{0.0000,-0.500,300.0},{0.5000,-1.000,3.000},{0.5000,-0.500,5.000},{-0.500,-1.000,4.000},{-0.500,-0.500,300.0},{0.0000,-1.000,300.0},{-1.500,-0.500,3.000},{-1.000,-1.000,3.000},{-1.000,-0.500,5.000},{-2.000,-1.000,2.000},{-2.000,-0.500,2.000},{-1.500,-1.000,2.000}";

vector<string> v = explode(data, '}');

for(int i; i<v.size(); i++){
	cout<< "v["<<i<<"]: "<<v[i]<<endl;
	if(i==0){

	}
	else{
		
	}
}




	return 0;
}