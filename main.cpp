#include <iostream>
#include "main_func.h"
using namespace std;

int main(){
  string input;
  cout<<"Hello this is a todo list program that shows,creates,edit,todo lists press help to understand commands"<<endl;
  while (1){
    cout<<'<';
    getline(cin,input);
    vector<string> parsed=parser(input);
    vector<string> res=analizer(parsed);
    doer(res);
    cout<<endl;
  }
  return 0;
}
