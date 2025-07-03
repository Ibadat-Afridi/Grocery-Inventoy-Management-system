void search_product_by_id();

void search_product_by_id()
{
  //checking if there are product available to be searched
  if (total_products == 0)
  {
    printf("No products in the system to search!\n");
    return;
  }
//declaring variable search id for getting the id of item to be search
  int search_id;
  //taking search id as an input
  printf("Enter product ID to search: ");
  scanf("%d", &search_id);

  //loop for searching 
  for (int i = 0; i < total_products; i++)
  {
    //condition if product id is equal to search id then the following code will search the specific item
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
  //if the product doesnot found with the specific id
  printf("Product with ID %d not found!\n", search_id);
}
