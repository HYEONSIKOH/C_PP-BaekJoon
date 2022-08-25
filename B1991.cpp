// 백준 1991 [트리] 전위,중위,후위 순회
#include <iostream>
using namespace std;

class Tree {
	char data; // 값
	Tree* left, * right; // 왼쪽,오른쪽 트리 

public:
	Tree() { // 생성자
		data = ' ';
		left = NULL;
		right = NULL;
	}

	// 설정자
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
		
		// 데이터값은 그냥 넣으면 된다.
		if (data != '.') t[(int)(data - 'A')].setData(data);

		// 왼쪽 서브 트리의 값은 left의 노드 주소값
		if (left != '.') t[(int)(data - 'A')].setLeft(&t[(int)(left - 'A')]);
		else t[(int)(data - 'A')].setLeft(NULL);

		// 오른쪽 서브 트리의 값은 right의 노드 주소값
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