# Grocery Inventory Management System

A simple command-line based grocery inventory management system written in C that allows administrators to manage grocery items through basic CRUD operations.

## Team Information

**Group Members:**
- Ibadat Ullah
- Habib Ullah

**Instructor:** M. Adil Khan

**Course:** Programming Fundamentals

**Institution:** COMSATS University Islamabad, Abbottabad Campus

**Project Type:** Semester Project

---

*This semester project was developed as part of our Programming Fundamentals course at COMSATS University Islamabad, Abbottabad Campus, demonstrating practical application of C programming concepts in real-world grocery inventory management scenarios.*

## Features

- **Admin Authentication**: Secure login system with predefined admin credentials
- **Grocery Item Management**: Add, delete, search, and display grocery items
- **Data Validation**: Prevents duplicate item IDs and validates input
- **Memory-based Storage**: Stores up to 100 grocery items in runtime memory
- **Modular Design**: Well-organized code with separate header files for each functionality

## System Requirements

- C Compiler (GCC recommended)
- Operating System: Windows, Linux, or macOS
- Terminal/Command Prompt access

## Project Structure

```
project/
├── main.c                    # Main program entry point
├── Version 2/
│   └── main2.c              # Alternative main implementation
├── login.h                  # Admin authentication module
├── view_home_page.h         # Home menu display module
├── add_product.h            # Grocery item addition functionality
├── delete_product.h         # Grocery item deletion functionality
├── search_product.h         # Grocery item search functionality
├── display_all_product.h    # Display all grocery items functionality
└── logout.h                 # Logout functionality
```

## Installation & Setup

1. **Clone or download the project files**
2. **Compile the program**:
   ```bash
   gcc -o grocery_management main.c
   ```
   
   Or for the alternative version:
   ```bash
   gcc -o grocery_management_v2 "Version 2/main2.c"
   ```

3. **Run the executable**:
   ```bash
   ./grocery_management
   ```

## Usage

### Admin Login
The system supports two predefined admin accounts:
- **Username**: `ibadat`, **Password**: `12345`
- **Username**: `habib`, **Password**: `67890`

**Note**: After 4 failed login attempts, the system will block access.

### Main Menu Options

Once logged in, you'll see the following menu:

```
===== Home Menu =====
1. Add Product
2. Delete Product
3. Search Product
4. Display All Products
5. Logout
======================
```

### 1. Add Product
- Enter grocery item name, ID, quantity, and price
- System validates that the item ID doesn't already exist
- Maximum storage capacity: 100 grocery items

### 2. Delete Product
- Enter the grocery item ID to delete
- System confirms deletion and shifts remaining items
- Displays updated item count

### 3. Search Product
- Enter grocery item ID to search
- Displays complete item information if found
- Shows error message if item doesn't exist

### 4. Display All Products
- Shows all grocery items in a formatted table
- Includes Name, ID, Quantity, and Price columns
- Displays message if no items are stored

### 5. Logout
- Safely exits the system
- Displays logout confirmation message

## Code Structure

### Data Storage
The system uses global arrays to store grocery item information:
- `product_names[100][100]`: Grocery item names
- `product_ids[100]`: Grocery item IDs
- `product_quantities[100]`: Grocery item quantities
- `product_prices[100]`: Grocery item prices
- `total_products`: Counter for total grocery items

### Key Functions

| Function | Purpose |
|----------|---------|
| `admin_login()` | Handles admin authentication |
| `view_home()` | Displays main menu |
| `add_new_product()` | Adds new grocery items to inventory |
| `delete_product_by_id()` | Removes grocery items by ID |
| `search_product_by_id()` | Searches for specific grocery items |
| `display_all_products()` | Shows all stored grocery items |
| `admin_logout()` | Handles system logout |

## Limitations

- **Memory Storage**: Data is stored in RAM and lost when program terminates
- **Item Limit**: Maximum 100 grocery items can be stored
- **No File Persistence**: No data saving to files
- **Fixed Admin Credentials**: Admin usernames and passwords are hardcoded
- **Basic Input Validation**: Limited input sanitization

## Future Enhancements

- [ ] File-based data persistence
- [ ] Dynamic memory allocation for unlimited grocery items
- [ ] User registration and management
- [ ] Grocery item categories and advanced search
- [ ] Data export/import functionality
- [ ] GUI interface
- [ ] Database integration

## Security Considerations

- Admin credentials are hardcoded in source code
- No password encryption
- Limited input validation
- Suitable for educational purposes only

## Example Usage

```
Enter admin username: ibadat
Enter admin password: 12345
Access Granted to Admin Panel

===== Home Menu =====
1. Add Product
2. Delete Product
3. Search Product
4. Display All Products
5. Logout
======================
Choice: 1

Enter the product name: Laptop
Enter the product ID: 101
Enter the product quantity: 5
Enter the product price: 999.99

=== Product Added Successfully! ===
Name: Laptop
ID: 101
Quantity: 5
Price: 999.99
Total products in system: 1
```

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

## License

This project is created for educational purposes. Feel free to use and modify as needed.

## Support

For questions or issues, please review the code comments or create an issue in the repository.

---

**Note**: This is a learning project demonstrating basic C programming concepts including structures, arrays, functions, and modular programming for grocery inventory management.
