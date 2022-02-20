// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu
#include <iomanip>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include "Book.hpp"

using std::cin, std::cout, std::showpoint, std::fixed, std::setprecision, std::vector;

int main()
{
  // Cout beginning block text
  cout << "Welcome to Forgotten Books, a bookstore filled with books from all nations.  Place books into your shopping cart by entering each book's information.\n"
       << "   enclose string entries in quotes, separate fields with commas\n"
       << "   Enter CTL-Z (Windows) or CTL-D (Linux) to quit\n\n";

  // Create a vector of ptrs
  vector<std::unique_ptr<Book>> shoppingCart;

  // Get Books by User
  Book book;
  while( cout << "Enter ISBN, Title, Author, and Price\n", cin >> book )
  {
    // push back shopping cart with book.
    shoppingCart.push_back( std::make_unique<Book>( std::move( book ) ) );
    // adding showpoint, fixed, and setprecision to make sure decimal places for money comes out
    cout << showpoint << fixed << setprecision( 2 )
         << "Item added to shopping cart: " << *shoppingCart.back() << "\n\n";
  }

  cout << "\n\nHere is an itemized list of the items in your shopping cart:\n";
  for( unsigned long i = shoppingCart.size(); i-- > 0; )
  {
    // adding showpoint, fixed, and setprecision to make sure decimal places for money comes out
    cout << showpoint << fixed << setprecision( 2 )
         << *shoppingCart[i] << '\n';
  }
  return 0;
}
