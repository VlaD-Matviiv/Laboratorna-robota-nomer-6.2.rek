// lab 6.2.rek

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// Функція для генерації масиву
void generateArray(std::vector<int>& array, int min_value, int max_value, int index) {
    if (index < array.size()) {
        array[index] = std::rand() % (max_value - min_value + 1) + min_value;
        generateArray(array, min_value, max_value, index + 1);
    }
}

// Функція для виведення масиву
void printArray(const std::vector<int>& array, int index) {
    if (index < array.size()) {
        std::cout << std::setw(3) << array[index];  // Форматування виведення
        printArray(array, index + 1);
    }
    else {
        std::cout << std::endl;
    }
}

// Функція для обробки масиву
void processArray(std::vector<int>& array, int& count, int& total_sum, int index) {
    if (index < array.size()) {
        if (array[index] % 2 == 0 && array[index] <= 0) {  // Критерій: парні, крім додатніх
            count++;
            total_sum += array[index];
            array[index] = 0;  // Замінюємо на 0
        }
        processArray(array, count, total_sum, index + 1);
    }
}

// Головна функція
int main() {
    const int size = 24;
    const int min_value = -15;
    const int max_value = 75;
    std::vector<int> array(size);

    // Ініціалізація генератора випадкових чисел
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Генерація масиву
    generateArray(array, min_value, max_value, 0);

    // Виведення оригінального масиву
    std::cout << "Оригінальний масив:\n";
    printArray(array, 0);

    // Змінні для підрахунку
    int count = 0;
    int total_sum = 0;

    // Обробка масиву
    processArray(array, count, total_sum, 0);

    // Виведення результатів
    std::cout << "\nКількість елементів, що задовольняють критерію: " << count << std::endl;
    std::cout << "Сума елементів, що задовольняють критерію: " << total_sum << std::endl;

    // Виведення модифікованого масиву
    std::cout << "\nМодифікований масив:\n";
    printArray(array, 0);

    return 0;
}
