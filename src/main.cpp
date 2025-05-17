#include "Car.hpp"
#include <algorithm>
#include <deque>
#include <vector>

int main(){
    Car car1("Volga", 10, 15, 12, 112, 5000);
    Car car2("Moskvich", 5, 12, 7, 100, 2000);
    Car car3("Zhiguli", 5, 17, 8, 100, 2500);
    Car car4("Mers", 15, 20, 18, 100, 9000);
    Car car5("Zhuck", 2, 6, 5, 100, 200);

    std::deque<Car> cars_deque = {car1, car2, car3, car4, car5};
    std::vector<Car> cars_vector (cars_deque.begin(), cars_deque.end());

    std::cout << "Cars in deque:" << std::endl;
    for(auto car : cars_deque){
        std::cout << car << std::endl;
    }
    std::cout << "Cars in vector: " << std::endl;
    for(auto car: cars_vector){
        std::cout << car << std::endl;
    }
    std::sort(cars_vector.begin(), cars_vector.end());

    std::cout << "Sorted cars in vector: " << std::endl;
    for(auto car: cars_vector){
        std::cout << car << std::endl;
    }
}
