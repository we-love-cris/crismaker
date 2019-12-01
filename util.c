#include "util.h"

//max, min
/*
//max와 min을 정의한다
*/
int MAX(int a, int b) {
	if (a >= b) return a;
	return b;
}

//a와 b중 더 작은 수를 반환
int MIN(int a, int b) {
	if (a <= b) return a;
	return b;
}

//input, get
/*
//string을 입력받는 함수. 문자열의 길이('\0' 미포함)를 return 한다.
//입력받는 데에 실패한 경우, -1을 return 한다.
//length는 constants.h의 STRING_LENGTH 라고 가정하지만, STRING_LENGTH 이하의 다른 숫자를 입력할 수도 있다.
//최대값은 STRING_LENGTH이다
//string은 입력받은 문자열이 저장될 주소, length는 '\0'을 포함한 string의 길이이다
*/
int get_string(char* string, int length) {
	char ret[STRING_LENGTH] = { '\0', }; //입력받은 문자열이 저장되는 임시 저장소
	char temp = '0'; //임시로 입력받은 저장 공간
	int nowlength = 0; //min(length, STRING_LENGTH);
	int i = 0, j = 0; //루프문에 사용될 값
	int flag = 0; //오류의 발생 여부를 저장하는 공간

	nowlength = MIN(length, STRING_LENGTH);

	for (i = 0; i < nowlength; i++) {
		scanf("%c", &temp);

		if (temp == '\n' || temp == '\0') {
			//엔터 혹은 NULL문자가 들어오는 경우 NULL문자를 저장하고 break하도록 한다.
			ret[i] = '\0';
			break;
		}

		if (i == nowlength - 1) {
			//엔터 혹은 NULL문자가 아니었지만 입력이 끝나야 정상이다
			flag = 1; //-1을 return해야 하므로 flag = 1;
			i = 0; //버퍼를 비우기 위해 루프를 끝까지 돌려야 한다
		}

		if (!flag) {
			//ret[i]에 temp 값 저장
			ret[i] = temp;
		}
	}

	if (flag) { //범위를 초과한 경우
		printf("입력 범위를 초과하였습니다.\n");
		return -1;
	}
	for (j = 0; j <= i; j++) {
		string[j] = ret[j];
	}

	return i; //for루프의 n번째까지 문자이고(n - 1번째 루프), n + 1번째(n번째)가 '\n'인 경우, i = n인 상태에서 break;되었을 것이다
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
		//if 문 앞에 !flag &&를 추가하도록 한다.
		*/

		if (!flag && '0' <= temp && temp <= '9') {
			ret *= 10;
			ret += (temp - '0');
			//overflow가 발생하는 지 확인하는 과정이 필요하다
		}
		else {
			//'\n'도, '\0'도, 0~9의 문자도 아닌 경우
			flag = 1;
		}
	}

	if (flag) {
		printf("올바른 정수를 입력해 주세요.\n"); //오류 메시지 출력(필요에 따라 수정해야할 수 있음)
		return -1; //오류가 발생했으면 -1 return
	}
	return ret; //제대로 입력되었으면 1 return
}

int get_wasd() {
	int key = 0;
	key = getch();
	switch (key) {
	case 119://'w'
	case 87: //'W'
		return UP;
		break;
	case 97://'a'
	case 65://'A'
		return LEFT;
		break;
	case 115://'s'
	case 83: //'S'
		return DOWN;
		break;
	case 100://'d'
	case 68: //'D'
		return RIGHT;
		break;
	case 13:
	case 10://'\n'
		return ENTER;
		break;
	case 224://방향키인 경우
		key = getch();
		switch (key) {
		case 72://up
			return UP;
			break;
		case 80://down
			return DOWN;
			break;
		case 75://left
			return LEFT;
			break;
		case 77://right
			return RIGHT;
			break;
		default://wrong
			return 0;
			break;
		}
		break;
	default:
		return 0;
		break;
	}
}

// sorting
//한글을 정렬하는 함수, 학생 생성 후 출석부에 넣을 때 이용할 예정
int hangeul_sort() {

}

void menu_screen() {
	system("mode con: cols=44 lines=24"); return;
}

void game_screen() {
	system("mode con: cols=104 lines=44"); return;
}

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void textcolor(int text_color, int background_color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_color | background_color * 16);
}
