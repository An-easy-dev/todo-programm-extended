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
  ios_base::openmode openm=ios::app;
  fstream file(fname,ios::app);
  string line;
  cout<<">";
  getline(cin,line);
  file<<line<<':'<<"unfinished";
}

void read(const string& fname,string atribute=""){
  ios_base::openmode atri=ios::in; //file opening mode variable
  if(atribute=="-r"){
    atri=ios::ate;
  }
  ifstream file(fname,atri);
  if(!file.is_open())
    cerr<<"Error occurred while opening file";
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
    cout<<"read:"<<endl;
    cout<<"  -r : reads backwards"<<endl;
    cout<<"  -n : numerates lines"<<endl;
    cout<<"Help : shows available commands and their attributes"<<endl;
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
    if (analized.size()!=2){
      read(analized[2],analized[1]);
    }
    else{
        read(analized[1]);
    }
  }else if(analized[0]=="help" ){
    if (analized[1]==""){
      help(analized[1]);
    }else{
      help();
    }
  }else if(analized[0]=="add"){
      add(analized[1]);
  }else{
    cout<<"wrong command use help to know comand types";
  }
}
