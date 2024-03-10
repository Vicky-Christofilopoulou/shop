# shop

We have a specific amount of money available, denoted as M, and we want to purchase N products with it. For each product i (1 ≤ i ≤ N), there are Ki available model choices, each costing Cij (1 ≤ j ≤ Ki, Cij > 0). For example, let's say we have 500 euros available and want to buy a computer, a printer, and an external hard drive, trying to spend as much money as possible. Suppose we have three options for the computer (HP, Dell, Asus), two options for the printer (Epson, Lexmark), and four options for the external hard drive (Seagate, Samsung, Maxtor, Toshiba). For each possible model of the products we want to buy, we know its cost. What is the maximum amount we can spend, up to M, to buy one model for each of the N products?

Example:
M = 20, N = 3
Product 1: K1 = 3, C11 = 8, C12 = 5, C13 = 9
Product 2: K2 = 2, C21 = 11, C22 = 4
Product 3: K3 = 4, C31 = 9, C32 = 5, C33 = 10, C34 = 3

For the above example, a solution is to buy the models costing C12 = 5, C21 = 11, and C34 = 3, resulting in a total cost of 19. Note that there is no combination of models that gives a total cost of 20, allowing us to spend the entire available amount. Another solution with the same total cost is the combination 5/4/10.

1. The recursive method
2. Recursive method with memoization
3. Iterative method with dynamic programming

