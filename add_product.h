#include <stdio.h>
#include <string.h>
void add_new_product();

// Declaring Global Arrays to store items
char product_names[100][100]; // Storing names upto 100
int product_ids[100];         // Storing id's upto 100
int product_quantities[100];  // Storing Quantities Upto 100
float product_prices[100];    // Storing 100 Prices
int total_products = 0;       // Counter for the products

void add_new_product()
{
    // Checking if we have space for more products
    if (total_products >= 100)
    {
        printf("Storage full! Cannot add more products.\n");
        return;
    }

    //declaring variales for getting product name,id,quantity and price from the admin
    char temp_name[100];
    int temp_id, temp_quantity;
    float temp_price;

    //Taking inputs from admin
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

    //Saving the product details in the arrays 
    strcpy(product_names[total_products], temp_name);
    product_ids[total_products] = temp_id;
    product_quantities[total_products] = temp_quantity;
    product_prices[total_products] = temp_price;

    //Counter for incrementing the product
    total_products++;

    
    //Displaying the data which is entered
    printf("\n=== Product Added Successfully! ===\n");
    printf("Name: %s\n", temp_name);
    printf("ID: %d\n", temp_id);
    printf("Quantity: %d\n", temp_quantity);
    printf("Price: %.2f\n", temp_price);
    printf("Total products in system: %d\n", total_products);
}
