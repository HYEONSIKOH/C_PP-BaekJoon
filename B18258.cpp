// BaekJoon 18258 ť2

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;

	int* arr = new int[num];

	string command;
	int number;
	int rear = -1, front = -1;
	int count;

	for (int i = 0; i < num; i++) {
		cin >> command;
		count = rear - front;

		if (command == "push") {
			cin >> number;
			arr[++rear] = number;
		}

		else if (command == "pop") {
			if (front == rear) cout << -1 << "\n";
			else cout << arr[++front] << "\n";
		}

		else if (command == "size") cout << count << "\n";
		

		else if (command == "empty") {
			if (count == 0) cout << 1 << "\n";
			else cout << 0 << "\n";
		}

		else if (command == "front") {
			if (front == rear) cout << -1 << "\n";
			else cout << arr[front+1] << "\n";
		}

		else if (command == "back") {
			if (front == rear) cout << -1 << "\n";
			else cout << arr[rear] << "\n";
		}
	}

	delete[] arr;
	return 0;
}