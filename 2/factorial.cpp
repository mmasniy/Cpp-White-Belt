
int Factorial(int number) {
	if (number < 2)
		return 1;
	return number * Factorial(number - 1);
}
