#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>

int n;
int m;  //議員idは0~n-1
int *x;
int *y;

void add_candidate(bool* candidate_p, bool* state_p, int added, int* max) {

  bool candidate[n];//candidateをコピー
  for (int i=0; i<n ;i++) {
    candidate[i]=candidate_p[i];
  }
  bool state[n];//stateをコピー
  for (int i=0; i<n ;i++) {
    state[i]=state_p[i];
  }

  //state,candidate更新
  state[added]=1;
  candidate[added]=0;

  for(int i=0;i<n;i++){//candidate更新，新たに追加された議員とリンクのない議員を削除
    if(candidate[i]){
      bool flg = 0;
      for (size_t j = 0; j<m; j++) {//全ての人間関係を確認
        if(x[j]==added && y[j]==i){
          flg=1;
        }
        if(y[j]==added && x[j]==i){
          flg=1;
        }
      }
      if(flg==0){candidate[i]=0;}
    }
  }


  if(std::accumulate(candidate,candidate+n,0)==0) { //candidateがいなければmax更新して終了
    if(std::accumulate(state,state+n,0)>*max){
      *max = std::accumulate(state, state+n,0);
    }
  }else{//candidateがいる場合には再帰処理
    for (size_t i = 0; i < n; i++) {
      if(candidate[i]==1 && added<i){
          add_candidate(candidate, state, i, max);
      }
    }
  }
}

int main()
{
  std::cin >> n;
	std::cin >> m;
  x = new int[m];
  y = new int[m];

  bool candidate[n]; //追加可能な議員のリスト，1:追加可能
  for (int i=0; i<n ;i++) { //初期は全て1
    candidate[i]=1;
  }

  bool state[n]; //現状態，1:追加済み
  for (int i=0; i<n ;i++) { //初期は全て0
    state[i]=0;
  }

  int max=1; //派閥の最大人数

  for (int i=0; i<m ;i++) {
    int x_tmp,y_tmp;
    std::cin >> x_tmp;
    std::cin >> y_tmp;
    x[i]=x_tmp-1;
    y[i]=y_tmp-1;
  }

  for (size_t i = 0; i < n; i++) {
    add_candidate(candidate, state, i, &max);
  }
  std::cout << max << std::endl;
  return 0;
}
