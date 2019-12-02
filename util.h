#pragma once

//기본 라이브러리 및 상수값, 구조체 include
#include "declare.h"

/*
//util.h 는 여러 기능을 담고 있는 헤더다
//주로 코드를 아끼거나 알고리즘을 수행할 듯
*/


//max, min
/*
//max와 min을 정의한다
*/
int MAX(int a, int b);
int MIN(int a, int b);


//input, get
/*
//문자열을 입력받는 함수. constants.h의 STRING_LENGTH - 1만큼 받을 수 있다.
//입력에 성공하면 문자열의 길이('\0'미포함)를, 실패하면 -1을 리턴한다.
//string은 문자열이 저장될 곳의 주소, length는 입력받을 최대 길이이다('\0' 포함).
//length는 평소의 상황에서는 STRING_LENGTH를 입력하는 것으로 가정하나,
//STRING_LENGTH 이하의 임의의 입력이 있는 경우도 처리한다. 즉, STRING_LENGTH가 length의 최대 값이다
//int a = -1;
//while(a == -1) {
//	//optional printf("입력할 문자열을 입력하시오 : ");
//	a = get_string(...);
//}
//이와 같은 용법으로 사용하면 올바른 사용을 할 수 있다.
*/
int get_string(char* string, int length);

/*
//양수의 정수와 0을 입력받는 함수. int의 양의 정수의범위 만큼 입력받을 수 있다
//입력에 실패하면 -1을 리턴한다.
//int a = -1;
//while(a == -1) {
//	//optional printf("입력할 정수를 입력하시오 : ");
//	a = get_unsigned_int();
//}
//이와 같은 용법으로 사용하면 올바른 사용을 할 수 있다.
*/
int get_unsigned_int();

/*방향키 혹은 wasd로 방향을 읽는 함수
//위, 아래, 왼쪽, 오른쪽 순서로 UP, DOWN, LEFT, RIGHT를 리턴
//엔터는 100을 리턴
//그 외의 의미없는 문자는 0을 리턴
*/
int get_wasd();


// sorting
 //한글을 정렬하는 함수, 학생 생성 후 출석부에 넣을 때 이용할 예정
int hangeul_sort(char* student_list, int amount);

void gotoxy(int x, int y);
void textcolor(int text_color, int background_color);

void menu_screen();
void game_screen();
