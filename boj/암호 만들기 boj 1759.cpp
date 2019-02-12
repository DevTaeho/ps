문제 URL ___ https://www.acmicpc.net/problem/1759

라이님의 블로그의 backtracking 강의를 통해 공부하면서 접한 문제다

backtracking은 dfs에서 가지치기를 한 형태를 띈다

이 문제의 경우 자음 2개 이상, 모음 1개 이상, 정렬된 암호를 구하는 문제다

#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char input[20];
char p[20];
bool isVowel[26];

void backtrack(int depth, int prev, int consonant, int vowel) {
	if (depth == L) {
		if (consonant >= 2 && vowel >= 1) {
			puts(p);
		}
		return;
	}

	for (int i = prev + 1; i < C; i++) {
		p[depth] = input[i];
		backtrack(depth + 1, i, consonant + !isVowel[input[i] - 'a'], vowel + isVowel[input[i] - 'a']);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	isVowel[0] = isVowel[4] = isVowel[8] = isVowel[14] = isVowel[20] = true;

	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin >> input[i];
	}

	sort(input, input + C);

	backtrack(0, -1, 0, 0);

	return 0;
}
