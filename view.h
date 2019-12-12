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
void v_acad_cal(day** acad_cal);
void v_acad_days(day** default_days);
//▶를 표시해주는 함수
void v_menu_indi(int chosen, char ch[3]);
void v_week_indi(int chosen, char ch[3]);
void v_toWeek_indi(int chosen, char ch[3]);
void v_toWeek_info(int chosen);

//화면 틀
//메인 선택 화면
void v_menusquare();
//메인 게임 화면
void v_board();

//기능 함수들
void v_row(int height, int amount);
void v_ver(int start, int end, int height, int amount);
void v_clear_menusquare();
void v_clear_right();
void v_clear_optbox();
void v_clearall();

void v_main_game_show_p(status* game, int* work);
void v_main_game_frame_p();
void v_attend(int std_no, int isAttend, int isWake);
void v_gohome();
void v_prof_status(status* game);

void v_end_game_p(char* score);

void v_main_game_show_s(status* game, int* work);
void v_std_status(status* game);
void v_what_prof_do(int isProgress);

void v_end_game_s(char* score);