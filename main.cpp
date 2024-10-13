#include <iostream>
#include <vector>
#include <cmath>

// Function declarations
double function2Params(const std::vector<double>& params);
double function3Params(const std::vector<double>& params);
std::vector<double> computeGradient2Params(const std::vector<double>& params);
std::vector<double> computeGradient3Params(const std::vector<double>& params);
void gradientDescent(int numParams, double learningRate, int maxIterations, double tolerance);

int main() {
    int numParams;
    double learningRate;
    int maxIterations;
    double tolerance;

    // User inputs
    std::cout << "Enter the number of parameters (2 or 3): ";
    std::cin >> numParams;

    if (numParams != 2 && numParams != 3) {
        std::cout << "Invalid number of parameters. Must be 2 or 3." << std::endl;
        return -1;
    }

    std::cout << "Enter the learning rate (e.g., 0.01): ";
    std::cin >> learningRate;

    std::cout << "Enter the maximum number of iterations: ";
    std::cin >> maxIterations;

    std::cout << "Enter the tolerance for stopping (e.g., 1e-6): ";
    std::cin >> tolerance;

    // Start gradient descent
    gradientDescent(numParams, learningRate, maxIterations, tolerance);

    return 0;
}

// Function for 2 parameters (you can replace this with your actual function)
double function2Params(const std::vector<double>& params) {
    return pow(params[0], 2) + pow(params[1], 2); // Example: f(x, y) = x^2 + y^2
}

// Function for 3 parameters (you can replace this with your actual function)
double function3Params(const std::vector<double>& params) {
    return pow(params[0], 2) + pow(params[1], 2) + pow(params[2], 2); // Example: f(x, y, z) = x^2 + y^2 + z^2
}

// Gradient of the function with 2 parameters
std::vector<double> computeGradient2Params(const std::vector<double>& params) {
    return {2 * params[0], 2 * params[1]}; // Gradient: [2x, 2y]
}

// Gradient of the function with 3 parameters
std::vector<double> computeGradient3Params(const std::vector<double>& params) {
    return {2 * params[0], 2 * params[1], 2 * params[2]}; // Gradient: [2x, 2y, 2z]
}

// Gradient Descent Algorithm
void gradientDescent(int numParams, double learningRate, int maxIterations, double tolerance) {
    std::vector<double> params(numParams, 1.0); // Initial values for the parameters

    for (int iter = 0; iter < maxIterations; ++iter) {
        std::vector<double> gradient;

        if (numParams == 2) {
            gradient = computeGradient2Params(params);
        } else {
            gradient = computeGradient3Params(params);
        }

        // Update parameters based on the gradient
        for (int i = 0; i < numParams; ++i) {
            params[i] -= learningRate * gradient[i];
        }

        // Compute the function value to check for convergence
        double value;
        if (numParams == 2) {
            value = function2Params(params);
        } else {
            value = function3Params(params);
        }

        std::cout << "Iteration " << iter + 1 << ": Function value = " << value << std::endl;

        // Check for convergence
        double gradientMagnitude = 0;
        for (double g : gradient) {
            gradientMagnitude += g * g;
        }
        gradientMagnitude = sqrt(gradientMagnitude);

        if (gradientMagnitude < tolerance) {
            std::cout << "Converged after " << iter + 1 << " iterations." << std::endl;
            break;
        }
    }

    std::cout << "Optimized parameters: ";
    for (double p : params) {
        std::cout << p << " ";
    }
    std::cout << std::endl;
}
