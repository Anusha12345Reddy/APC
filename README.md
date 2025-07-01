# APC

📘 **Arbitrary Precision Calculator (APC) Project – Explanation**

The Arbitrary Precision Calculator (APC) is a command-line application written in C that performs arithmetic operations on numbers far larger than those natively supported by standard data types like `int`, `long`, or `double`. The core purpose of this project is to emulate calculator functionality for extremely large integers with arbitrary length, achieving mathematical accuracy without overflow.

Internally, each large number is stored as a doubly linked list, with each node representing a single digit. This allows the calculator to process and store numbers of virtually unlimited size, overcoming the limitations of fixed-width integer types. The operations supported include:

- Addition
- Subtraction
- Multiplication
- Division (for integer results)

Users input the operations in a custom syntax via the terminal (e.g., `12345678901234567890 + 98765432109876543210`) and the calculator parses the numbers and operator, performs the computation digit-by-digit, and prints the precise result without any loss of data.

The logic is fully modular, separating parsing, arithmetic, and linked list management into distinct components. This enhances maintainability and readability while demonstrating a clear understanding of data structure manipulation and algorithmic problem-solving.

### 🔹 What This Project Showcases:

- Strong grasp of data structures (especially doubly linked lists)
- Mastery of arithmetic algorithm implementation at the digit level
- Real-world simulation of calculator logic for non-native data sizes
- Clean modular C programming, input validation, and robust parsing
