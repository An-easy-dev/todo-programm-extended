#ifndef MAIN_FUNC_H_INCLUDED
#define MAIN_FUNC_H_INCLUDED
#include <vector>
using namespace std;
void read(const string& fname,string atribute);
vector<string> parser(const string& command);
void help(const string& command);
vector <string> analizer(const vector<string>& res);
void doer(vector<string> analized);
void add(const string& fname);
#endif // MAIN_FUNC_H_INCLUDED