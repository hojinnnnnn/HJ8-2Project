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
				printf("������ ���� á���ϴ�.");
				return 0;
			}
			push(&s, input_string[i]);  // ���̸� ���ÿ� �߰�
		}
		else if ('A' <= input_string[i] && input_string[i] <= 'Z') { // �Է� ���� ���ڰ� A~Z ���̸� ����
			if (is_full(&s)) { // ���� ��ȭ �˻�
				printf("������ ���� á���ϴ�.");
				return 0;
			}
			char c = input_string[i] + ('a' - 'A'); // �빮�ڸ� �ҹ��ڷ� ����
			push(&s, c); // ���ÿ� �߰�
		}
		i++; // ���ڱ��� ���� ����
	}
	i = 0; // ���ڱ��� ���� �ʱ�ȭ
	int j = 0; // ���ĺ��� �ƴ� ���ڸ� ī��Ʈ���ִ� ����
	while (input_string[i + j] != NULL) { // ���ڿ��� ������ �ݺ�
		if (isalpha(input_string[i + j]) != 0) { // �Է¹��� ���ڰ� ���ĺ��̸� ����
			if ('a' <= input_string[i + j] && input_string[i + j] <= 'z') { // a~z ���� �̸�
				if (pop(&s) != input_string[i + j]) return 0; // ���ÿ��� �������� �Է¹��� ���ڰ� �ٸ��� ����
			}
			else if ('A' <= input_string[i + j] && input_string[i + j] <= 'Z') { // A~Z ���� �̸�
				char a = input_string[i] + ('a' - 'A'); // �빮�ڸ� �ҹ��ڷ� ����
				if (pop(&s) != a) return 0;  // ���ÿ��� �������� �Է¹��� ���ڰ� �ٸ��� ����
			}
			i++; // ���� ���� ���� ����
		}
		else j++; // ���ĺ��� �ƴѰ��� ī��Ʈ
	}
	if (!is_empty) printf("�˻簡 ����� �̷������ �ʾҽ��ϴ�"); // ���� ���°� �ƴϸ�  ����
	return 1; 
}
int main() {
	char input_string[MAX] = { NULL };
	char word[100];

		printf("���ڿ��� �Է��Ͻÿ�>>");
		gets_s(input_string, sizeof(input_string));
		if (check_matching(input_string) == 1) printf("ȸ���Դϴ�.\n");
		else printf("ȸ���� �ƴմϴ�.\n");
	int exit = 0;
	while (1) {
		printf("�ٽ� �Է��Ͻðڽ��ϱ�? (yes/no) : ");
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