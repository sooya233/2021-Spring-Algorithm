#include <iostream>
void visit(struct treeNode *t);
void traverse(struct treeNode *t);

struct treeNode { char info; struct treeNode *l, *r; };
struct treeNode *x, *z;
using namespace std;


class Stack
{
public:
	Stack(int max = 100) { stack = new treeNode[max]; p = 0; };
	~Stack() { delete stack; };
	inline void push(treeNode *v) {
		stack[p].info = v->info;
		stack[p].l = v->l;
		stack[p].r = v->r;
		p++;

	};
	inline treeNode* pop() {
		if (empty()) {
			cout << "Stack is empty!" << "\n";
			exit(0);
		}
		else {
			treeNode *temp = new treeNode;
			p--;
			*temp = stack[p];
			return temp;
		}
	};
	inline int empty() {
		if (p == 0) {
			return 1;
		}
		else {
			return 0;
		}
	};
private:
	treeNode *stack;
	int p;
};

class Queue {
public:
	Queue(int max = 100) { queue = new treeNode*[max];  head = 0; tail = 0; size = max; };
	~Queue() { delete queue; };
	void put(treeNode* v);
	treeNode* get();
	int empty();
	int getSize() {
		return tail - head;
	};

private:
	treeNode **queue;
	int head;
	int tail;
	int size;
};

void Queue::put(treeNode* v)
{
	queue[tail++] = v;
	if (tail > size) tail = 0;
}
treeNode* Queue::get()
{
	treeNode* t = queue[head++];
	if (head > size) head = 0;
	return t;
}
int Queue::empty() { return head == tail; }

int traverse(struct treeNode *t, char c2)
{
	bool found = false;
	int level = 0;
	
	Queue queue(50);
	
	queue.put(t);
	while (!queue.empty())
	{
		int size = queue.getSize();
		level++;
		for (int i = 0; i < size; i++) {
			t = queue.get();
			if (t->info == c2) {
				found = true;
				return level;
			}
			if (t->l != z) queue.put(t->l);
			if (t->r != z) queue.put(t->r);
		}
		
	}
	if (!found) {
		return -1;
	}
}

int main()
{
	char c; char c2;  Stack stack(50); int level;
	z = new treeNode; z->l = z; z->r = z;
	while ((c = cin.get()) != '\n')
	{
		while (c == ' ') cin.get(c);
		x = new treeNode;
		x->info = c; x->l = z; x->r = z;
		if (c == '+' || c == '*' || c == '-') { x->r = stack.pop(); x->l = stack.pop(); }
		stack.push(x);
	}
	c2 = cin.get();
	level = traverse(stack.pop(),c2);
	if (level == -1)	cout << "Not Found" << endl;
	else
	{
		cout << level << endl;
	}
	return 0;
}

