int calcDigits(int a) {
	int digits = 0;
	
	while(a > 0) {
		digits++;
		a = a / 10;
	}

	return digits;
}
