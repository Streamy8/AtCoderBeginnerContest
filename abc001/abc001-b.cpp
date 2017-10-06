#include<iostream>

std::string fill(int input){
	std::string filled("00");
	if(input/10==0){
		filled[1]= '0'+input;
	}else{
		filled[0]= '0'+input/10;
		filled[1]= '0'+input%10;
	}
	return filled;
}

int main(){
  int m;
  float m_km;
  int vv;
  std::cin >> m;

  m_km = m / 1000.0;
  if(m_km<0.1){
    vv=0;
  }else if(0.1<=m_km && 5>=m_km){
    vv = m_km *10;
  }else if(6<=m_km && 30>=m_km){
    vv = m_km +50;
  }else if(35<=m_km && 70>=m_km){
    vv = (m_km-30)/5.0 +80;
  }else if(m_km>70){
    vv = 89;
  }else{
    std::cout << "input error" << std::endl;
  }
  std::cout << fill(vv) << std::endl;

}
