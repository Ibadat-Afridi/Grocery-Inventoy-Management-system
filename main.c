#include <stdio.h>
// Importing or including the custom header file
#include "login.h"               //Login Feature
#include "view_home_page.h"      //View Home Menu Feature
#include "add_product.h"         //Add Product Feature
#include "delete_product.h"      //Delete product Feature
#include "search_product.h"      //Search Product Feature
#include "display_all_product.h" //Display all items Feature
#include "logout.h"              //Logout Feature

int main()
{
    // condition if the admin doesnot login successfully so it will return 0 means the program will end.
    if (!admin_login())
        return 0;

    // condition if the admin login successfully so it will return 1 means the program struture will move forward.

    else
    {

        int choice;
        //this is an infinity while loop every time login succeeded the program will goes into an infinity loop except we terminat it out by using logout function
        while (1)
        {
            // first of all we want to display the menu or options to see which operations can we perform
            view_home();
            //after every operation view home page will shown y default that's why we put it in an infinity loop
            printf("Choice: ");
            //inputing choice from admin
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                // Adding a new product according by taking name,id,quantity and price as an input from the admin
                add_new_product();
                break;
            case 2:
                // Deleting an item or product based on product id inputed by admin
                delete_product_by_id();
                break;
            case 3:
                // Searching a specific item or product through inputed id
                search_product_by_id();
                break;
            case 4:
                // Displaying all the products inputed by the admin
                display_all_products();
                break;
            case 5:
                admin_logout();
                // After performing all the operations so we would like to exit.so in this case it will also return 0 which will terminate the programe.
                printf("System Closed");
                return 0;
            default:
                // in case of invalid choice made by the admin it will display this thing
                printf("Invalid choice\n");
            }
        }
    }
}
