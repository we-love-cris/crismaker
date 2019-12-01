#pragma once

#include <stdio.h>
#include <Windows.h>

#include "declare.h"
#include "util.h"

/*
//시작 화면을 나타낸다.
*/
void v_start();


/*
//v는 view의 약자
//게임 판의 틀을 찍는 역할을 한다.
//게임 판은 메인 화면과 상태 표시 화면이 있다
//상태 표시 화면에서는 정보 텍스트가 표시되고
//주요 내용들은 메인 화면에 표시된다.
//MAIN_SCREEN_HOR : 메인화면 가로 길이(테두리 제외)
//MAIN_SCREEN_VER : 메인화면 세로 길이(")
//INFO_SCREEN_VER : 정보화면 세로 길이(")
//화면들의 가로 길이는 동일하다
*/

void v_ss();

void v_board();