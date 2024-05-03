# supermarket-billing-system
This project is a supermarket billing system implemented in C++. It consists of two panels: an administrator panel and a buyer panel, each designed to handle specific functionalities assigned to them.

# Features
## Administrator Panel

1. Add, update, and delete products from the inventory<br>
2. View sales report<br>
3. Manage user accounts and permissions<br>

## Buyer Panel

1. Add products to the cart<br>
2. Generate bills<br>
3. View purchase history<br>

## Data Storage

Data for products, sales, and user accounts is stored in a database file. The system uses std::ifstream to read data from the database file and std::ofstream to write data to it, ensuring data integrity and security.

## How to Run

1. Clone the repository: git clone https://github.com/Bhumika2808/supermarket-billing-system.git<br>
2. Navigate to the project directory: cd supermarket-billing-system<br>
3. Compile the code: g++ main.cpp -o supermarket<br>
4. Run the executable: ./supermarket<br>

