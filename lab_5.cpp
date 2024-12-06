// Сортировка вставками (1)
#include <iostream> 
#include <vector> 
 
void insertionSort(std::vector<int>& arr) { 
    int n = arr.size(); 
    for (int i = 1; i < n; ++i) { 
        int key = arr[i]; // Сохраняем текущий элемент 
        int j = i - 1; 
 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            --j; 
        } 
        arr[j + 1] = key; 
    } 
} 
 
int main() { 
    std::vector<int> arr = {12, 11, 13, 5, 6}; 
 
    std::cout << "Original array:\n"; 
    for (int num : arr) { 
        std::cout << num << " "; 
    } 
    std::cout << "\n"; 
 
    insertionSort(arr); 
 
    std::cout << "Sorted array:\n"; 
    for (int num : arr) { 
        std::cout << num << " "; 
    } 
    std::cout << "\n"; 
 
    return 0; 
}



// Быстрая сортировка (2)
#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Опорный элемент
    int i = low - 1;       // Индекс для меньших элементов

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]); // Меняем местами текущий элемент с элементом на позиции i
        }
    }
    std::swap(arr[i + 1], arr[high]); // Ставим опорный элемент на правильное место
    return i + 1;                     // Возвращаем индекс опорного элемента
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // Разделение массива
        quickSort(arr, low, pivotIndex - 1);        // Сортируем левую часть
        quickSort(arr, pivotIndex + 1, high);       // Сортируем правую часть
    }
}

int main() {
    std::vector<int> arr = { 10, 7, 8, 9, 1, 5 };

    std::cout << "Original array:\n";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array:\n";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}



// Поразрядная сортировка (Radix sort) (3)
#include <iostream> 
#include <vector> 
#include <algorithm> 
 
// Функция для получения цифры разряда 
int getDigit(int number, int place) { 
    return (number / place) % 10; 
} 
 
// Стабильная сортировка для текущего разряда 
void countingSort(std::vector<int>& arr, int place) { 
    const int base = 10; // Основание системы счисления 
    int n = arr.size(); 
    std::vector<int> output(n); // Временный массив для результата 
    int count[base] = {0};      // Массив для подсчета частот 
 
    // Подсчитываем частоты 
    for (int num : arr) 
        count[getDigit(num, place)]++; 
 
    // Преобразуем массив count в позиции 
    for (int i = 1; i < base; i++) 
        count[i] += count[i - 1]; 
 
    // Сортируем по текущему разряду 
    for (int i = n - 1; i >= 0; i--) { 
        int digit = getDigit(arr[i], place); 
        output[count[digit] - 1] = arr[i]; 
        count[digit]--; 
    } 
 
    // Копируем результат обратно в оригинальный массив 
    for (int i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
 
// Основная функция поразрядной сортировки 
void radixSort(std::vector<int>& arr) { 
    // Находим максимальный элемент, чтобы узнать количество разрядов 
    int maxNum = *std::max_element(arr.begin(), arr.end()); 
 
    // Сортируем по каждому разряду 
    for (int place = 1; maxNum / place > 0; place *= 10) 
        countingSort(arr, place); 
} 
 
int main() { 
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66}; 
 
    std::cout << "Исходный массив:\n"; 
    for (int num : arr) 
        std::cout << num << " "; 
    std::cout << "\n"; 
 
    radixSort(arr); 
 
    std::cout << "Отсортированный массив:\n"; 
    for (int num : arr) 
        std::cout << num << " "; 
    std::cout << "\n"; 
 
    return 0; 
}