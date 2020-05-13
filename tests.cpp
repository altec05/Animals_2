#include <gtest/gtest.h>
#include "cont.h"
#include "fish.h"
#include "bird.h"
#include "common_animal.h"

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

// Тест открытия файла input
TEST(LAB1_test, test_fileInpName) {
    std::ifstream ifstr("input.txt");
    EXPECT_TRUE(ifstr.is_open());
}

// Тест открытия файла output
TEST(LAB1_test, test_fileOutName) {
    std::ofstream ofstr("output.txt");
    EXPECT_TRUE(ofstr.is_open());
}

// Тест инициализации контейнера
TEST(LAB1_test, test_Init) {
    std::ifstream ifstr("input.txt");
    cont Zoo{};
    EXPECT_EQ(Zoo.first, nullptr);
    EXPECT_EQ(Zoo.size, 0);
}

// Тест добавления элемента в контейнер
TEST(LAB1_test, test_fileName) {
    std::ifstream ifstr("input.txt");
    cont Zoo{};
    // Создаем элемент
    node *A = new node;
    A->data = reinterpret_cast<animal *>(new common_animal);
    A->data->TYPE = enum_animal::COMMON_ANIMAL;
    A->data->name = "Test name";
    A->data->age = 3;
    ((common_animal*)A)->food = type::insectivorous;
    Zoo.Add(A);
    // Проверяем корректность
    EXPECT_EQ(Zoo.size, 1);
    EXPECT_EQ(A->data->age, 3);
    EXPECT_EQ(A->data->name, "Test name");
    EXPECT_EQ(A->data->TYPE, enum_animal::COMMON_ANIMAL);
    EXPECT_EQ(((common_animal*)A)->food, type::insectivorous);
}

// Тест чтения контейнера
TEST(LAB1_test, test_Read) {
    std::ifstream ifstr("input.txt");
    cont Zoo{};
    // Если не будет вызвано исключений, тест пройден
    EXPECT_NO_THROW(Zoo.Read(ifstr));

}

// Тест записи контейнера
TEST(LAB1_test, test_Write) {
    std::ifstream ifstr("input.txt");
    std::ofstream ofstr("output.txt");
    cont Zoo{};
    // Если не будет вызвано исключений, тест пройден
    Zoo.Read(ifstr);
    EXPECT_NO_THROW(Zoo.Out(ofstr));
}