#include "BarrierOption.h"
#include <random>
#include <algorithm> // for std::max

BarrierOption::BarrierOption(double S0, double K, double sigma, double r, double T, double H, int N, int M)
    : S0(S0), K(K), sigma(sigma), r(r), T(T), H(H), N(N), M(M) {}

double BarrierOption::simulatePrice() {
    double dt = T / N;
    double S = S0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);

    for (int i = 0; i < N; ++i) {
        double Z = d(gen);
        S *= exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z);
        if (S > H) return 0.0; // Knocked out
    }
    return std::max(S - K, 0.0);
}

double BarrierOption::priceOption() {
    double payoffSum = 0.0;

    for (int i = 0; i < M; ++i) {
        payoffSum += simulatePrice();
    }

    return exp(-r * T) * (payoffSum / M);
}
