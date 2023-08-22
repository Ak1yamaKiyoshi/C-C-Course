#include <iostream>
#include <string> 


using namespace std;

void add(string first, string second) {
  int i_first = first.size()-1;
  int i_second = second.size()-1;
  int temporary = 0;
  cout << "second size: " << i_second << endl;
  string result = ""; 
  for (int i = -1; i <= i_second; i++) {
  	cout << "cur: " << &second[i_second] << endl;
    string added = to_string(atoi(&first[i_first--]) + atoi(&second[i_second--])+ temporary) ;
    if (temporary != 0) temporary = 0;
  	if (added.size() == 2) {
  		result = to_string(atoi(&added[1])) + result;
  		temporary = atoi(&added[0]);
  	} 
  }

  result = first.substr(0, i_first) + result;
  cout << "\n result: "<< result << endl;
}


int main() {

  string bigNum = "100";
  string num = "15";
c
  add(bigNum, num);


  return 0;
}