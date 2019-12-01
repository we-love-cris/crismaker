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
		menu_screen();
		menu_select = game->func_list.mp[0](4);

		switch (menu_select) {
		case 1://게임 시작, 모드 선택
			menu_screen();
			game_mode = game->func_list.mp[1](2);
			break;
		case 2://학사일정 편집
			game_screen();
			break;
		case 3://시험문제 수정
			game_screen();
			break;
		case 4://게임 종료
			game_screen();
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
