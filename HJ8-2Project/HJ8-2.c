#include <stdio.h>
#define MAX 100
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
typedef struct stacktype { 
char stack[MAX];
int top;
}stacktype;
void init(stacktype* s) { 
	s->top = -1;
}
int is_full(stacktype* s) { 
	return (s->top == MAX - 1);
}
int is_empty(stacktype* s) { 
	return (s->top == -1);
}
char pop(stacktype* s) { 
	char out; 
	out = s->stack[(s->top)--]; 
	return out;
}
void push(stacktype* s, char item) {
	s->stack[++(s->top)] = item; 
}
int check_matching(char input_string[]) { 
	stacktype s; 
	int i = 0;  
	init(&s); 
	while (input_string[i] != NULL) { 
		if ('a' <= input_string[i] && input_string[i] <= 'z') { 
			if (is_full(&s)) { 
				printf("스택이 가득 찼습니다.");
				return 0;
			}
			push(&s, input_string[i]);  // 참이면 스택에 추가
		}
		else if ('A' <= input_string[i] && input_string[i] <= 'Z') { // 입력 받은 문자가 A~Z 사이면 실행
			if (is_full(&s)) { // 스택 포화 검사
				printf("스택이 가득 찼습니다.");
				return 0;
			}
			char c = input_string[i] + ('a' - 'A'); // 대문자를 소문자로 변경
			push(&s, c); // 스택에 추가
		}
		i++; // 문자길이 변수 증가
	}
	i = 0; // 문자길이 변수 초기화
	int j = 0; // 알파벳이 아닌 문자를 카운트해주는 변수
	while (input_string[i + j] != NULL) { // 문자열의 끝까지 반복
		if (isalpha(input_string[i + j]) != 0) { // 입력받은 문자가 알파벳이면 실행
			if ('a' <= input_string[i + j] && input_string[i + j] <= 'z') { // a~z 사이 이면
				if (pop(&s) != input_string[i + j]) return 0; // 스택에서 꺼낸값과 입력받은 문자가 다르면 종료
			}
			else if ('A' <= input_string[i + j] && input_string[i + j] <= 'Z') { // A~Z 사이 이면
				char a = input_string[i] + ('a' - 'A'); // 대문자를 소문자로 변경
				if (pop(&s) != a) return 0;  // 스택에서 꺼낸값과 입력받은 문자가 다르면 종료
			}
			i++; // 문자 길이 변수 증가
		}
		else j++; // 알파벳이 아닌것을 카운트
	}
	if (!is_empty) printf("검사가 제대로 이루어지지 않았습니다"); // 공백 상태가 아니면  실행
	return 1; 
}
int main() {
	char input_string[MAX] = { NULL };
	char word[100];

		printf("문자열을 입력하시오>>");
		gets_s(input_string, sizeof(input_string));
		if (check_matching(input_string) == 1) printf("회문입니다.\n");
		else printf("회문이 아닙니다.\n");
	int exit = 0;
	while (1) {
		printf("다시 입력하시겠습니까? (yes/no) : ");
		scanf("%s", word);
		if (strcmp(word, "yes") == 0) {
			break;
		}
		else if (strcmp(word, "no") == 0) {
			exit = 1;
			break;
		}

	}
	if (exit == 1) {
		getchar(); 
	}


	return 0;
}