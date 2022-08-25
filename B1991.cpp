// ���� 1991 [Ʈ��] ����,����,���� ��ȸ
#include <iostream>
using namespace std;

class Tree {
	char data; // ��
	Tree* left, * right; // ����,������ Ʈ�� 

public:
	Tree() { // ������
		data = ' ';
		left = NULL;
		right = NULL;
	}

	// ������
	void setData(char data) {
		this->data = data;
	}

	void setLeft(Tree* left) {
		this->left = left;
	}

	void setRight(Tree* right) {
		this->right = right;
	}

	void static preorder(Tree* r) {
		if (r) {
			cout << r->data;
			preorder(r->left);
			preorder(r->right);
		}
	}
	
	void static inorder(Tree* r) {
		if (r) {
			inorder(r->left);
			cout << r->data;
			inorder(r->right);
		}
	}
	
	void static postorder(Tree* r) {
		if (r) {
			postorder(r->left);
			postorder(r->right);
			cout << r->data;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num;
	cin >> num;
	Tree* t = new Tree[num + 1];
	
	char data, left, right;

	for (int i = 0; i < num; i++) {
		cin >> data >> left >> right;
		
		// �����Ͱ��� �׳� ������ �ȴ�.
		if (data != '.') t[(int)(data - 'A')].setData(data);

		// ���� ���� Ʈ���� ���� left�� ��� �ּҰ�
		if (left != '.') t[(int)(data - 'A')].setLeft(&t[(int)(left - 'A')]);
		else t[(int)(data - 'A')].setLeft(NULL);

		// ������ ���� Ʈ���� ���� right�� ��� �ּҰ�
		if (right != '.') t[(int)(data - 'A')].setRight(&t[(int)(right - 'A')]);
		else t[(int)(data - 'A')].setRight(NULL);
	}

	Tree::preorder(&t[0]);
	cout << '\n';
	Tree::inorder(&t[0]);
	cout << '\n';
	Tree::postorder(&t[0]);

	return 0;
}