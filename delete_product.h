void delete_product_by_id();

void delete_product_by_id()
{
    //checking if there is product available or not
    if (total_products == 0)
    {
        printf("No products in the system to delete!\n");
        return;
    }
    //declaring variable for deleting product using id
    int delete_id;
    //taking id as an input
    printf("Enter product ID to delete: ");
    scanf("%d", &delete_id);
    
    //loop which will will check total product
    for (int i = 0; i < total_products; i++)
    {
        //validating product id should be equal to delete id so the idem should be deletable
        if (product_ids[i] == delete_id)
        {
            printf("Deleting product: %s (ID: %d)\n", product_names[i], product_ids[i]);

            //shifting all the product afters the deleted item gap to fill it
            for (int j = i; j < total_products - 1; j++)
            {
                strcpy(product_names[j], product_names[j + 1]);
                product_ids[j] = product_ids[j + 1];
                product_quantities[j] = product_quantities[j + 1];
                product_prices[j] = product_prices[j + 1];
            }
            //incrementing the total_product array size
            total_products--;
            //printing messages for confirmation and remaining products
            printf("Product deleted successfully!\n");
            printf("Total products remaining: %d\n", total_products);
            return;
        }
    }

    printf("Product with ID %d not found!\n", delete_id);
}
