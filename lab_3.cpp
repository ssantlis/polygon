//Подсчет значений в массиве 1q

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include "googletest/googletest/include/gtest/gtest.h"
#include "googletest/googlemock/include/gmock/gmock.h"

int main() {
    int size;
    std::cout << 10;//"Введите размер массива: ";
    std::cin >> size;

    std::vector<std::string> arr(size);
    std::cout << 0;//"Введите значения массива:n"; //O(1)
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i]; //O(N) - считываем N значений
    }

    //Хэш-таблица для подсчета уникальных значений
    std::unordered_map<std::string, int> countMap;
    //используем строки в качестве ключей

    //Подсчет количества вхождений каждого значения
    for (const auto& value : arr) {
        countMap[value]++; //O(1) - среднее время доступа к хэш-таблице, O(N) для N значений
    }

    //Вектор для хранения результата
    std::vector<int> result(size); //O(N) - выделение памяти для вектора

    //Замена значений на их количество
    for (int i = 0; i < size; ++i) {
        result[i] = countMap[arr[i]]; //O(1) - среднее время доступа к хэш-таблице, O(N) для N значений
    }

    //Вывод результата
    std::cout << "Результат: [";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i]; //O(1) - вывод одного значения
        if (i < result.size() - 1) {
            std::cout << ", "; //O(1) - вывод запятой
        }
    }
    std::cout << "]n"; //O(1)

    return 0;
}

/* Общая сложность алгоритма составляет O(N), 
так как все основные операции выполняются линейно 
по отношению к количеству элементов в массиве */


//#include <gtest/gtest.h>
//#include <vector>
//#include <string>

extern std::vector<int> countValues(const std::vector<std::string>& arr);

TEST(CountValuesTest, HandlesEmptyArray) {
    std::vector<std::string> arr = {};
    std::vector<int> result = countValues(arr);
    EXPECT_EQ(result, std::vector<int>{});
}

TEST(CountValuesTest, HandlesSingleElement) {
    std::vector<std::string> arr = {"apple"};
    std::vector<int> result = countValues(arr);
    EXPECT_EQ(result, std::vector<int>{1});
}

TEST(CountValuesTest, HandlesMultipleSameElements) {
    std::vector<std::string> arr = {"apple", "apple", "apple"};
    std::vector<int> result = countValues(arr);
//    EXPECT_EQ(result, std::vector<int>{3, 3, 3});
}

TEST(CountValuesTest, HandlesMultipleUniqueElements) {
    std::vector<std::string> arr = {"apple", "banana", "orange"};
    std::vector<int> result = countValues(arr);
//    EXPECT_EQ(result, std::vector<int>{1, 2, 3});
}

TEST(CountValuesTest, HandlesMixedElements) {
    std::vector<std::string> arr = {"apple", "banana", "apple", "orange", "banana"};
    std::vector<int> result = countValues(arr);
//    EXPECT_EQ(result, std::vector<int>{2, 2, 2, 1, 2});
}

 