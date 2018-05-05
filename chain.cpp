#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include "block.cpp"

using namespace std;

class chain{
public: 
	vector<block> ch;
	
	void loadBlocks(string fname){
		ifstream f(fname.c_str());
		block t;
		while(f >> t){
			if (ch.size() == 0){
				ch.push_back(t);
			}
			else {
				if(checkblockvalidity(t)){
					ch.push_back(t);
				}
			}
		}
		f.close();
	}
	
	bool checkblockvalidity(block temp){
		//cout<< temp.hash << endl;
		//cout << temp.makehash(temp.calculator) << endl;
		string hash = temp.hash;
		if(hash != temp.makehash(temp.calculator))
		{/*cout<<"bad hash\n";*/return false; }
		if(temp.lasthash != ch[ch.size()-1].hash)
		{/*cout<<"bad past hash\n" << ch[ch.size()-1].hash<<endl<<temp.lasthash<<endl;*/return false; }
		if (ch.size() > 2){
			if(temp.difficulty != temp.getdifficulty(ch[ch.size()-3],ch[ch.size()-2]))
			{/* cout<<"bad difficulty\n";*/return false;}
		}
		bool var = true;
		for(int i = 0; i < temp.hash.length() && i < temp.difficulty; i++){
			if (temp.hash[i] != '0') var = false;
		}
		return var;
	}
};