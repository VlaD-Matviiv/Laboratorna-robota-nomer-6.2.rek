// lab 6.2.rek

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// ������� ��� ��������� ������
void generateArray(std::vector<int>& array, int min_value, int max_value, int index) {
    if (index < array.size()) {
        array[index] = std::rand() % (max_value - min_value + 1) + min_value;
        generateArray(array, min_value, max_value, index + 1);
    }
}

// ������� ��� ��������� ������
void printArray(const std::vector<int>& array, int index) {
    if (index < array.size()) {
        std::cout << std::setw(3) << array[index];  // ������������ ���������
        printArray(array, index + 1);
    }
    else {
        std::cout << std::endl;
    }
}

// ������� ��� ������� ������
void processArray(std::vector<int>& array, int& count, int& total_sum, int index) {
    if (index < array.size()) {
        if (array[index] % 2 == 0 && array[index] <= 0) {  // �������: ����, ��� �������
            count++;
            total_sum += array[index];
            array[index] = 0;  // �������� �� 0
        }
        processArray(array, count, total_sum, index + 1);
    }
}

// ������� �������
int main() {
    const int size = 24;
    const int min_value = -15;
    const int max_value = 75;
    std::vector<int> array(size);

    // ����������� ���������� ���������� �����
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // ��������� ������
    generateArray(array, min_value, max_value, 0);

    // ��������� ������������ ������
    std::cout << "����������� �����:\n";
    printArray(array, 0);

    // ���� ��� ���������
    int count = 0;
    int total_sum = 0;

    // ������� ������
    processArray(array, count, total_sum, 0);

    // ��������� ����������
    std::cout << "\nʳ������ ��������, �� ������������� �������: " << count << std::endl;
    std::cout << "���� ��������, �� ������������� �������: " << total_sum << std::endl;

    // ��������� �������������� ������
    std::cout << "\n������������� �����:\n";
    printArray(array, 0);

    return 0;
}
