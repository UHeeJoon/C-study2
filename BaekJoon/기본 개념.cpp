#include <iostream>
using namespace std;

//void t1(int t) {
//	int idx = 0;
//	int temp = t;
//	temp &= ~(1 << idx);
//	cout << "�������ٷ�? T1 : " << temp << "\n";
//}
//void t2(int t) {
//	int idx = 0;
//	int temp = t;
//	temp ^= (1 << idx);
//	cout << "XOR T2 : " << temp << "\n";
//}
//void t3(int t) {
//	int idx = (t & -t);
//	cout << "������ �����ִ� �ε��� T3: " << idx << "\n";
//}
//void t4(int t) {
//	int n = 4;
//	cout << "ũ�Ⱑ n�� ��� ������ ��� ��Ʈ �ѱ� T4 : " << (1 << n) - 1 << "\n";
//}
//void t5(int t) {
//	int idx = 1;
//	int temp = t;
//	temp |= (1 << idx);
//	cout << "idx��° ���ѱ� T5 : " << temp << "\n";
//}
//
//void t6(int t) {
//	int idx = 0;
//	int temp = t;
//	string a = temp & (1 << idx) ? "yes" : "no";
//	cout << "idx��° ��Ʈ�� �ִ��� Ȯ���ϱ� T6 : " << a << "\n";
//}

int main() {
	int t = 5; // 101 
	//t1(t);
	//t2(t);
	//t3(t);
	//t4(t);
	//t5(t);
	//t6(t);
	//for (int i = 0; i < (1 << 4); i++)
	//	cout << i << " ";
	int num = 15;
	int num2 = 16;
	cout << ~num << " " << ~num2;
	cout << "\n";
	return 0;
}

