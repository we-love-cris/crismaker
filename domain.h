#pragma once

#include "declare.h"
#include "util.h"
#include "view.h"

//선택한 항목을 리턴한다, 메인 메뉴와 교수학생 선택에 쓰인다
//amount만큼의 항목을 선택할 수 있다
int select_main_menu(int amount);
int select_profvsstd(int amount);


//1~max까지의 메뉴를 선택하는 함수
int choose_menu(int max);
