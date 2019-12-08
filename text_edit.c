#include "text_edit.h"

int text_edit_main(status* game) {
	
}

int editing_file(int prev_number) {//파일 수정
	int lines = 1;
	int cursor = 1;
	int input = 0;//input값 저장
	int temp = 0, temp2 = 0;//line 값 임시저장 및 loop에 사용
	ll pare = { NULL, NULL, NULL, 100 };
	ll* nowline;

	if (0) {//파일 열기
		;
	}
	else {//문제를 새로 만드는 경우
		pare.content = (char*)calloc(100, sizeof(char));
		pare.content[0] = '\0';
		nowline = &pare;
	}
	
	//파일 에디팅
	while (input != 27) {
		input = get_input();
		switch (input) {
		case 8: //backspace
			if (lines == 1 && cursor == 1) {
				
			}
			else if (cursor == 1) {

			}
			else {

				temp = char_delete(nowline->content, cursor - 1);
				cursor -= temp;
			}
			break;
		case 9: //tab
			for (temp = 0; temp < 8; temp++) {
				temp2 = char_input(nowline->content, cursor - 1, 32, nowline->max_size);
				nowline->max_size = temp2;
				cursor++;
			}
			break;
		case 13: //enter
			temp2 = char_input(nowline->content, cursor - 1, 13, nowline->max_size);
			nowline->max_size = temp2;
			if (nowline->next == NULL) {
				making_ll(nowline);
			}
			nowline = nowline->next;
			cursor = 1;
			break;
		case 1000: //up
			if (nowline->prev == NULL) {
				if (cursor > 100) cursor -= 100;
			}
			else {
				nowline = nowline->prev;
				cursor = MIN(cursor, strlen(nowline->content) + 1);
			}
			break;
		case 1001: //down
			if (nowline->next == NULL) {

			}
			else {
				nowline = nowline->next;
				cursor = MIN(cursor, strlen(nowline->content) + 1);
			}
			break;
		case 1002: //left
			if (cursor == 1) {
				if (nowline->prev != NULL) {
					nowline = nowline->prev;
					cursor = strlen(nowline->content) + 1;
				}
			}
			else if (is_hangeul(nowline->content[cursor - 1])) {
				cursor -= 2;
			}
			else {
				cursor--;
			}
			break;
		case 1003: //right
			if (cursor - 1 == strlen(nowline->content)) {
				if (nowline->next != NULL) {
					nowline = nowline->next;
					cursor = 1;
				}
			}
			else if (is_hangeul(nowline->content[cursor - 1])) {
				cursor += 2;
			}
			else {
				cursor++;
			}
			break;

		default:
			temp2 = char_input(nowline->content, cursor - 1, input, nowline->max_size);
			nowline->max_size = temp2;
			cursor++;
			break;
		}
		gotoxy(lines, 1);
		printf("%s\t%d\n", nowline->content, cursor);
		gotoxy(cursor, lines);
		/*
		if (!is_hangeul((char)input)) {
			printf("%s\n", nowline->content);
		}
		*/

	}

	
}

ll* making_ll(ll* prev_line) {
	ll* line = (ll*)malloc(sizeof(ll));
	line->prev = NULL;
	line->next = NULL;
	line->content = (char*)malloc(sizeof(char) * 100);
	line->content[0] = '\0';
	line->max_size = 100;
	if (prev_line->next != NULL) {
		line->next = prev_line->next;
		prev_line->next->prev = line;
	}
	prev_line->next = line;
	line->prev = prev_line;

	return line;
}

void deleting_ll(ll* line) {
	if (line->prev == NULL && line->next == NULL) {
		;
	}
	else if (line->prev == NULL) {
		line->next->prev = NULL;
	}
	else if (line->next == NULL) {
		line->prev->next = NULL;
	}
	else {
		line->prev->next = line->next;
		line->next->prev = line->prev;
	}
	free(line->content);
	free(line);
	return;
}

int making_file() {//파일 없을 때 만들기

}

int get_input() {
	int temp = 0;
	temp = getch();
	if (temp == 224) {
		temp = getch();
		switch (temp) {
		case 72: //up
			temp = 1000;
			break;
		case 80: //down
			temp = 1001;
			break;
		case 75: //left
			temp = 1002;
			break;
		case 77: //right
			temp = 1003;
			break;
		defalut:
			temp = -1;
		}
	}
	return temp;
}

int char_delete(char* content, int at) {
	int ret = 1;
	int i = at - 1;
	int length = strlen(content);
	if (is_hangeul((int)content[at - 1])) {
		i--;
		ret = 2;
	}
	

	for (i; i < length; i++) { //content 마지막에는 항상 null이 있으므로 그것을 포함
		content[i] = content[i + 1];
		if(i == length - 1)
			content[length - ret] = '\0';
	}
	

	return ret;
}

int char_input(char* content, int at, int input, int char_size) {
	int i = 0;
	int length = strlen(content);
	
	if (length + 10 > char_size) {
		content = (char*)realloc(content, char_size * 2);
		char_size *= 2;
	}

	i = at;
	for (i = length; i > at; i--) {
		content[i] = content[i - 1];
	}
	content[at] = (char)input;
	content[length + 1] = '\0';
	return char_size;
}

int is_hangeul(int what) {
	if (0 <= what && what <= 127) {
		return 0;
	}
	return 1;
}