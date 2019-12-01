#pragma once

#include "declare.h"
#include "util.h"

//시작 화면을 보여 준다
void v_start();

//메뉴 선택
//4가지 메인 메뉴를 나타낸다
void v_main_menu();
//학생, 교수를 선택하는 메뉴
void v_profvsstd();
//▶를 표시해주는 함수
void v_menu_indi(int chosen, char ch[3]);

//화면 틀
//메인 선택 화면
void v_menusquare();
//메인 게임 화면
void v_board();

//기능 함수들
void v_row(int height, int amount);
void v_ver(int start, int end, int height, int amount);
void v_clear_menusquare();
void v_clearall();
