#include "constants.h"
#include "init.h"
#include "declare.h"

void allocname(status *game, char * name, int i) {
	int len = 0;

	game->student_list[i]->name = (char *)realloc(game->student_list[i]->name, sizeof(char) * strlen(name));
	strcpy(game->student_list[i]->name, name);
	if (game->student_list[i]->name == NULL) {
		printf("Error: 이보다 많은 학생 수는 수업을 듣길 원치 않습니다.\n");
		exit(1);
	}
}
void stdnaming(status *game) {
	int i, len = 0;
	int y = 3;
	char * name;

	system("mode con: cols=44 lines=36");

	name = malloc(sizeof(char));
	if (name == NULL) {
		printf("학생 정보 입력 중 에러 발생! \n");
		printf("Error: 학생 이름을 불러일으킬 수 없습니다.\n");
		exit(1);
	}

	for (i = 0; i < STD_AMOUNT; i++) {
		//출석부랑 연동시켜서 1~12번째 이름 입력받게 하고
		gotoxy(3, y); printf("%d 번째 학생 --> 이름 입력: ", i + 1);
		scanf("%s", name);
		allocname(game, name, i);
		//이름을 학생 정보에 연동시켜서 저장해야 함.
		y = y + 2;
	}
}
