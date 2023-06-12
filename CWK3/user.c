#include <stdio.h>
#include <stdlib.h>

#include "libraryStructures.h"
#include "user.h"
#include "utility.h"

////
// Code module for the library user
// They can look for available books,
// borrow and return books

// List the books that are available to borrow
// Input
// bookList - the array of Book structures
// numBooks - the number of books

void listAvailableBooks( Book *bookList, int numBooks ) {
  // TO DO :
  // print out available books with format "list number - author - title" on each line
  int i;
  for(i=0;i<numBooks;i++)
  {
    if (bookList[i].available == 1)
    {
      printf("%i - %s -%s\n",i,bookList[i].author,bookList[i].title);
    }
  }
  return;
}

// Borrow a book
// Input
// theUser - user data structure
// bookList - the array of Book structures
// numBooks - the number of books
// maxBorrowed - max books we can borrow

void borrowBook( User *theUser, Book *bookList, int numBooks, int maxBorrowed ) {

  // TO DO :

  // For any error message you should return to the menu

  // check that the user can borrow a book
  if (theUser->numBorrowed ==maxBorrowed )
  {
    printf("You have to return a book before you can borrow another\n");
  }
  else
  {
    printf("Which book? (enter book number)");
    int bc = optionChoice();
    if (bc> (numBooks-1)|| bc<0)
    {
      printf("Error\nInvalid choice\n");
      return;
    }
    else if (bookList[bc].available==0)
    {
      printf("Book is not available\n");
    }
    else
    {
      theUser->numBorrowed++;
      numBooks= numBooks-1;
      bookList[bc].available=0;
    }
  }

  // request the choice of book

  // check that the choice is valid
  // error messages



  // borrow the book, update the data structures

  return;
}

// List books I have borrowed
// Input
// theUser - user data structure
// bookList - the array of Book structures
// maxBorrowed - max books we can borrow

void listMyBooks( User *theUser, Book *bookList, int maxBorrowed ) {

  // TO DO :

  // list my books in format "number - author - title"
  int i;
  for(i=0;i<maxBorrowed;i++)
  {
    if (bookList[i].available == 0)
    {
      printf("%i - %s - %s",i,bookList[i].author,bookList[i].title);
    }
  }
  return;
}

// Return a book
// Input
// theUser - user data structure
// bookList - the array of Book structures
// numBooks - the number of books
// maxBorrowed - max books we can borrow

void returnBook( User *theUser, Book *bookList, int numBooks, int maxBorrowed ) {

  // TO DO :

  // For any error message you should return to the menu

  // check that we have borrowed books
  // error messages
  if (theUser->numBorrowed==0)
  {
    printf("Error\nYou have not borrowed any books\n");
  }
  // request the choice of book
  // message
  else
  {
      printf("Which book? (number):");
      int bc = optionChoice();
      if (bc> (numBooks-1)|| bc<0)
      {
        printf("Error\nInvalid choice\n");
        return;
      }
      else
      {
        theUser->numBorrowed--;
        numBooks= numBooks+1;
        bookList[bc].available=1;
      }

  }


  // check the choice is valid
  // error messages
  // return the book and update data structures

  return;
}

// DO NOT ALTER THIS FUNCTION

// Menu system for library user

void userCLI( Library *theLibrary ) {
    int userLoggedIn = 1;
    int option;

    while( userLoggedIn ){
        printf("\n User options\n 1 List available books\n 2 Borrow book\n 3 Return book\n 4 Log out\n Choice:");
        option = optionChoice();

        if( option == 1 ) {
            printf("\nList available books:\n");
            listAvailableBooks( theLibrary->bookList, theLibrary->numBooks );
        }
        else if( option == 2 ) {
            printf("\nBorrow book from library:\n");
            listAvailableBooks( theLibrary->bookList, theLibrary->numBooks );
            borrowBook( &(theLibrary->theUser), theLibrary->bookList, theLibrary->numBooks, theLibrary->maxBorrowed );
        }
        else if( option == 3 ) {
            printf("\nReturn book from my list:\n");
            listMyBooks( &(theLibrary->theUser), theLibrary->bookList, theLibrary->maxBorrowed );
            returnBook( &(theLibrary->theUser), theLibrary->bookList, theLibrary->numBooks, theLibrary->maxBorrowed );
        }
        else if( option == 4 ) {
            userLoggedIn = 0;
            printf("\nLogging out\n");
        }
        else
            printf("\nUnknown option\n");
    }
    return;
}
