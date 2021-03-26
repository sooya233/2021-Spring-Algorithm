#include <iostream>
using namespace std;

class Stack2
{
public:
	//Stack2가 실행될때 발생하는 생성자. 노드인 head와 z를 각각 NULL로 지정시켜 놓는다.
	Stack2() {
		head = NULL;
		z = NULL;
	};
	//Stack2가 소멸될 때 실행되는 소멸자, node인 head와 z를 샂게한다.
	~Stack2() {
		delete head;
		delete z;
	};
	//stack에 값을 넣는 push함수
	void push(float v){
		node* newNode = new node;
		newNode->key = v;
		newNode->next = NULL;
		if (head == NULL) {
			head = newNode;
			z = head;
		}
		else {
			z->next = newNode;
			z = newNode;
		}
	};
	//stack에서 값을 추출하는 pop메소드
	float pop() {
		float t = z->key;
		node* temp = head;
		if (empty() == 1) {
			cout << "Stack is empty!" << "\n";
			return -1;
		}
		else {
			if (z == head) {
				head = NULL;
				z = NULL;
				return t;
			}
			else {
				while (temp->next != z) {
					temp = temp->next;
				}
				temp->next = NULL;
				z = temp;
				return t;
			}
		}
	};
	//stack이 비어있는지 아닌지 확인하는 empty 메소드
	int empty() {
		if (head == NULL) {
			return 1;
		}
		else {
			return 0;
		}
	};

private:
	struct node
	{
		float key;
		struct node *next;
	};
	struct node *head, *z;
};

int main() {
	char c;
	Stack2 st;
	float x;

	/*
	2번문제와 비슷하지만, '-' 와 '/'같은 경우에는 후에 나온 값에서 앞에 나온 값을 연산을 해 주어야 되기 때문에 temp라는
	임시 변수를 만들어서 전의 stack에서 pop한 값을 저장시켜 놓은 후 연산한 뒤에 다시 stack 에 push한다.
	*/
	while ((c = cin.get()) != '\n') {
		x = 0;
		while (c == ' ') {
			cin.get(c);
		}
		if (c == '+') x = st.pop() + st.pop();
		if (c == '-') {
			float temp = st.pop();
			x = st.pop() - temp;
		};
		if (c == '*') x = st.pop() * st.pop();
		if (c == '/') {
			float temp = st.pop();
			x = st.pop() / temp;
		};
		while (c >= '0' && c <= '9')
		{
			x = 10 * x + (c - '0');
			cin.get(c);
		}
		st.push(x);
	}

	//소수점이라면 소수점 두자리까지 출력하도록 하고, 아니라면 그대로 출력해주는 코드
	float temp = st.pop();
	if (temp * 10 != float((int)temp * 10)) {
		printf("%.2f", temp);
		cout << "\n";
	}
	else {
		cout << temp << "\n";
	}
	
	return 0;

}
