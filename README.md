# Gradient Descent Program

This is a simple C++ program that allows users to perform gradient descent on functions with either 2 or 3 parameters. The user can input the number of parameters, learning rate, and other required values to start the gradient descent computation.

## How to Use

### 1. Compile the Program
To compile the program, run the following command:
g++ main.cpp -o gradient_descent

### 2. Run the Program
After compiling, you can run the program by typing:
./gradient_descent

### 3. Input Parameters
The program will ask you to enter several values:
- **Number of parameters**: Enter `2` for a function with two parameters or `3` for a function with three parameters.
- **Learning rate**: Enter the learning rate for the gradient descent (e.g., `0.01`).
- **Maximum number of iterations**: Enter the maximum number of iterations you want the gradient descent algorithm to run (e.g., `1000`).
- **Tolerance**: Enter the stopping tolerance for the gradient magnitude (e.g., `1e-6`).

### 4. Example Output

Enter the number of parameters (2 or 3): 2 Enter the learning rate (e.g., 0.01): 0.01 Enter the maximum number of iterations: 100 Enter the tolerance for stopping (e.g., 1e-6): 1e-6 Iteration 1: Function value = 1.98 Iteration 2: Function value = 1.9602 ... Converged after 50 iterations. Optimized parameters: 0.01 0.01


### 5. Customizing the Function
You can replace the provided function definitions in the code with your own functions:
- For 2 parameters, modify the `function2Params` function.
- For 3 parameters, modify the `function3Params` function.

### 6. Notes
- The program uses a simple quadratic function as an example (`x^2 + y^2` for 2 parameters, and `x^2 + y^2 + z^2` for 3 parameters).
- You can replace these with any other differentiable function to perform gradient descent on your custom functions.
- The initial parameter values are set to `1.0`, but you can modify this in the code.

Enjoy experimenting with different functions and parameters!
