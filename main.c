#include "declare.h"
#include "util.h"
#include "init.h"
#include "view.h"
#include "domain.h"
#include "acad_day.h"


int main(void) {
	//선언 및 초기화
	int life = 1;
	int menu_select = 0;
	int game_mode = 0;

	status* game = init_status();
	init_consol(game);

	//게임 시작 화면(press any key)
	v_start();
	//메인 메뉴
	while (life) {
		game->db->func_list.screen_size[0]();
		menu_select = game->db->func_list.show_menu[0](4);
		switch (menu_select) {
		case 1://게임 시작, 모드 선택
			game->db->func_list.screen_size[0]();
			game_mode = game->db->func_list.show_menu[1](2);
			stdnaming(game);
			break;
		case 2://학사일정 편집
			game->db->func_list.screen_size[1]();
			break;
		case 3://시험문제 수정
			game->db->func_list.screen_size[1]();
			break;
		case 4://게임 종료
			game->db->func_list.screen_size[1]();
			return -1;
			life = 0;
			break;
		default:
			life = 0;
			break;
		}
		//교수 및 학생 모드 입력받기

		//이름 입력받기

		//게임 시작 앞선 초기화 값들 초기화
		//플레이어에 관련한 정보 입력 및 모드 확정

		//학사 일정 수정 입력받기

		//학사 관련 정보 입력

		//게임 플레이




	}
	gotoxy(0, 0);

	system("pause");
	return 0;
}


//test 용

//int main(void) {
//	student a = { 0,0,0,0,0,0,0,0, "박용준" };
//	student b = { 0,0,0,0,0,0,0,0, "준용박" };
//	student c = { 0,0,0,0,0,0,0,0, "박박박박" };
//	student d = { 0,0,0,0,0,0,0,0, "박용준용" };
//	student e = { 0,0,0,0,0,0,0,0, "박용준용준" };
//	student f = { 0,0,0,0,0,0,0,0, "박박박김" };
//	student g = { 0,0,0,0,0,0,0,0, "박박박님" };
//
//	student** student_list = (student**)malloc(sizeof(student*) * 7);
//	student_list[0] = &a;
//	student_list[1] = &b;
//	student_list[2] = &c;
//	student_list[3] = &d;
//	student_list[4] = &e;
//	student_list[5] = &f;
//	student_list[6] = &g;
//
//	for (int i = 0; i < 7; i++) {
//		printf("%s\n", student_list[i]->name);
//	}
//
//	hangeul_sort(student_list, 7);
//
//	printf("\n");
//
//	for (int i = 0; i < 7; i++) {
//		printf("%s\n", student_list[i]->name);
//	}
//
//
//
//	system("pause");
//	return;
//}
