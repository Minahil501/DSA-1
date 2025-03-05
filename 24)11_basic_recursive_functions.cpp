#include <iostream>
#include <string>
using namespace std;
int fact(int n){
	if (n == 0){
		return 1;

	}
	if (n > 0){
		return n*fact(n - 1);
	}
}
int fib(int n){
	if (n == 0){
		return 0;
	}
	if (n == 1){
		return 1;

	}
	if (n > 1){
		return fib(n - 1) + fib(n - 2);
	}
}
void print(int n, int current = 0){
	if (current == n){ return; }
	cout << fib(current);
	print(n, current + 1);
}
int no_of_dig(int n){
	if (n == 0){
		return 0;
	}
	if (n > 1){
		return no_of_dig(n / 10) + 1;
	}
}
int sum_of_dig(int n){
	if (n == 0){
		return 0;
	}
	if (n > 1){
		return sum_of_dig(n / 10) + (n % 10);
	}
}
int rev_of_dig(int n, int rev = 0){
	if (n == 0){
		return rev;
	}
	if (n > 1){
		return rev_of_dig(n / 10, rev * 10 + n % 10);
	}
}
void dectobin(int n){
	if (n != 0){
		dectobin(n / 2);
		cout << n % 2;
	}
}
int prime(int n, int div = 2) {
	if (n <= 1) {
		cout << "not prime" << endl;
		return 0;
	}
	if (div * div > n) {
		cout << "prime" << endl;
		return 1;
	}
	if (n % div == 0) {
		cout << "Not prime" << endl;
		return 0;
	}
	return prime(n, div + 1);
}
void natural(int n) {
	if (n == 0){ return; }
	natural(n - 1);
	cout << n;
}
int naturalsum(int n) {
	if (n == 0){ return 0; }
	return n + naturalsum(n - 1);

}
bool isPalindrome(string s, int start, int end) {
	if (start >= end) { // Base case
		return true;
	}
	if (s[start] != s[end]) { // Not a palindrome
		return false;
	}
	return isPalindrome(s, start + 1, end - 1); // Recursive call
}
int power(int a, int b){
	if (b == 0){
		return 1;
	}
	return a*power(a, b - 1);
}
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	int choice, value, a, b;
	string str;

	do {
		cout << "1. FACTORIAL" << endl;
		cout << "2. FIBONACCI SERIES" << endl;
		cout << "3. SUM OF DIGITS" << endl;
		cout << "4. REVERSE DIGITS" << endl;
		cout << "5. DECIMAL TO BINARY" << endl;
		cout << "6. CHECK PRIME" << endl;
		cout << "7. SUM OF NATURAL NUMBERS" << endl;
		cout << "8. CHECK PALINDROME" << endl;
		cout << "9. POWER FUNCTION" << endl;
		cout << "10. GCD CALCULATION" << endl;
		cout << "11. EXIT" << endl;
		cout << "ENTER CHOICE: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "ENTER NUMBER: ";
			cin >> value;
			cout << "FACTORIAL: " << fact(value) << endl;
			break;
		case 2:
			cout << "ENTER TERMS: ";
			cin >> value;
			print(value);
			cout << endl;
			break;
		case 3:
			cout << "ENTER NUMBER: ";
			cin >> value;
			cout << "SUM OF DIGITS: " << sum_of_dig(value) << endl;
			break;
		case 4:
			cout << "ENTER NUMBER: ";
			cin >> value;
			cout << "REVERSED NUMBER: " << rev_of_dig(value) << endl;
			break;
		case 5:
			cout << "ENTER NUMBER: ";
			cin >> value;
			dectobin(value);
			cout << endl;
			break;
		case 6:
			cout << "ENTER NUMBER: ";
			cin >> value;
			prime(value);
			break;
		case 7:
			cout << "ENTER NUMBER: ";
			cin >> value;
			cout << "SUM: " << naturalsum(value) << endl;
			break;
		case 8:
			cout << "ENTER STRING: ";
			cin >> str;
			if (isPalindrome(str, 0, str.length() - 1)) {
				cout << "PALINDROME" << endl;
			}
			else {
				cout << "NOT A PALINDROME" << endl;
			}
			break;
		case 9:
			cout << "ENTER BASE AND EXPONENT: ";
			cin >> a >> b;
			cout << "RESULT: " << power(a, b) << endl;
			break;
		case 10:
			cout << "ENTER TWO NUMBERS: ";
			cin >> a >> b;
			cout << "GCD: " << gcd(a, b) << endl;
			break;
		case 11:
			cout << "EXITING..." << endl;
			break;
		default:
			cout << "INVALID CHOICE" << endl;
		}
	} while (choice != 11);

	return 0;
}

