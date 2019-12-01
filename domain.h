#pragma once

#include "declare.h"
#include "util.h"
#include "view.h"

//메인메뉴 실행, 선택한 항목을 리턴한다
int main_menu();

//1~max까지의 메뉴를 선택하는 함수
int choose_menu(int max);
