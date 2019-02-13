기존 암호문 문제에 list에 push하는 조건만 생겼다

#include <iostream>
#include <list>

using namespace std;

void my_insert(list<int> &crypt, int pos, int num_crypt) {
	list<int>::iterator Iter;
	list<int> add;

	Iter = crypt.begin();
	for (int j = 0; j < pos; j++) {
		Iter++;
	}

	for (int j = 0; j < num_crypt; j++) {
		int temp;
		cin >> temp;
		add.push_back(temp);
	}

	crypt.splice(Iter, add);
}

void my_delete(list<int> &crypt, int pos, int num_crypt) {
	list<int>::iterator firstIdx, lastIdx;
	firstIdx = crypt.begin();
	lastIdx = crypt.begin();

	for (int i = 0; i < pos; i++) {
		firstIdx++;
	}

	for (int i = 0; i < num_crypt + pos; i++) {
		lastIdx++;
	}

	crypt.erase(firstIdx, lastIdx);
}

void my_append(list<int> &crypt, int num_crypt) {
	for (int i = 0; i < num_crypt; i++) {
		int temp;
		cin >> temp;
		crypt.push_back(temp);
	}
}

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

			list<int> add;
			char o;
			int pos, num_crypt;
			// 명령어 종류, 추가 암호문 위치, 추가 암호문 갯수 입력
			cin >> o;

			switch (o)
			{
			case 'I': 
				cin >> pos >> num_crypt;
				my_insert(crypt, pos, num_crypt);
				break;
				
			case 'D': 
				cin >> pos >> num_crypt;
				my_delete(crypt, pos, num_crypt);
				break;

			case 'A': 
				cin >> num_crypt;
				my_append(crypt, num_crypt);
				break;
			default:
				break;
			}

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
