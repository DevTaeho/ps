stl의 list를 사용하여 풉니다~
데이터 인덱스 중간에 삽입 및 삭제를 할 필요가 있을 땐 list 자료구조를 사용합니다

#include <iostream>
#include <list>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int tc = 1; tc <= 10; tc++) {
		int c_len, o_len;
		
		list<int> crypt;
		
		// 암호문 길이 입력
		cin >> c_len;

		// 원래 암호문 입력
		for (int i = 0; i < c_len; i++) {
			int num;
			cin >> num;
			crypt.push_back(num);
		}

		// 명령 횟수 입력
		cin >> o_len;

		for (int i = 0; i < o_len; i++) {
			list<int>::iterator Iter;
			list<int> add;
			char o;
			int pos, num_crypt;
			// 명령어 종류, 추가 암호문 위치, 추가 암호문 갯수 입력
			cin >> o >> pos >> num_crypt;

      //삽입할 위치 찾기
			Iter = crypt.begin();
			for (int j = 0; j < pos; j++) {
				Iter++;
			}
			
      // crypt에 삽입될 add 리스트에 삽입될 값 저장
			for (int j = 0; j < num_crypt; j++) {
				int temp;
				cin >> temp;
				add.push_back(temp);
			}

      // crypt 리스트에 pos 뒤에 add 리스트를 추가
			crypt.splice(Iter, add);
		}

		// 출력 부분
		list<int>::iterator Iter2;
		cout << "#" << tc << ' ';
		int i = 0;
		for (Iter2 = crypt.begin(); Iter2 != crypt.end() && i < 10; ++Iter2, i++) {
			cout << *Iter2 << ' ';
		}
		cout << '\n';
	}

	return 0;
}
