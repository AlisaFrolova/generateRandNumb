#include <iostream>
#include <ctime>
#include <cstdlib>

const std::string errorMessage = "Incorrect enter. Try again";

int generateRandNumb();
int inputNumber(std::string error_message);
bool isNumberNumeric();

int main() {
	std::cout << "Generated Number: " << generateRandNumb() << std::endl;

	std::cout << "Press any key to finish...";
	std::cin.get();

	return 0;
}

int generateRandNumb() {
	srand(time(NULL));

	int leftBorder, rightBorder;

	std::cout << "Enter min value" << std::endl;
	leftBorder = inputNumber(errorMessage);

	std::cout << "Enter max value" << std::endl;
	rightBorder = inputNumber(errorMessage);

	return rand() % (rightBorder - leftBorder + 1) + leftBorder;
}

bool isNumberNumeric()
{
	if (std::cin.get() == '\n')
		return true;
	else
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
}

int inputNumber(std::string error_message)
{
	int number;

	while (true)
	{
		std::cin >> number;
		if (isNumberNumeric())
			return number;
		else
			std::cout << error_message << std::endl;
	}
}