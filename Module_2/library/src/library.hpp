#ifndef ELEC_AS_CPP_LIBRARY
#define ELEC_AS_CPP_LIBRARY

#include <string>
#include <vector>
#include "book.hpp"
#include "customer.hpp"

/*TODO: modify also customer.cpp so that it prints "* " before every book for customer!
 * Like this:
Customer: Chris Customer, 34674568, has 1 books on loan:
* Book: The C++ programming language, author: Stroustrup, Bjarne, ISBN: 978-0-321-56384-2, loaned 1, due date: 21-9-2015
 *
*/

class Library
{
    public:
        /* Library:
         * the constructor of the Library class, takes following parameters:
         * the library's name (string const&)
         * Remember to also initialize books and customers in the constructor!
         */

         Library(std::string const& name);

        /* getName:
         * returns the library's name as a string, takes no parameters.
         * This function should not alter the Library object's state, in other words the function should be const.
         */
         const std::string getName() const;
        /* getBooks:
         * returns the Library's books as a reference to a vector<Book>, takes no parameters.
         * (vector<Book>&)
         */
         std::vector<Book>& getBooks();
        /* getCustomers:
         * returns the Library's customers as a reference to a vector<Customer>, takes no parameters.
         */
         std::vector<Customer>& getCustomers();
        /* findBookByName:
         * returns a Book, takes a const reference to a string as a parameter.
         */
         Book findBookByName(const std::string&);
        /* findBooksByAuthor:
         * returns a vector of Books, takes a const reference to a string as a parameter.
         */
         std::vector<Book> findBooksByAuthor(const std::string&);
        /* findAllLoanedBooks():
         * returns a vector of Books, takes no parameters.
         */
        std::vector<Book> findAllLoanedBooks();

        /* findCustomer:
         * returns a Customer, takes a const reference to a string representing the Customer's id as a parameter.
         */
         Customer findCustomer(const std::string&);

    private:
        /* Make variables for:
         * name (string)
         * books (vector<Book>)
         * customers (vector<Customer>)
         */

         std::string name;
         std::vector<Book> books;
         std::vector<Customer> customers;
};

#endif
