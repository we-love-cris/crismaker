#pragma once
#pragma warning(disable:4996)

#define _CRT_SECURE_NO_WARNINGS

// declare.h struct status
#define STD_AMOUNT 12 //학생 수
#define ACADEMIC_WEEK 8 //학사일정 총 주차 수
#define ACAD_TYPES 6 //학사일정 종류 수

// declare.h struct types
#define PLAYER_PROF 0
#define PLAYER_STUDENT 1
#define OTHER_STUDENT 2
#define OTHER_PROF 3

// util.h
#define STRING_LENGTH 100 //입력받을 문자의 최대 길이
#define UP 1//방향키 위쪽
#define DOWN 2//방향키 아래쪽
#define LEFT 3//방향키 왼쪽
#define RIGHT 4//방향키 오른쪽
#define ENTER 100//엔터키

//view.h
#define VIEW_HOR 100
#define VIEW_MAIN_VER 30
#define VIEW_INFO_VER 10

#define MENU_HOR 40
#define MENU_VER 20

#define CLASS_ATTEND_RATE 80
#define CLASS_MOVE 30
#define OT_ATTEND_RATE 60
#define OT_MOVE 10
#define TP_ATTEND_RATE 90
#define TP_MOVE 10
#define TEST_ATTEND_RATE 90
#define TEST_MOVE 5
#define FESTIV_ATTEND_RATE 30
#define FESTIV_MOVE 30
#define HOLI_ATTEND_RATE 0
#define HOLI_MOVE 0