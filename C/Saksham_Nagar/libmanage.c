#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
struct book {
    int id;
    char Author[200];
    char title[200];
    char isbn13[20];
    char languages[200];
    char publication_date[20];
    char publisher_name[200];
    float price;
};
struct student {
    int student_id;
    char first_name[50];
    char middle_name[50];
    char last_name[50];
    char email[100];
    char address[200];
    long long int phn_no;
};
void addBook() 
{
    FILE *openfile = fopen("Book.bin", "rb+");
    if (!openfile) {
        openfile = fopen("Book.bin", "wb+");
    }
    struct book b;
    bool duplicate = false;
    printf("Enter the book ID: ");
    scanf("%d", &b.id);
    struct book temp;
    while (fread(&temp, sizeof(struct book), 1, openfile) == 1) {
        if (temp.id == b.id) {
            printf("Book ID already exists. Please enter a unique ID.\n");
            duplicate = true;
            break;
        }
    }
    if (!duplicate) {
        printf("Enter the book Author's name: ");
        scanf("%s", b.Author);

        printf("Enter the Book's Title: ");
        scanf("%s", b.title);

        printf("Enter the Book's ISBN number: ");
        scanf("%s", b.isbn13);

        printf("Enter the Language of the Book: ");
        scanf("%s", b.languages);

        printf("Enter the Book's Publication Date: ");
        scanf("%s", b.publication_date);

        printf("Enter the Book's Publisher Name: ");
        scanf("%s", b.publisher_name);

        printf("Enter the Book's Price: ");
        scanf("%f", &b.price);

        fseek(openfile, 0, SEEK_END);
        fwrite(&b, sizeof(struct book), 1, openfile);
        printf("Book added successfully.\n");
    }
    fclose(openfile);
}
void delBook(int idToDelete)
{
    FILE *openfile = fopen("Book.bin", "rb");
    if (!openfile) {
        printf("\nError opening file Book\n");
        return;
    }
    FILE *temp = fopen("Temp.bin", "wb");
    if (!temp) {
        printf("\nError opening temp file\n");
        fclose(openfile);
        return;
    }
    struct book b;
    bool found = false;
    while (fread(&b, sizeof(struct book), 1, openfile) == 1) {
        if (b.id != idToDelete) {
            fwrite(&b, sizeof(struct book), 1, temp);
        } else {
            found = true;
        }
    }
    fclose(openfile);
    fclose(temp);
    if (found) {
        remove("Book.bin");
        rename("Temp.bin", "Book.bin");
        printf("\nRecord Deleted Successfully.\n");
    } else {
        printf("Book ID not found.\n");
    }
}
void getBookInfo() 
{
    FILE *openfile = fopen("Book.bin", "rb");
    if (!openfile) {
        printf("No books found.\n");
        return;
    }
    struct book b;
    printf("Book Information:\n");
    while (fread(&b, sizeof(struct book), 1, openfile) == 1) {
        printf("ID: %d,\n Author: %s,\n Title: %s,\n ISBN: %s,\n Language: %s,\n Publication Date: %s,\n Publisher: %s,\n Price: %f",
               b.id, b.Author, b.title, b.isbn13, b.languages, b.publication_date, b.publisher_name, b.price);
    }
    fclose(openfile);
}
int searchBook(int idToSearch) 
{
    FILE *openfile = fopen("Book.bin", "rb");
    if (!openfile) {
        printf("No books found.\n");
        return 0;
    }
    struct book b;
    while (fread(&b, sizeof(struct book), 1, openfile) == 1) {
        if (idToSearch == b.id) {
            printf("ID: %d, Author: %s, Title: %s, ISBN: %s, Language: %s, Publication Date: %s, Publisher: %s, Price: %.2f\n",
                   b.id, b.Author, b.title, b.isbn13, b.languages, b.publication_date, b.publisher_name, b.price);
            fclose(openfile);
            return 1;
        }
    }
    printf("No record found.\n");
    fclose(openfile);
    return 0;
}
void addStudent() 
{
    FILE *openfile = fopen("Student.bin", "ab");
    if (!openfile) {
        printf("Error opening Student file.\n");
        return;
    }

    struct student s;
    printf("Enter the Student's ID: ");
    scanf("%d", &s.student_id);

    printf("Enter First Name: ");
    scanf("%s", s.first_name);

    printf("Enter Middle Name: ");
    scanf("%s", s.middle_name);

    printf("Enter Last Name: ");
    scanf("%s", s.last_name);

    printf("Enter Student's Email: ");
    scanf("%s", s.email);

    printf("Enter Student's Address: ");
    scanf("%s", s.address);

    printf("Enter Mobile Number: ");
    scanf("%lld", &s.phn_no);

    fwrite(&s, sizeof(struct student), 1, openfile);
    printf("Student added successfully.\n");
    fclose(openfile);
}
void searchStudent(int idToSearch) 
{
    FILE *file = fopen("Student.bin", "rb");
    if (!file) {
        printf("No students found.\n");
        return;
    }
    struct student s;
    bool found = false;
    while (fread(&s, sizeof(struct student), 1, file) == 1) {
        if (idToSearch == s.student_id) {
            printf("\nStudent's ID: %d,\n Name: %s %s %s,\n Email: %s,\n Address: %s,\n Mobile Number: %lld",
                   s.student_id, s.first_name, s.middle_name, s.last_name, s.email, s.address, s.phn_no);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("No record found.\n");
    }

    fclose(file);
}
void issueBook(int studentId) {
    FILE *studentFile = fopen("Student.bin", "rb+");
    if (!studentFile) {
        printf("No students found.\n");
        return;
    }
    struct student s;
    bool studentFound = false;
    long pos;
    while (fread(&s, sizeof(struct student), 1, studentFile) == 1) {
        if (studentId == s.student_id) {
            studentFound = true;
            pos = ftell(studentFile) - sizeof(struct student);
            break;
        }
    }
    if (!studentFound) {
        printf("Student ID not found.\n");
        fclose(studentFile);
        return;
    }

    else{
    int bookId;
    printf("Enter the Book ID to issue: ");
    scanf("%d", &bookId);
    FILE *bookFile = fopen("Book.bin", "rb");
    if (!bookFile) {
        printf("No books found.\n");
        fclose(studentFile);
        return;
    }
    struct book b;
    bool bookFound = false;
    while (fread(&b, sizeof(struct book), 1, bookFile) == 1) {
        if (bookId == b.id) {
            bookFound = true;
        }
    }
    fclose(bookFile);
    if (!bookFound) {
        printf("Book ID not found.\n");
        fclose(studentFile);
        return;
    }
    fseek(studentFile, pos, SEEK_SET);
    fwrite(&s, sizeof(struct student), 1, studentFile);
    printf("Book issued successfully.\n");
    }
    fclose(studentFile);
}
int main() {
    int choice;
    while (1) {
        printf("\n\tWELCOME\t\n");
        printf("1. Add Book\n");
        printf("2. Display Books Information\n");
        printf("3. Delete Book Information\n");
        printf("4. Search Book\n");
        printf("5. Student Info\n");
        printf("6. Issue Book\n");
        printf("7. Add Student\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                getBookInfo();
                break;
            case 3:
                {
                    int id;
                    printf("Enter the Book ID to delete: ");
                    scanf("%d", &id);
                    delBook(id);
                }
                break;
            case 4:
                {
                    int id;
                    printf("Enter the Book ID to search: ");
                    scanf("%d", &id);
                    searchBook(id);
                }
                break;
            case 5:
                {
                    int id;
                    printf("Enter the Student ID to search: ");
                    scanf("%d", &id);
                    searchStudent(id);
                }
                break;
            case 6:
                {
                    int id;
                    printf("Enter the Student ID to issue a book: ");
                    scanf("%d", &id);
                    issueBook(id);
                }
                break;
            case 7:
                addStudent();
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}