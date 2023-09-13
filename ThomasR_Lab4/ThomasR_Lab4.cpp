#include <iostream>
int calculateArithmeticSum(int difference, int start, int numElements) {
	int lastTerm = start + (numElements - 1) * difference;
	int sum = (start + lastTerm) * numElements / 2;
	return sum;
}

// Print out the menu of choices for the user to select from
void printMenu() {
	std::cout << "Please select which operation to perform:" << std::endl;
	std::cout << "\t1. Factorial" << std::endl;
	std::cout << "\t2. Arithmetic Series" << std::endl;
	std::cout << "\t3. Geometric Series" << std::endl;
	std::cout << "\t4. Exit" << std::endl;
	std::cout << "Your Selection: ";
}

int factorial(int number) {

	if (number < 0) {
		std::cout << "Factorial not for negative numbers, Enter a POSITIVE number." << std::endl;
		return 0;
	}
	else {
		int result = 1;

		std::cout << "Factorial equation for " << number << " is:" << std::endl;
		std::cout << number << "! = ";

		for (int i = 1; i <= number; i++) {
			result *= i;
			std::cout << i;
			if (i != number) {
				std::cout << " * ";
			}
		}
		std::cout << " = " << result << std::endl;
		return result;
	}
}

void arithmetic() {
	// TODO: Implement arithmetic series code here
}
void arithmetic(int difference, int start, int numElements) {
	int current = start;

	for (int i = 0; i < numElements; i++) {
		std::cout << current;
		if (i != numElements - 1) {
			std::cout << " + ";
		}
		current += difference;
	}

	std::cout << std::endl;
	int sum = calculateArithmeticSum(difference, start, numElements);
	std::cout << "Sum of the arithmetic series: " << sum << std::endl;

}

//void geometric() {
	double geometric(double a, double r, int n) {
		if (n <= 0) {
			return -1; // Indicate an error or handle it as needed
		}

		double result = a;
		std::cout << "Operations: " << a;

		for (int i = 1; i < n; i++) {
			a *= r;
			result += a;
			std::cout << " + " << a;
		}

		std::cout << std::endl;
		return result;
	}


	int main() {
		int choice;
		char again;
		int difference;
		int	start;
		int numElements;
		int n;
		double a, r;

		do {
			printMenu();
			std::cin >> choice;

			// Quit if user chooses to exit (or any invalid choice)
			if (choice > 3 || choice < 1) {
				return 0;
			}
			else if (choice == 1) {
				int number;
				std::cout << "Factorial: " << std::endl;
				std::cout << "Enter a number: ";
				std::cin >> number;
				factorial(number);

			}
			else if (choice == 2) {
				std::cout << "Arithmetic Series: " << std::endl;

				std::cout << "Enter a number to add each time: ";
				std::cin >> difference;

				std::cout << "Enter a number to start at: ";
				std::cin >> start;

				std::cout << "Enter the number of elements in the series: ";
				std::cin >> numElements;

				if (numElements <= 0) {
					std::cout << "Number of elements must be positive." << std::endl;
					return 0;
				}
				arithmetic(difference, start, numElements);
			}
			else if (choice == 3) {
				std::cout << "Enter the starting number: ";
				std::cin >> a;

				std::cout << "Enter a number to multiply by each time: ";
				std::cin >> r;

				std::cout << "Enter the number of elements in the series: ";
				std::cin >> n;

				double result = geometric(a, r, n);
				if (result != -1) {
					std::cout << "Result: " << result << std::endl;
				}
				else {
					std::cout << "Number of elements must be positive." << std::endl;
				}



			}

				std::cout << "Go Again? [Y/N] ";
				std::cin >> again;
			} while (again == 'y' || again == 'Y');

			return 0;
		}
	