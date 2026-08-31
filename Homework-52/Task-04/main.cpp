#include <iostream>
#include <chrono>

/*
	Алгоритм сортування бульбашкою можна оптимізувати. Для цього вам треба добавити визначення того, чи за одне проходження по масиву (поки бульбашка випливає) відбуваються якісь перестановки. Якщо перестановок немає, то масив уже відсортований і перевіряти наступні елементи (бульбашки) немає сенсу. Реалізуйте це і порівняйте з простим алгоритмом бульбашки.
*/


namespace Utility
{

    template <typename T>
    void randomize_array(T* arr, int size, int bot_value = 0, int top_value = 100);

    template <typename T>
    void show_array_head(T* arr, int size);

    /*
    arr - an array to fill of random numbers
    size - the size of an array
    bot_value - the smallest possible random value inclusive
    top_value - the highest possible random value inclusive
    */
    template <typename T>
    void randomize_array(T* arr, int size, int bot_value, int top_value)
    {
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
    void show_array_head(T* arr, int size = 20)
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
    void simple_bubble_sort(T* arr, int size, bool is_ascending_order = true);

    template <typename T>
    void graded_bubble_sort(T* arr, int size, bool is_ascending_order = true);

    template <typename T>
    void simple_bubble_sort(T* arr, int size, bool is_ascending_order)
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
    void graded_bubble_sort(T* arr, int size, bool is_ascending_order)
    {
        for (int i = 0; i < size; i++)
        {
            bool was_swap = false;
            for (int e = 0; e < size - i - 1; e++)
            {
                if (arr[e] > arr[e + 1] == is_ascending_order)
                {
                    std::swap(arr[e], arr[e + 1]);
                    was_swap = true;
                }
            }

            if (!was_swap) return;
        }
    }

} // namespace Sort

int main()
{
    const int ARRAY_SIZE = 100'000;

    int simple_bubble_array[ARRAY_SIZE];
    int graded_bubble_array[ARRAY_SIZE];
    long long simple_bubble_time;
    long long graded_bubble_time;

    std::srand(0);
    Utility::randomize_array(simple_bubble_array, ARRAY_SIZE);
    std::srand(0);
    Utility::randomize_array(graded_bubble_array, ARRAY_SIZE);

    Utility::show_array_head(simple_bubble_array);
    Utility::show_array_head(graded_bubble_array);

    // simple selection sorting
    { 
        auto start = std::chrono::high_resolution_clock::now();

        Sort::simple_bubble_sort(simple_bubble_array, ARRAY_SIZE);

        auto end = std::chrono::high_resolution_clock::now();
        simple_bubble_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    // graded bubble sorting
    { 
        auto start = std::chrono::high_resolution_clock::now();

        Sort::graded_bubble_sort(graded_bubble_array, ARRAY_SIZE);

        auto end = std::chrono::high_resolution_clock::now();
        graded_bubble_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    std::cout << "simple_bubble_sort was sorted with " << simple_bubble_time << " time.\n"; 
    std::cout << "graded_bubble_sort was sorted with " << graded_bubble_time << " time.\n"; 

    return 0;
}