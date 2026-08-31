#include <iostream>
#include <ctime>
#include <chrono>

/*
	Давайте спробуємо дізнатися, яке сортування працює швидше на масивах з випадковими значеннями. Для цього ви можете скористатися наступним алгоритмом:

    #include <chrono>

    int main()
    {
        // Записати час початку алгоритму:
        auto start = std::chrono::high_resolution_clock::now();

        // Ось тут знаходиться ваш алгоритм сортування.

        // Записати час завершення алгоритму:
        auto end = std::chrono::high_resolution_clock::now();

        // Порахувати тривалість алгоритму:
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        // Вивести тривалість алгоритму на екран в мікросекундах:
        std::cout << "Time taken by code: " << duration.count() << " microseconds\n";

        return 0;
    }

    Напишіть 2 функції: SelectionSort і BubbleSort (SelectionSort візьміть з попередньої домашньої роботи, BubbleSort можете взяти з задачі 1), засуньте в ці функції алгоритм визначення часу, створіть 2 однакові масиви на 100 000 елементів (а може й на 1 000 000), заповніть їх випадковими значеннями. Перший відсортуйте алгоритмом сортування вибіркою, другий завдяки бульбашці. І дізнаєтеся, яке сортування швидше.
*/

namespace Utility
{

    template <typename T>
    void randomize_array(T* arr, int size, int bot_value = 0, int top_value = 100);

    template <typename T>
    void show_array(T* arr, int size);

    /*
        arr - an array to fill of random numbers
        size - the size of an array
        bot_value - the smallest possible random value inclusive
        top_value - the highest possible random value inclusive
    */
    template <typename T>
    void randomize_array(T* arr, int size, int bot_value, int top_value)
    {
        #ifndef RAND_SEED_SET 

        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        #endif // !RAND_SEED_SET

        for (int i = 0; i < size; i++)
        {
            T r_value = std::rand() % (top_value - bot_value + 1) + bot_value;
            arr[i] = r_value;
        }
    }

    /*
        arr - an array to show
        size - the size of an array
    */
    template <typename T>
    void show_array(T* arr, int size)
    {
        std::cout << '[';
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i];

            if (i < size - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
    }

} // namespace Utility

namespace Sort
{

    template <typename T>
    void bubble_sort(T* arr, int size, bool is_ascending_order = true);

    template <typename T>
    void selection_sort(T* arr, int size, bool is_ascending_order = true);

    template <typename T>
    void bubble_sort(T* arr, int size, bool is_ascending_order)
    {
        for (int i = 0; i < size; i++)
        {
            for (int e = 0; e < size - i - 1; e++)
            {
                if (arr[e] > arr[e + 1] == is_ascending_order)
                {
                    std::swap(arr[e], arr[e + 1]);
                }
            }
        }
    }

    template <typename T>
    void selection_sort(T* arr, int size, bool is_ascending_order)
    {
        for (int lead = 0; lead < size - 1; lead++)
        {
            for (int i = lead + 1; i < size; i++)
            {
                if (arr[i] < arr[lead] == is_ascending_order)
                {
                    std::swap(arr[lead], arr[i]);
                }   
            }
        }
    }


} // namespace Sort

int main()
{
    const int ARRAY_SIZE = 10'000;
    
    int selection_array[ARRAY_SIZE];
    int bubble_array[ARRAY_SIZE];
    long long selection_time;
    long long bubble_time;
    
    Utility::randomize_array(selection_array, ARRAY_SIZE);
    Utility::randomize_array(bubble_array, ARRAY_SIZE);
    
    // selection sorting
    { 
        auto start = std::chrono::high_resolution_clock::now();

        Sort::selection_sort(selection_array, ARRAY_SIZE);

        auto end = std::chrono::high_resolution_clock::now();
        selection_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    // bubble sorting
    { 
        auto start = std::chrono::high_resolution_clock::now();

        Sort::bubble_sort(bubble_array, ARRAY_SIZE);

        auto end = std::chrono::high_resolution_clock::now();
        bubble_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    std::cout << "Selection_sort was sorted with " << selection_time << " time.\n"; 
    std::cout << "Bubble_sort was sorted with " << bubble_time << " time.\n"; 

	return 0;
}