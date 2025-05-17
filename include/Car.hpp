#include <ostream>
#include <string>
#include <iostream>

class Car{
private:
    std::string model_name;
    float fuel_consumption[3];
    float max_speed;
    float power;

public:
    Car():model_name(""), fuel_consumption{0,0,0}, max_speed(0), power(0){};
    
    Car(std::string name, 
        float road_fc, 
        float citu_fc, 
        float average_fc, 
        float max_speed, 
        float power):
        model_name(name), 
        fuel_consumption{road_fc, citu_fc, average_fc}, 
        max_speed(max_speed), 
        power(power) {}
    
    Car(const Car& other){
        model_name = other.model_name;
        std::copy(std::begin(other.fuel_consumption), std::end(other.fuel_consumption), fuel_consumption);
        max_speed = other.max_speed;
        power = other.power;
    }

    Car& operator=(const Car& other){
        if(this != &other){
            model_name = other.model_name;
            std::copy(std::begin(other.fuel_consumption), std::end(other.fuel_consumption), fuel_consumption);
            max_speed = other.max_speed;
            power = other.power;
        }
        return *this;
    }

    Car(Car&& other) noexcept : model_name(std::move(other.model_name)), max_speed(other.max_speed), power(other.power){
        std::copy(std::begin(other.fuel_consumption), std::end(other.fuel_consumption), std::begin(fuel_consumption));
        other.max_speed = 0.0f;
        other.power = 0.0f;
        std::fill(std::begin(other.fuel_consumption), std::end(other.fuel_consumption), 0.0f);
    }

    bool operator<(const Car& other) const{
        return fuel_consumption[2] < other.fuel_consumption[2];
    }

    friend std::ostream& operator<< (std::ostream& stream, const Car& car);
};

std::ostream& operator<< (std::ostream& stream, const Car& car){
    stream << "<Car ";
    stream << "model_name = " << car.model_name;
    stream << " fuel_consumption = [" << car.fuel_consumption[0] << ", " << car.fuel_consumption[1] << ", " << car.fuel_consumption[2] << "]";
    stream << " max_speed = " << car.max_speed;
    stream << " power = " << car.power;
    stream << ">";
    return stream;
}