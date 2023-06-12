#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libraryStructures.h"
#include "library.h"
#include "user.h"
#include "librarian.h"
#include "utility.h"

////
// Code module for main library menu and file management
// Reads the book and initialises the problem data

// Initialise library data
// Input:
// bookfile - name of book file
// theLibrary - library data structure

void initLibrary( char *bookFile, Library *theLibrary ) {

  theLibrary->maxBooks = 12;
  theLibrary->maxBorrowed = 4;
  theLibrary->bookList=malloc(sizeof(Book)*theLibrary->maxBooks);

  // TO DO :

  // dynamically allocate the bookList array for storing books

  // check the book file exists
  // use the error message and exit the program if it does not
  FILE *file;
  file = fopen(bookFile,"r");
  if (file !=NULL)
  {
    theLibrary->numBooks = readBooks(file, theLibrary->bookList);
    theLibrary->theUser.numBorrowed=0;
    fclose(file);
    return;
  }
  else
  {
    printf("Error\nBook file does not exist: %s\n",bookFile);
    return ;
  }

  // open it if it exists

  // use the readBooks function to read in the file and add the book records into the bookList array

  // remember to close the file

  // Initialise the User data

  return;
}

// Read in book file and create the books data structure
// the book file is in a fixed format:
// * book author
// * book title
// * blank line
// Input:
//   books - file pointer to text input file
//   bookList - alocated array for storing Book structures
// Output:
//   numBooks - number of books read

int readBooks( FILE *books, Book *bookList ) {
  // TO DO:
  // read from the book file pointer
  int numBooks = 0;
  char authorortitle[40];
  int i = 0;
  int c = 1;
  while(fscanf(books,"%40[^\n]\n",authorortitle)!=EOF)
  {
    removeNewLine(authorortitle);
    if (c == 1)
    {
      strcpy(bookList[i].author,authorortitle);
      c = c + 1;
    }
    else if (c==2)
    {
      strcpy(bookList[i].title,authorortitle);
      bookList[i].available=1;
      i++;
      numBooks++;
      c =  1;
    }
    else if (strcmp(authorortitle,"\n")==0)
    {
      c = 1;
    }
  }
  // assign values to a Book structure in the bookList array for each complete record
  // read data until the file ends
  return numBooks;
}

// Free any allocated library data
// Input:
// theLibrary - library data structure

void exitLibrary( Library *theLibrary ) {

  // TO DO:
  free(theLibrary->bookList);
  // free the allocated lists

  return;
}

// DO NOT ALTER THIS FUNCTION
// Library menu system

void libraryCLI( char *bookFile ) {
    int libraryOpen = 1;
    int option;

    // create the library structure
    Library *theLibrary = (Library *)malloc( sizeof(Library) );

    initLibrary( bookFile, theLibrary );

    while( libraryOpen ){
        printf("\n Main menu options\n 1 User login\n 2 Librarian login\n 3 Exit system\n Choice:");
        option = optionChoice();

        if( option == 1 ) {
            printf("\nUser login\n");
            userCLI( theLibrary );
        }
        else if( option == 2 ) {
            printf("\nLibrarian login\n");
            librarianCLI( theLibrary );
        }
        else if( option == 3 ) {
            libraryOpen = 0;
            printf("\nClosing\n");
        }
        else
            printf("\nUnknown option\n");
    }

    exitLibrary( theLibrary );

    // free the library structure
    free( theLibrary );

    return;
}
