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
int main()
{
	char c; Stack stack(50);
	z = new treeNode; z->l = z; z->r = z;
	while ((c = cin.get()) != '\n')
	{
		while (c == ' ') cin.get(c);
		x = new treeNode;
		x->info = c; x->l = z; x->r = z;
		if (c == '+' || c == '*' || c == '-') { x->r = stack.pop(); x->l = stack.pop(); }
		stack.push(x);
	}
	traverse(stack.pop());
	cout << endl;
	return 0;
}
void visit(struct treeNode *t)
{
	cout << t->info << " ";
}
void traverse(struct treeNode *t)
{
	if (t != z)
	{
		traverse(t->l);
		visit(t);
		traverse(t->r);
	}
}
