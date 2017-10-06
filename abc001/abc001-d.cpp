#include<iostream>
#include<string>
#include <algorithm>

using namespace std ;

int ctoi(char c) {
	switch (c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}
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

int main()
{
  int n;
  cin >> n;
  char data[n][10];

  int size = 60*24/5+1;
  bool rain[size];
  for (int i = 0; i < size; i++) {
    rain[i]= false;
  }

  for(int i;i<n;i++){
      cin >> data[i];
      std::string begin_time(data[i], data[i]+4 );
      std::string end_time(data[i]+5, data[i]+9 );

      int begin_time_serial=0;
      int end_time_serial=0;

      begin_time_serial = 10*60*ctoi(begin_time[0])+60*ctoi(begin_time[1])+10*ctoi(begin_time[2])+ctoi(begin_time[3]);

      if(begin_time_serial%10<5){
        begin_time_serial=begin_time_serial-begin_time_serial%10;
      }else if (begin_time_serial%10>5) {
        begin_time_serial=begin_time_serial-(begin_time_serial%10-5);
      }

      end_time_serial = 10*60*ctoi(end_time[0])+60*ctoi(end_time[1])+10*ctoi(end_time[2])+ctoi(end_time[3]);

      if(end_time_serial%10<5 && end_time_serial%10>0){
        end_time_serial=end_time_serial+(5-end_time_serial%10);
      }else if (end_time_serial%10>5) {
        end_time_serial=end_time_serial+(10-end_time_serial%10);
      }

      int begin_id = begin_time_serial/5;
      int end_id = end_time_serial/5;

      for(int i=begin_id; i<end_id; i++){
        rain[i]=true;
      }
  }
	int count = 0;
	std::string h_str;
	std::string m_str;
	while(count!=size){
		int h,m;
		if(rain[count]==false){
			count++;
		}else{
			h=count*5/60;
			m=(count*5)%60;
			h_str = fill(h);
			m_str = fill(m);
			std::cout<<h_str<<':'<<m_str<<'-';
			while(rain[count]==true){
				count++;
				if(rain[count]==false){
					h=count*5/60;
					m=(count*5)%60;
					h_str = fill(h);
					m_str = fill(m);
					std::cout<<h_str<<':'<<m_str<<std::endl;
				}
			}
		}
	}
  return 0;
}
