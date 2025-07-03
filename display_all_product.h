void display_all_products();

void display_all_products()
{
    //checking the products are available or not
    if (total_products == 0)
    {
        printf("No products found in the system!\n");
        return;
    }

    printf("\n=== ALL PRODUCTS ===\n");
    printf("%-20s %-10s %-10s %-10s\n", "NAME", "ID", "QUANTITY", "PRICE");
    printf("--------------------------------------------------------\n");

    //displaying all the products using a for loop and also check the number of total products
    for (int i = 0; i < total_products; i++)
    {
        printf("%-20s %-10d %-10d %-10.2f\n",
               product_names[i],
               product_ids[i],
               product_quantities[i],
               product_prices[i]);
    }
}