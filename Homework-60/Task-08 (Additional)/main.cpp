#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

/*
Задача: Матриця з видаленням рядків/стовпців

У тебе є двовимірний динамічний масив int** (рядки виділені окремо, як у попередній задачі з initialize/show). 
Реалізуй:
	1. int** create_matrix(int rows, int columns); --- виділяє int** на купі (масив вказівників на int-рядки)
	2. void initialize_random(int** matrix, int rows, int columns); --- заповнює випадковими числами
	3. void show_matrix(const int* const* matrix, int rows, int columns); --- виводить матрицю
	4. int** remove_row(int** matrix, int rows, int columns, int row_index); --- створює НОВУ матрицю без вказаного рядка (rows-1), звільняє стару, повертає нову
	5. int** remove_column(int** matrix, int rows, int columns, int col_index); --- створює НОВУ матрицю без вказаного стовпця (columns-1) для кожного рядка, звільняє стару, повертає нову
	6. int find_max(const int* const* matrix, int rows, int columns); --- знаходить максимальне значення в усій матриці
	7. void delete_matrix(int** matrix, int rows); --- звільняє кожен рядок і сам масив вказівників

Меню:
  [1] Показати матрицю
  [2] Видалити рядок за індексом
  [3] Видалити стовпець за індексом
  [4] Знайти максимум
  [0] Вийти
*/

void print_menu();

int get_user_option();

bool does_user_option_exist(int option);

int** create_matrix(int rows, int columns);

void initialize_random(int** matrix, int rows, int columns, int min = -1000, int max = 1000);

void show_matrix(const int* const* matrix, int rows, int columns);

int** remove_row(int** matrix, int rows, int columns, int row_index);

int** remove_column(int** matrix, int rows, int columns, int column_index);

int find_max(const int* const* matrix, int rows, int columns);

void delete_matrix(int** matrix, int rows);

int main()
{
	int** matrix ;
	int matrix_rows; 
	int matrix_columns;

	std::cout << "Create matrix (rows, columns): ";
	std::cin >> matrix_rows >> matrix_columns;
	matrix = create_matrix(matrix_rows, matrix_columns);
	initialize_random(matrix, matrix_rows, matrix_columns);

	while (true)
	{
		print_menu();
		int user_option = get_user_option();

		if (!does_user_option_exist(user_option))
		{
			std::cout << "Option doesn't exist. Choose please one in the menu." << std::endl;
			continue;
		}

		switch (user_option)
		{
			case 1: 
			{
				show_matrix(matrix, matrix_rows, matrix_columns);
			}
			break;
			case 2:
			{
				std::cout << "Row index: ";
				int index;
				std::cin >> index;

				if (matrix_rows < 2)
				{
					std::cout << "Impossible delete last row.\n";
					break;
				}

				if (index > matrix_rows - 1 || index < 0)
				{
					std::cout << "Row with index " << index << " not found\n";
					break;
				}

				matrix = remove_row(matrix, matrix_rows, matrix_columns, index);
				matrix_rows--;
			}
			break;
			case 3:
			{
				std::cout << "Column index: ";
				int index;
				std::cin >> index;

				if (matrix_columns < 2)
				{
					std::cout << "Impossible delete last column.\n";
					break;
				}

				if (index > matrix_columns - 1 || index < 0)
				{
					std::cout << "Column with index " << index << " not found\n";
					break;
				}

				matrix = remove_column(matrix, matrix_rows, matrix_columns, index);
				matrix_columns--;
			} 
			break;
			case 4:
			{
				int max = find_max(matrix, matrix_rows, matrix_columns);
				std::cout << "Matrix max: " << max << std::endl;
			}
			break;
			case 0:
			{
				return 0;
			}
			break;
			default:
			{
				std::cout << "Not Found Option " << user_option << std::endl;
			}
		}
		std::cout << std::endl;
	}

	return 0;
}

void print_menu()
{
	std::cout << "- MENU -" << std::endl;
	std::cout << "  [1] Show matrix"						<< std::endl;
	std::cout << "  [2] Remove matrix row with index"		<< std::endl;
	std::cout << "  [3] Remove matrix column with index"	<< std::endl;
	std::cout << "  [4] Find max element"					<< std::endl;
	std::cout << "  [0] Exit"								<< std::endl;
}

int get_user_option()
{
	std::cout << "Chose menu item: ";
	int option;
	std::cin >> option;

	return option;
}

bool does_user_option_exist(int option)
{
	if (option == 1) return true;
	if (option == 2) return true;
	if (option == 3) return true;
	if (option == 4) return true;
	if (option == 0) return true;

	return false;
}

int** create_matrix(int rows, int columns)
{
	int** matrix = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		*(matrix + i) = new int[columns] {0};
	}

	return matrix;
}

void initialize_random(int** matrix, int rows, int columns, int min, int max)
{
	static bool has_random_seed_set = false;
	if (!has_random_seed_set)
	{
		has_random_seed_set = true;
		unsigned int timestamp = static_cast<unsigned int>(std::time(nullptr));
		std::srand(timestamp);
	}

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			matrix[r][c] = std::rand() % (max - min) + min;
		}
	}
}

int get_digit_width(int digit)
{
	for (int i = 0; true; i++)
	{
		if (std::abs(digit) / std::pow(10, i) < 10)
		{
			return i + 1;
		}
	}
}

int find_max_value_width(const int* column, int size)
{
	int widest = column[0];

	for (int i = 1; i < size; i++)
	{
		if (std::abs(widest) < std::abs(column[i]))
		{
			widest = column[i];
		}
	}

	return get_digit_width(widest);
}

int* get_map_of_columns_width(const int* const* elements, int rows, int columns)
{
	int* columns_width = new int[columns];

	for (int c = 0; c < columns; c++)
	{
		int* column = new int[rows];
		for (int r = 0; r < rows; r++)
		{
			column[r] = elements[r][c];
		}

		columns_width[c] = find_max_value_width(column, rows);
		delete[] column;
	}

	return columns_width;
}

void print_whitespaces(int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << ' ';
	}
}

void show_matrix(const int* const* matrix, int rows, int columns)
{
	int* column_width_map = get_map_of_columns_width(matrix, rows, columns);

	for (int r = 0; r < rows; r++)
	{
		std::cout << "|";
		for (int c = 0; c < columns; c++)
		{	
			int e = matrix[r][c];
			int suffix_width = column_width_map[c] - get_digit_width(e);
			if (e >= 0)
			{
				std::cout << ' ';
			}
			std::cout << e;
			print_whitespaces(suffix_width);
			if (c < columns - 1)
			{
				std::cout << ' ';
			}
		}

		std::cout << "|\n";
	}

	delete[] column_width_map;
}

int** remove_row(int** matrix, int rows, int columns, int row_index)
{
	int** new_matrix = create_matrix(rows - 1, columns);

	int index = 0;
	for (int r = 0; r < rows; r++) {
		if (r == row_index) continue;

		for (int c = 0; c < columns; c++)
		{
			new_matrix[index][c] = matrix[r][c];
		}

		index++;
	}
	delete_matrix(matrix, rows);

	return new_matrix;
}

int** remove_column(int** matrix, int rows, int columns, int column_index)
{
	int** new_matrix = create_matrix(rows, columns - 1);
	
	for (int r = 0; r < rows; r++) 
	{
		int index = 0;
		for (int c = 0; c < columns; c++)
		{
			if (c == column_index) continue;

			new_matrix[r][index] = matrix[r][c];
			index++;
		}
	}

	delete_matrix(matrix, rows);

	return new_matrix;
}

int find_max(const int* const* matrix, int rows, int columns)
{
	int biggest = matrix[0][0];
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++) 
		{
			if (matrix[r][c] > biggest)
			{
				biggest = matrix[r][c];
			}
		}
	}
	
	return biggest;
}

void delete_matrix(int** matrix, int rows)
{
	for (int r = 0; r < rows; r++)
	{
		delete[] matrix[r];
	}
	delete[] matrix;
}