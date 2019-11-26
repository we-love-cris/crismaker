#pragma once

//기본 라이브러리 및 상수값, 구조체 include
#include "declare.h"

/*
//util.h 는 여러 기능을 담고 있는 헤더다
//주로 코드를 아끼거나 알고리즘을 수행할 듯
*/




//input, get
/*
//문자열을 입력받는 함수. constants.h의 STRING_LENGTH - 1만큼 받을 수 있다.
//입력에 성공하면 문자열의 길이를, 실패하면 -1을 리턴한다.
*/
int get_string();

/*
//양수의 정수와 0을 입력받는 함수. 정수의 범위만큼 입력받을 수 있다
//입력에 실패하면 -1을 리턴한다.
*/
int get_unsigned_int();




// sorting
int hangeul_sort(); //한글을 정렬하는 함수, 학생 생성 후 출석부에 넣을 때 이용할 예정