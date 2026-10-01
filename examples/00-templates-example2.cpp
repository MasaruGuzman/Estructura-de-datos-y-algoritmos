//Example templates

// Repasar este tema, porque no estaba poniendo atencion la clase pasada
#include <iostream>
#include <string>
#include <cmath>

template <typename T>
T maximum(T a, T b) {
    if (a > b) return a;
    else return b;
}

class Point{
    public: 
        Point(double x, double y) : x_{x}, y_{y} {}   
        
        bool operator>(Point &other){
            double normThis = std::sqrt( x_* x_ + y_ * y_ );
            double normOther = std::sqrt( other.x_ * other.x_ +
                                         other.y_ * other.y_ );
            
            if (normThis > normOther){
                return true;
            }
            else{
                return false;
            }

        }
        
        friend std::ostream& operator<<(std::ostream &out, const Point &p){
            out << "(" << p.x_ << "," << p.y_ << ")";
            return out;
        }

    private:
        double x_;
        double y_;
};



int main(){
    int res;
    res = maximum(2, 3);
    std::cout << "Maximum " << res << std::endl; 

    double resD = maximum(2.5, 2.6);
    std::cout << "Maximum " << resD << std::endl; 

    std::string resS = maximum(std::string("abeja"), std::string("zorro"));
    std::cout << "Maximum " << resS << std::endl; 

    // Custom data type
    Point point1 = Point(2.5, 2.6);
    Point point2 = Point(4.5, 2.6);
    Point resPoint = maximum(point1, point2);
    std::cout << "Maximum " << resPoint << std::endl;
}
