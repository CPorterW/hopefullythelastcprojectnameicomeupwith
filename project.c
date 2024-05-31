#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 I had some writer's block trying tp come up with ideas so I
 decided to face an issue I'm facing in my life currently--
 trying to figure out the order in which to read Ender's
 Game books.
 */

// Define the structure for a Book in the reading list
typedef struct Book {
    char title[256];
    char description[512];
    int read; // 0 for unread, 1 for read
    struct Book *next;
} Book;

Book *head = NULL;

// Predefined books for each series
typedef struct {
    char title[256];
    char description[512];
} PredefinedBook;

PredefinedBook theFormicWars[] = {
    {"Earth Unaware", "This follows the epic tales of Victor, Imala, Lem and Captain \
    \nO'Toole as they begin to realize that aliens aren't only real, but that they are\
    coming, and that nobody is doing anything about it. This is not just an imaginative\
    science fiction, this is a survey of human stories, cultures and responses to\
    \ncrisis that are very real in our day."},
    {"Earth Afire", "Mazer Rackham and Bingwen join the fight as paths begin to cross.\
    \nAs millions die under alien hands, a handful of smart, courageous people save\
    \nwhat lives they can and plot to destroy the invaders."},
    {"Earth Awakens", "Everyone puts their lives on the line to take an alien ship,\
    \nbut questions about the purpose and nature of the aliens go unanswered."},
    {"The Swarm", "I will update these descriptions as I finish reading these books."},
    {"The Hive", "I will update these descriptions as I finish reading these books."},
    {"The Queens", "I will update these descriptions as I finish reading these books."}
};

PredefinedBook endersGame[] = {
    {"Ender's Game", "This is not the chronological beginning of Ender's universe,\
    \nbut was the first book written, and Orson Scott Card's most popular by far.\
    \nIt tells a passionate, provocative yet sympathetic tale from the perspective of\
    \na child who is born and bred to save the world from alien invasion. The\
    \nprofundity of this novel is not in its imaginative fictional speculations,\
    \nbut instead in its examination of the mind of a brilliant and empathetic child."}
};

PredefinedBook theSpeakerTrilogy[] = {
    {"The Speaker for the Dead", "Orson Scott Card said that Ender's Game was only\
    \nwritten as a precursor for this book. He says that Speaker for the Dead tells\
    \nthe truth he most wanted to tell, which is that people should be understood,\
    \nand that once they are understood, they will be loved."},
    {"Investment Counselor - Short Story", "I will update these descriptions as I finish reading these books."},
    {"Xenocide", "I will update these descriptions as I finish reading these books."},
    {"Children of the Mind", "I will update these descriptions as I finish reading these books."}
};

PredefinedBook shadowSaga[] = {
    {"Ender's Shadow", "The story of Bean, Ender's brilliant friend and fellow\
    \ncommander. This book takes a strange boy from starving on crime-ridden streets\
    \nto commanding star fleets against alien armadas. As a genetic anomaly, Bean\
    \nstruggles to confirm that he is just as much human as the people he is made\
    \nto save."},
    {"Shadow of the Hegemon", "I will update these descriptions as I finish reading these books."},
    {"Shadow Puppets", "I will update these descriptions as I finish reading these books."},
    {"Shadow of the Giant", "I will update these descriptions as I finish reading these books."},
    {"Shadows in Flight", "I will update these descriptions as I finish reading these books."},
    {"Messenger - Short Story", "I will update these descriptions as I finish reading these books."},
    {"The Last Shadow", "All of the Speaker Trilogy and of the Shadow Saga should be \
    \nread before this book. I will update these descriptions as I finish reading these \
    \nbooks."}
};

PredefinedBook otherWorks[] = {
    // Ender in Exile 
    {"Ender in Exile", "I will update these descriptions as I finish reading these books."},
    {"Governor Wiggin - Short Story", "I will update these descriptions as I finish reading these books."},
    {"The Gold Bug - Short Story", "I will update these descriptions as I finish reading these books."},
    // Fleet School
    {"Children of the Fleet", "I will update these descriptions as I finish reading these books."},
    {"Renegat - Short Story", "I will update these descriptions as I finish reading these books."},
    // IGMS Anthology
    {"Mazer in Prison", "I will update these descriptions as I finish reading these books."},
    {"Pretty Boy", "I will update these descriptions as I finish reading these books."},
    {"Cheater", "I will update these descriptions as I finish reading these books."},
    // Ender's Parents
    {"The Polish Boy - Short Story", "I will update these descriptions as I finish reading these books."},
    {"Teacher's Pest - Short Story", "I will update these descriptions as I finish reading these books."},
    // Christmas Stories
    {"A War of Gifts - Short Story", "I will update these descriptions as I finish reading these books."},
    {"Ender's Stocking - Short Story", "I will update these descriptions as I finish reading these books."}
};

void displayBooksMenu(int seriesChoice);

// Function prototypes
Book* addBook(Book *head, const char *title, const char *description);
void displayReadingList(Book *head);
void findBook(Book *head, const char *title);
void markBookAsRead(Book *head, const char *title);
void saveReadingList(const char *filename, Book *head);
void loadReadingList(const char *filename, Book **head);
void displayMainMenu(void);
void displaySeriesMenu(void);

int main() {
    loadReadingList("reading_list.txt", &head);
    int choice;
    do {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left by scanf
        switch (choice) {
            case 1: // Add book from pre-defined series
                displaySeriesMenu();
                break;
            case 2: // Display reading list
                displayReadingList(head);
                break;
            case 3: // Find book
                printf("Enter the title of the book to find: ");
                char title[256];
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove the newline character
                findBook(head, title);
                break;
            case 4: // Mark book as read
                printf("Enter the title of the book to mark as read: ");
                char readTitle[256];
                fgets(readTitle, sizeof(readTitle), stdin);
                readTitle[strcspn(readTitle, "\n")] = '\0';
                markBookAsRead(head, readTitle);
                break;
            case 0: // Quit program
                printf("Exiting program.\n");
                saveReadingList("reading_list.txt", head);
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);
    return 0;
}

void displayMainMenu(void) {
    printf("\nMain Menu:\n");
    printf("1. Add Book from Series\n");
    printf("2. Display Reading List\n");
    printf("3. Find Book\n");
    printf("4. Mark Book as Read\n");
    printf("0. Quit\n");
}

void displaySeriesMenu(void) {
    int seriesChoice;
    printf("\nSeries Menu:\n");
    printf("1. The Formic Wars\n");
    printf("2. Ender's Game\n");
    printf("3. The Speaker Trilogy\n");
    printf("4. Shadow Saga\n");
    printf("5. Other works in Ender's universe\n");
    printf("0. Return to Main Menu\n");
    printf("Enter the series number: ");
    scanf("%d", &seriesChoice);
    getchar(); // Consume the newline character left by scanf

    if (seriesChoice >= 1 && seriesChoice <= 5) {
        displayBooksMenu(seriesChoice);
    } else if (seriesChoice != 0) {
        printf("Invalid choice. Returning to Main Menu.\n");
    }
}

void displayBooksMenu(int seriesChoice) {
    int bookChoice;
    PredefinedBook *books = NULL;
    int numBooks = 5;

    switch (seriesChoice) {
        case 1:
            books = theFormicWars;
            numBooks = 6;
            break;
        case 2:
            books = endersGame;
            numBooks = 1;
            break;
        case 3:
            books = theSpeakerTrilogy;
            numBooks = 3;
            break;
        case 4:
            books = shadowSaga;
            numBooks = 7;
            break;
        case 5:
            books = otherWorks;
            numBooks = 12;
            break;
        default:
            printf("Invalid series choice.\n");
            return;
    }

    printf("\nBooks in Series #%d:\n", seriesChoice);
    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s\n", i + 1, books[i].title);
    }
    printf("0. Return to Series Menu\n");
    printf("Enter the book number: ");
    scanf("%d", &bookChoice);
    getchar(); // Consume the newline character left by scanf

    if (bookChoice >= 1 && bookChoice <= numBooks) {
        head = addBook(head, books[bookChoice - 1].title, books[bookChoice - 1].description);
        printf("Book added to the reading list: %s\n", books[bookChoice - 1].title);
    } else if (bookChoice != 0) {
        printf("Invalid choice. Returning to Series Menu.\n");
    }
}

Book* addBook(Book *head, const char *title, const char *description) {
    Book *newBook = (Book *)malloc(sizeof(Book));
    if (!newBook) {
        printf("Memory allocation failed\n");
        return head;
    }
    strncpy(newBook->title, title, sizeof(newBook->title) - 1);
    strncpy(newBook->description, description, sizeof(newBook->description) - 1);
    newBook->title[sizeof(newBook->title) - 1] = '\0';
    newBook->description[sizeof(newBook->description) - 1] = '\0';
    newBook->read = 0; // Default to unread
    newBook->next = head;
    return newBook;
}

void displayReadingList(Book *head) {
    Book *current = head;
    int index = 0;
    while (current != NULL) {
        printf("%d. [%c] %s - %s\n", index, current->read ? 'x' : ' ', current->title, current->description);
        current = current->next;
        index++;
    }
}

void findBook(Book *head, const char *title) {
    Book *current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            printf("Book found: [%c] %s - %s\n", current->read ? 'x' : ' ', current->title, current->description);
            return;
        }
        current = current->next;
    }
    printf("Book not found: %s\n", title);
}

void markBookAsRead(Book *head, const char *title) {
    Book *current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            current->read = 1;
            printf("Book marked as read: %s\n", current->title);
            return;
        }
        current = current->next;
    }
    printf("Book not found: %s\n", title);
}

void saveReadingList(const char *filename, Book *head) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Could not open file for saving reading list");
        return;
    }
    Book *current = head;
    while (current != NULL) {
        fprintf(file, "%d %s\n%s\n", current->read, current->title, current->description);
        current = current->next;
    }
    fclose(file);
}

void loadReadingList(const char *filename, Book **head) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file for loading reading list");
        return;
    }
    char line[512];
    while (fgets(line, sizeof(line), file)) {
        Book *newBook = (Book *)malloc(sizeof(Book));
        if (!newBook) {
            printf("Memory allocation failed\n");
            fclose(file);
            return;
        }
        sscanf(line, "%d %[^\n]", &newBook->read, newBook->title);
        fgets(newBook->description, sizeof(newBook->description), file);
        newBook->description[strcspn(newBook->description, "\n")] = '\0'; // Remove newline character
        newBook->next = *head;
        *head = newBook;
    }
    fclose(file);
}
