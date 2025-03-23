#ifndef BARRIER_OPTION_H
#define BARRIER_OPTION_H

#include <vector>
#include <cmath>

class BarrierOption {
private:
    double S0;     // Initial stock price
    double K;      // Strike price
    double sigma;  // Volatility
    double r;      // Risk-free rate
    double T;      // Time to maturity
    double H;      // Barrier level
    int N;         // Number of time steps
    int M;         // Number of simulations

public:
    // Constructor
    BarrierOption(double S0, double K, double sigma, double r, double T, double H, int N, int M);

    // Method to simulate a single price path and calculate payoff
    double simulatePrice();

    // Method to calculate the option price using Monte Carlo simulation
    double priceOption();
};

#endif
