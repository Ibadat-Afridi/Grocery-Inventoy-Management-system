#include <stdio.h>
#include <string.h>

struct credentials
{
    char uname[7];
    char upassword[6];
};

void add_new_product();
int admin_login();
int view_home();
void delete_product_by_id();
void search_product_by_id();
void display_all_products();
void admin_logout();

// Global arrays to store products in memory
char product_names[100][100]; // Can store 100 product names
int product_ids[100];         // Can store 100 product IDs
int product_quantities[100];  // Can store 100 quantities
float product_prices[100];    // Can store 100 prices
int total_products = 0;       // Counter for how many products we have
int main()
{
    // condition if the admin doesnot login successfully so it will return 0 means the program will end.
    if (!admin_login())
        return 0;

    // condition if the admin login successfully so it will return 1 means the program struture will move forward.

    else
    {

        int choice;
        // this is an infinity while loop every time login succeeded the program will goes into an infinity loop except we terminat it out by using logout function
        while (1)
        {
            // first of all we want to display the menu or options to see which operations can we perform
            view_home();
            // after every operation view home page will shown y default that's why we put it in an infinity loop
            printf("Choice: ");
            // inputing choice from admin
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

int admin_login()
{
    // creating instances for two admins
    struct credentials cred1, cred2;
    // putting the credential username and password in the structure variables using strcpy() string function which take two arguments 1 is variable and another is content
    strcpy(cred1.uname, "ibadat");
    strcpy(cred1.upassword, "12345");
    strcpy(cred2.uname, "habib");
    strcpy(cred2.upassword, "67890");
    // declaring another two variables by which we can get inputs from the admin
    char username[7];
    char pass[6];
    // loop running four times
    for (int i = 1; i <= 4; i++)
    {
        // taking admin username and admin password as input
        printf("Enter admin username: ");
        scanf("%6s", username);
        printf("Enter admin password: ");
        scanf("%5s", pass);
        // Checking the admin attempting the password wrong many times
        if (i == 4)
        {
            printf("You tried several times and make invalid credentials so your account session has been blocked\n");
            return 0;
            break;
        }
        // verifying the admins by using the strcmp function which compare the ASCII Code
        if ((strcmp(username, cred1.uname) == 0 && strcmp(pass, cred1.upassword) == 0) || (strcmp(username, cred2.uname) == 0 && strcmp(pass, cred2.upassword) == 0))
        {
            printf("Access Granted to Admin Panel\n");
            return 1;
            break;
        }
        // In case of wrong credentials inputed on each iteration the below else will be executed
        else
        {
            printf("Wrong Credentials, Please try again!\n");
        }
    }
    return 0;
}

int view_home()
{
    printf("\n===== Home Menu =====\n");
    printf("1. Add Product\n");
    printf("2. Delete Product\n");
    printf("3. Search Product\n");
    printf("4. Display All Products\n");
    printf("5. Logout\n");
    printf("======================\n");
}

void add_new_product()
{
    // Checking if we have space for more products
    if (total_products >= 100)
    {
        printf("Storage full! Cannot add more products.\n");
        return;
    }

    // declaring variales for getting product name,id,quantity and price from the admin
    char temp_name[100];
    int temp_id, temp_quantity;
    float temp_price;

    // Taking inputs from admin
    printf("Enter the product name: ");
    scanf("%s", temp_name);

    printf("Enter the product ID: ");
    scanf("%d", &temp_id);

    printf("Enter the product quantity: ");
    scanf("%d", &temp_quantity);

    printf("Enter the product price: ");
    scanf("%f", &temp_price);

    // Validating if the entered Id already exists
    for (int i = 0; i < total_products; i++)
    {
        if (product_ids[i] == temp_id)
        {
            printf("Error: Product ID %d already exists!\n", temp_id);
            return;
        }
    }

    // Saving the product details in the arrays
    strcpy(product_names[total_products], temp_name);
    product_ids[total_products] = temp_id;
    product_quantities[total_products] = temp_quantity;
    product_prices[total_products] = temp_price;

    // Counter for incrementing the product
    total_products++;

    // Displaying the data which is entered
    printf("\n=== Product Added Successfully! ===\n");
    printf("Name: %s\n", temp_name);
    printf("ID: %d\n", temp_id);
    printf("Quantity: %d\n", temp_quantity);
    printf("Price: %.2f\n", temp_price);
    printf("Total products in system: %d\n", total_products);
}

void delete_product_by_id()
{
    // checking if there is product available or not
    if (total_products == 0)
    {
        printf("No products in the system to delete!\n");
        return;
    }
    // declaring variable for deleting product using id
    int delete_id;
    // taking id as an input
    printf("Enter product ID to delete: ");
    scanf("%d", &delete_id);

    // loop which will will check total product
    for (int i = 0; i < total_products; i++)
    {
        // validating product id should be equal to delete id so the idem should be deletable
        if (product_ids[i] == delete_id)
        {
            printf("Deleting product: %s (ID: %d)\n", product_names[i], product_ids[i]);

            // shifting all the product afters the deleted item gap to fill it
            for (int j = i; j < total_products - 1; j++)
            {
                strcpy(product_names[j], product_names[j + 1]);
                product_ids[j] = product_ids[j + 1];
                product_quantities[j] = product_quantities[j + 1];
                product_prices[j] = product_prices[j + 1];
            }
            // incrementing the total_product array size
            total_products--;
            // printing messages for confirmation and remaining products
            printf("Product deleted successfully!\n");
            printf("Total products remaining: %d\n", total_products);
            return;
        }
    }

    printf("Product with ID %d not found!\n", delete_id);
}

void search_product_by_id()
{
    // checking if there are product available to be searched
    if (total_products == 0)
    {
        printf("No products in the system to search!\n");
        return;
    }
    // declaring variable search id for getting the id of item to be search
    int search_id;
    // taking search id as an input
    printf("Enter product ID to search: ");
    scanf("%d", &search_id);

    // loop for searching
    for (int i = 0; i < total_products; i++)
    {
        // condition if product id is equal to search id then the following code will search the specific item
        if (product_ids[i] == search_id)
        {
            printf("\n=== PRODUCT FOUND ===\n");
            printf("Name: %s\n", product_names[i]);
            printf("ID: %d\n", product_ids[i]);
            printf("Quantity: %d\n", product_quantities[i]);
            printf("Price: %.2f\n", product_prices[i]);
            return;
        }
    }
    // if the product doesnot found with the specific id
    printf("Product with ID %d not found!\n", search_id);
}

void display_all_products()
{
    // checking the products are available or not
    if (total_products == 0)
    {
        printf("No products found in the system!\n");
        return;
    }

    printf("\n=== ALL PRODUCTS ===\n");
    printf("%-20s %-10s %-10s %-10s\n", "NAME", "ID", "QUANTITY", "PRICE");
    printf("--------------------------------------------------------\n");

    // displaying all the products using a for loop and also check the number of total products
    for (int i = 0; i < total_products; i++)
    {
        printf("%-20s %-10d %-10d %-10.2f\n",
               product_names[i],
               product_ids[i],
               product_quantities[i],
               product_prices[i]);
    }
}
void admin_logout()
{
    printf("Loging Out of the system");
}