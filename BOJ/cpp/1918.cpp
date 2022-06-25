#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

int main() {
	char W[101]; scanf("%s", W);
	stack<char> stack;

	int len = strlen(W);
	for (int i = 0; i < len; i++) {
		if (W[i] >= 'A' && W[i] <= 'Z') {
			printf("%c", W[i]);
		}
		else {
			if (stack.empty()) stack.push(W[i]);
			else if (W[i] == '(') stack.push(W[i]);
			else if (W[i] == ')') {
				while (stack.top() != '(') {
					printf("%c", stack.top());
					stack.pop();
				}
				stack.pop();
			}
			else if (W[i] == '*' || W[i] == '/') {
				while (!stack.empty() && (stack.top() == '/' || stack.top() == '*')) {
					printf("%c", stack.top());
					stack.pop();
				}
				stack.push(W[i]);
			}
			else if (W[i] == '+' || W[i] == '-') {
				while (!stack.empty() && stack.top() != '(') {
					printf("%c", stack.top());
					stack.pop();
				}
				stack.push(W[i]);
			}
		}
	}

	while (!stack.empty()) {
		printf("%c", stack.top());
		stack.pop();
	}
}

