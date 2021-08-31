// 깨알나라 신문사
//프로그래머스에서는 main함수 및 입출력문이 필요하지 않습니다. 대신 solution함수만 작성하면 됩니다.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> solution(int r, int c, int zr, int zc, vector<string> words) {
    vector<string> answer;
    
		string resize = "";
	  for (int i=0; i<r; i++) {
			// 가로로 확대
			for (int j=0; j<c; j++){
				for (int k=0; k<zc; k++){
					resize += words[i][j];
				}
			}
			// 세로로 확대
			for (int p=0; p<zr; p++){
					answer.push_back(resize);
			}
			resize = "";
		}

    return answer;
}

using namespace std;
int main() {
	int r, c, zr, zc;
	vector<string> answer, words;
	string temp;
	
	cin >> r >> c >> zr >> zc;
	
	for(int i=0; i<r; i++)
	{
		cin >> temp;
		if(temp.length()>c)
		{
			cout << "입력 범위를 초과하였습니다.\n";
			exit(1);
		}
		words.push_back(temp);
	}
  
  answer = solution(r, c, zr, zc, words);
  
	for(auto i : answer)
	{
		cout << i << endl;
	}
	
	return 0;
}