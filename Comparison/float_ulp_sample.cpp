// Adapted from std::nextafter sample

#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
  for (float current_value = 10.0f, next_value, dist_to_next;
       (dist_to_next = (next_value = std::nextafter(current_value, +INFINITY)) -
                       current_value) < float(10.0f);
       current_value *= float(10.0f)) {
    std::cout << "nextafter(" << std::scientific << std::setprecision(0)
              << current_value << ", INF) gives " << std::fixed
              << std::setprecision(6) << next_value
              << "; dist_to_next = " << dist_to_next << '\n';
  }

  return 0;
}