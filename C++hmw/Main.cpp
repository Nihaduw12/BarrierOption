#include <iostream>
#include "BarrierOption.h"

int main() {
    // Variables to hold user input
    double S0, K, sigma, r, T, H;
    int N, M;

    // Get user input for the parameters
    std::cout << "Enter the initial stock price (S0): ";
    std::cin >> S0;
    std::cout << "Enter the strike price (K): ";
    std::cin >> K;
    std::cout << "Enter the volatility (sigma) as a decimal (e.g., 0.25 for 25%): ";
    std::cin >> sigma;
    std::cout << "Enter the risk-free rate (r) as a decimal (e.g., 0.05 for 5%): ";
    std::cin >> r;
    std::cout << "Enter the time to maturity (T) in years: ";
    std::cin >> T;
    std::cout << "Enter the barrier level (H): ";
    std::cin >> H;
    std::cout << "Enter the number of time steps (N): ";
    std::cin >> N;
    std::cout << "Enter the number of simulations (M): ";
    std::cin >> M;

    // Create the barrier option object
    BarrierOption option(S0, K, sigma, r, T, H, N, M);

    // Price the option
    double price = option.priceOption();
    std::cout << "Up-and-Out Barrier Call Option Price: " << price << std::endl;

    return 0;
}
