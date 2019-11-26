#include "util.h"

//input, get
/*
//string을 입력받는 함수. 문자열의 길이를 return 한다.
//입력받는 데에 실패한 경우, -1을 return 한다.
//constants.h의 STRING_LENGTH - 1만큼 입력받을 수 있다
*/
int get_string() {

}

/*
//양수의 정수를 입력받는 함수
//int의 범위만큼 입력받을 수 있다
//입력에 실패하면 -1을 리턴한다
//char을 1개씩 scanf하여 버퍼 문제를 해결할 수 있다.
*/
int get_unsigned_int() {
	char temp = '0'; //임시로 입력받을 저장 공간
	int ret = 0; //리턴될 정수
	int i = 0; //루프문에 사용될 값
	for (i = 0; i < 11; i++) {
		scanf("%c", &temp);
		if ('0' <= temp && temp <= '9') {
			ret *= 10;
			ret += temp - '0';
		}
		if (temp == '\n') {

		}
	}
}

// sorting
//한글을 정렬하는 함수, 학생 생성 후 출석부에 넣을 때 이용할 예정
int hangeul_sort() {

}