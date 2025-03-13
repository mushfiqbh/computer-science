// // N
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a shelf
typedef struct
{
    int total_books;
    int *pages_per_book;
} Shelf;

// Function to create a new shelf
Shelf *create_shelf(int num_books)
{
    Shelf *shelf = (Shelf *)malloc(sizeof(Shelf));
    if (!shelf)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    shelf->total_books = num_books;
    shelf->pages_per_book = (int *)calloc(num_books, sizeof(int));
    if (!shelf->pages_per_book)
    {
        perror("Memory allocation failed");
        free(shelf);
        exit(EXIT_FAILURE);
    }

    return shelf;
}

// Function to add a new book to a specific shelf
void add_book(Shelf *shelf, int pages)
{
    int new_index = shelf->total_books; // New index for the book
    shelf->total_books++;               // Increment the total number of books
    shelf->pages_per_book = (int *)realloc(shelf->pages_per_book, shelf->total_books * sizeof(int));
    if (!shelf->pages_per_book)
    {
        perror("Memory allocation failed");
        free(shelf);
        exit(EXIT_FAILURE);
    }

    shelf->pages_per_book[new_index] = pages;
}

// Function to get the number of books in a specific shelf
int get_num_books(Shelf *shelf)
{
    return shelf->total_books;
}

// Function to free memory allocated for a shelf
void free_shelf(Shelf *shelf)
{
    free(shelf->pages_per_book);
    free(shelf);
}

int main()
{
    int num_shelves;
    int num_commands;

    scanf("%d", &num_shelves);
    scanf("%d", &num_commands);

    // Create an array of shelves
    Shelf **shelves = (Shelf **)malloc(num_shelves * sizeof(Shelf *));
    if (!shelves)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize each shelf
    for (int i = 0; i < num_shelves; ++i)
    {
        shelves[i] = create_shelf(0);
    }

    // Add books to shelves (for demonstration purposes)
    for (int i = 0; i < num_commands; i++)
    {
        int cmd, shelf, page;
        scanf("%d %d %d", &cmd, &shelf, &page);

        if (cmd == 1)
        {
            add_book(shelves[shelf], page);
        }
        else if (cmd == 2)
        {
            printf("%d\n", shelves[shelf]->pages_per_book[page]);
        }
        else if (cmd == 3)
        {
            int num_books_in_shelf = get_num_books(shelves[shelf]);
            printf("%d", num_books_in_shelf);
        }
    }

    // Free memory for all shelves
    for (int i = 0; i < num_shelves; ++i)
    {
        free_shelf(shelves[i]);
    }
    free(shelves);

    return 0;
}

// // Function to print pages of each book in every shelf
// void print_shelves(Shelf **shelves, int num_shelves)
// {
//     for (int i = 0; i < num_shelves; ++i)
//     {
//         printf("Shelf %d:\n", i);
//         for (int j = 0; j < shelves[i]->total_books; ++j)
//         {
//             printf("Book %d: %d pages\n", j, shelves[i]->pages_per_book[j]);
//         }
//         printf("\n");
//     }
// }

// // Function to remove a book from a specific shelf
// void remove_book(Shelf* shelf, int book_index) {
//     if (book_index < 0 || book_index >= shelf->total_books) {
//         printf("Invalid book index. Please choose a valid index (0 to %d).\n", shelf->total_books - 1);
//         return;
//     }

//     // Shift remaining books to fill the gap
//     for (int i = book_index; i < shelf->total_books - 1; ++i) {
//         shelf->pages_per_book[i] = shelf->pages_per_book[i + 1];
//     }

//     shelf->total_books--; // Decrement the total number of books
//     shelf->pages_per_book = (int*)realloc(shelf->pages_per_book, shelf->total_books * sizeof(int));
//     if (!shelf->pages_per_book) {
//         perror("Memory allocation failed");
//         free(shelf);
//         exit(EXIT_FAILURE);
//     }

//     printf("Removed book at index %d from the shelf.\n", book_index);
// }

// // Function to update the page count of an existing book
// void update_book_pages(Shelf* shelf, int book_index, int new_pages) {
//     if (book_index < 0 || book_index >= shelf->total_books) {
//         printf("Invalid book index. Please choose a valid index (0 to %d).\n", shelf->total_books - 1);
//         return;
//     }

//     shelf->pages_per_book[book_index] = new_pages;
//     printf("Updated book at index %d with new page count: %d pages.\n", book_index, new_pages);
// }