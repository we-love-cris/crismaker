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
//int의 범위 중 양수만큼 입력받을 수 있다(0 ~ 2^31 - 1)
//입력에 실패하면 -1을 리턴한다
//char을 1개씩 scanf하여 버퍼 문제를 해결할 수 있다.
*/
int get_unsigned_int() {
	char temp = '0'; //임시로 입력받을 저장 공간
	int ret = 0; //리턴될 정수
	int i = 0; //루프문에 사용될 값
	int flag = 0; //int범위를 넘어가거나, 0~9의 숫자가 입력되었으면 1이 된다.

	for (i = 0; i < 11; i++) {
		scanf("%c", &temp);
		if (temp == '\n' || temp == '\0') {
			//엔터가 들어오면 입력 끝
			//null문자가 들어오는 경우도 상정해 보았다...?
			break;
		}

		if (i == 10) {
			//11번째 입력이지만, '\n'이 아니었다.
			//11번째의 입력이 숫자라고 하더라도 int의 범위를 넘어간다
			flag = 1; //그래서 -1을 리턴해야 한다 -> flag = 1
			i = 0; //i를 0으로 만들어서, for루프를 돌려 buffer를 비우는 과정
		}

		/*
		//flag == 1이라면, 이미 오류 값을 return해야 하는 상황이다.
		//temp값을 처리하는 과정은 무의미하다.
		//if(flag) continue; 를 넣어도 되지만, continue를 최 교수님이 안 좋아하시기에,
		//if 문 앞에 !temp &&를 추가하도록 한다.
		*/

		if (!temp && '0' <= temp && temp <= '9') {
			ret *= 10;
			ret += (temp - '0');
			//overflow가 발생하는 지 확인하는 과정이 필요하다
		}
		else {
			//'\n'도, '\0'도, 0~9의 문자도 아닌 경우
			flag = 1;
		}
		
		if (flag) {
			printf("올바른 정수를 입력해 주세요."); //오류 메시지 출력(필요에 따라 수정해야할 수 있음)
			return -1; //오류가 발생했으면 -1 return
		}
		return ret; //제대로 입력되었으면 1 return
	}
}

// sorting
//한글을 정렬하는 함수, 학생 생성 후 출석부에 넣을 때 이용할 예정
int hangeul_sort() {

}