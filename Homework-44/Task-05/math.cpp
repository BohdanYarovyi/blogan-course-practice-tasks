const double PI = 3.14;

static double radius_square(double radius);

double calculate_circle_area(double radius) {
	return PI * radius_square(radius);
}

double calculate_circle_length(double radius) {
	return 2 * PI * radius;
}

double pi() {
	return PI;
}

static double radius_square(double radius) {
	return radius * radius;
}
