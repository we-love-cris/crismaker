#include "init.h"
#include "declare.h"
#include "util.h"

int main(void) {
	//구조체들 선언
	status game;
	player_p gg;

	//선언 이후의 초기화
	make_player_p(&gg);
	init_status(&game);

	//게임 시작

	//교수 및 학생 모드 입력받기

	//이름 입력받기

	//게임 시작 앞선 초기화 값들 초기화
	//플레이어에 관련한 정보 입력 및 모드 확정

	//학사 일정 수정 입력받기

	//학사 관련 정보 입력

	//게임 플레이

	system("pause");
	return 0;
}