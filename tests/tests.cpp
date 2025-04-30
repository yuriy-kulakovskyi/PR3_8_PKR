#include <gtest/gtest.h>
#include "../functions/functions.h"

// Test case for adding a book
TEST(LibraryTest, AddBook) {
    Book* library = nullptr;
    addBook(library, "Test Book", "Test Author", 2023);

    ASSERT_NE(library, nullptr);
    EXPECT_EQ(library->title, "Test Book");
    EXPECT_EQ(library->author, "Test Author");
    EXPECT_EQ(library->year, 2023);
    EXPECT_EQ(library->next, nullptr);
    EXPECT_EQ(library->prev, nullptr);

    clearBooks(library);
}