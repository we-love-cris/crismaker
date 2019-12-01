#pragma once

#include "declare.h"
#include "util.h"

//시작 화면을 보여 준다
void v_start();

//메뉴 선택
void v_main_menu();

//화면 틀
//메인 선택 화면
void v_menusquare();
//메인 게임 화면
void v_board();

//기능 함수들
void v_row(int height);
void v_ver(int start, int end, int height, int amount);
