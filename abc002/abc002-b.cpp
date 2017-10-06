#include<iostream>
#include<string>
#include <algorithm>


int main()
{
  std::string w;
  std::string result;
  std::cin >> w;

  for(int i=0;i<w.size();i++){
    if(w[i]!='a' &&w[i]!='i' &&w[i]!='u' &&w[i]!='e' &&w[i]!='o'){
      //result.push_back(w[i]);
      result += w[i];
    }
  }

  std::cout<< result << std::endl;

  return 0;
}
