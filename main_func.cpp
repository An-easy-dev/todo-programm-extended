#include <cstdio>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <cstdint>
#include "main_func.h"
using namespace std;
void add(const string& fname) {
  fstream file(fname,ios::app);
  string line;
  cout<<">";
  getline(cin,line);
  file<<line<<':'<<"unfinished"<<endl;
}
void finish(const string& fname){
  uint64_t num;
  cout<<"enter a line:";
  cin>>num;
  string line;
  size_t i=1;
  string tmp="temp.txt";
  ifstream file(fname);
  ofstream tile(tmp);
  if (!file.is_open() && !tile.is_open()){
    cerr<<"Encoutered an error while opening file ERROR_CODE:15";
  }
  while(getline(file,line)){
    if (line.find("unfinished")==string::npos){
      string ln=line.substr(0,line.find(':')+1)+"unfinished";
      tile<<ln<<endl;
    }else if(i==num){
      uint64_t pos=line.find("unfinished");
      string ln=line.substr(0,pos)+"finished";
      tile<<ln<<endl;
    }else{
      tile<<line<<endl;
    }
    i++;
  }
  remove(fname.c_str());
  rename(tmp.c_str(),fname.c_str());
  file.close();
  tile.close();

  cin.ignore();
}
void read(const string& fname){
  ifstream file(fname);
  if(!file.is_open())
    cerr<<"Error occurred while opening file"<<endl;
  string line;
  size_t num=1;
  while (getline(file,line)){
    cout<<num<<':';
    num++;
    cout<<line<<endl;
  }
  file.close();
}

vector<string> parser(const string& command){
  vector <string> res;
  string buff;
  istringstream stream(command);
  while (stream>>buff)
    res.push_back(buff);
  return res;
}

void help(const string& command=""){
  if(command==""){
    cout<<"command attribute input"<<endl;
    cout<<"read: reads file\'s tasks"<<endl;
    cout<<"Help : shows available commands and their attributes"<<endl;
    cout<<"add : adds unfinished task"<<endl;
    cout<<"finish: finishes a certain task in the surtain line"<<endl;
  }
}
vector <string> analizer(const vector<string>& res){
  vector<string> divider;
  string line;
  divider.push_back(res[0]);
  if (res.size()-1==0){ // if non of the atributes is showed
    return divider;
  }
  divider.push_back(res[1]);
  if(res.size()-2==0){ // if we got somethin
    return divider;
  }
  for(size_t i=2;i<res.size();i++){
    line+=res[i];
  }
  divider.push_back(line);
  return divider;
}
void doer(vector<string> analized){
  if (analized[0]=="read"){
    read(analized[1]);
  }else if(analized[0]=="help" ){
    if (analized[1]==""){
      help(analized[1]);
    }else{
      help();
    }
  }else if(analized[0]=="add"){
      add(analized[1]);
  }else if(analized[0]=="finish"){
    finish(analized[1]);
  }else{
    cout<<"wrong command use help to know comand types";
  }
}
