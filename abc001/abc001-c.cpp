#include<iostream>
#include<string>
#include <algorithm>
#include <cstring>

using namespace std ;

int main()
{
  int deg, dis;
  char dir[4];
  cin >> deg;
  cin >> dis;
  double deg_actual = deg/10.0;

  char dirList[17][4] = {"C","N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"};
  int dirId = (int)((deg_actual-11.25)/22.5);

  double speed_actual = dis*10/60.0;
  double speed_approx = ((int)(speed_actual + 0.5))/10.0;
  if(speed_approx<=0.2){
    strcpy(dir,"C");
  }else if(deg_actual<11.25||deg_actual>=348.75){
    strcpy(dir,"N");
  }else{
    strcpy(dir,dirList[dirId+2]);
  }

  int w;
  if(speed_approx<=0.2){
    w=0;
  }else if(speed_approx<=1.5){
    w=1;
  }else if(speed_approx<=3.3){
    w=2;
  }else if(speed_approx<=5.4){
    w=3;
  }else if(speed_approx<=7.9){
    w=4;
  }else if(speed_approx<=10.7){
    w=5;
  }else if(speed_approx<=13.8){
    w=6;
  }else if(speed_approx<=17.1){
    w=7;
  }else if(speed_approx<=20.7){
    w=8;
  }else if(speed_approx<=24.4){
    w=9;
  }else if(speed_approx<=28.4){
    w=10;
  }else if(speed_approx<=32.6){
    w=11;
  }else{
    w=12;
  }

  cout<<dir<< " "<< w <<endl;
  return 0;
}
