/*
    Darrius White (Z1900146)
    Assignment 5
    10/11/2021
*/
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <stack>
#include <algorithm>


class car
{
public:
    car(int id, const std::string &license) : id(id), license(license) {}

    /// Call this to increment the numbner of times the car has been moved.
    void move() { ++num_moves; }

    /// @return the number of times that the car has been moved.
    int get_num_moves() const { return num_moves; }

    /// @return A reference to the license for this car.
    const std::string &get_license() const { return license; }

    /// Overload the << so this can print itself.
    friend std::ostream& operator<<(std::ostream& lhs, const car& rhs)
    {
        lhs << "Car " << rhs.id << " with license plate \"" << rhs.license << "\"";
        return lhs;
    }

private:
    int id;                 ///< The ID number for this car (assigned by the garage)
    std::string license;    ///< license plate of this car.
    int num_moves = {0};    ///< how many times the car was moved within the garage.
};


class garage
{
public:
        garage(size_t limit = 10) : parking_lot_limit(limit) {}

        /// @param license The license of the car that has arrived.
        void arrival(const std::string &license)
        {
            car car(next_car_id, license);//new car arrives to lot

            std::cout << car << " has arrived.\n";//stating the car has arrived

            //if parking lot is full
            if (parking_lot.size() == parking_lot_limit)
                std::cout << "    But the garage is full!\n";

            else if (parking_lot.size() != parking_lot_limit)//add car to the parking lot deque if not full
            {
                parking_lot.push_back(car);//car enters parking lot
                next_car_id++;
            }
        }

        /// @param license The license of the car that has departed.
        void departure(const std::string &license)
        {
            std::stack<car> temp_garage;//stack to store cars in a temp garage

            size_t i = 0;

            //loop through parking lot to find car departing
            while (parking_lot.size() != 0)
            {
                //if not the car departing then it gets pushed to the temp garage stack
                if (parking_lot[i].get_license() != license)
                {
                   parking_lot[i].move();//adding to number of moves for specific car
                   temp_garage.push(parking_lot[i]);//pushing car to temp garage stack
                   parking_lot.pop_front();//removing car from parking lot starting from closest to exit
                }


                //if license plate is found
                else if (parking_lot[i].get_license() == license)
                {
                   std::cout << parking_lot[i] << " has departed," << std::endl;//printing the car thats departing

                   parking_lot[i].move();//adding to number of moves for departing car

                   if(parking_lot[i].get_num_moves() == 1)
                        std::cout << "    car was moved " << parking_lot[i].get_num_moves() << " time in the garage." << std::endl;

                   else if(parking_lot[i].get_num_moves() > 1)
                        std::cout << "    car was moved " << parking_lot[i].get_num_moves() << " times in the garage." << std::endl;

                   parking_lot.pop_front();//removing the car thats departing



                   //moving cars back into parking lot from temp garage
                   if (!temp_garage.empty()){
                      if(temp_garage.size() > 1)
                      {
                         for (size_t j = 0; j < temp_garage.size(); j++)
                         {
                             parking_lot.push_front(temp_garage.top());//push car bakc into parking lot
                             temp_garage.pop();//pop from the temp_garage stack what was inserted into the parking lot deque
                         }
                      }
                      parking_lot.push_front(temp_garage.top());
                      temp_garage.pop();
                   }
                   break;
                }
                //if license plate still isnt found
                if(parking_lot.empty())
                {
                   std::cout << "No car with license plate \"" << license << "\" is in the garage." << std::endl;
                   break;
                }
            }

        }

private:
        int next_car_id = { 1 };
        std::deque<car> parking_lot;
        size_t parking_lot_limit;
};



void get_input_vals(const std::string &line, char &xact_type, std::string &license)
{
    //using a garage object, process an arrival or
    //departure based on the value of the transaction code
    std::string s = line;
    std::string delimiter = ":";
    size_t pos = 0;
    std::string token;
    int count = 0;

    //parsing through string locating the delimiter and separating the string
    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        token = s.substr(0, pos);

        if (count == 0)
        {
            xact_type = token[0];
            count++;
        }
        else
        {
            license = token;
            count--;
        }

        s.erase(0, pos + delimiter.length());
    }
}


int main()
{
    //read transaction records from stdin
    std::string input_line, license;
    char act;
    std::ifstream infile("parking.in");
    garage garage_act;

    if (!infile)
    {
        std::cerr << "File failed to open\n";
        exit(1);
    }

    //and parse them by calling get_input_vals()
    while (getline(std::cin, input_line, '\n'))//each input line
    {
        get_input_vals(input_line, act, license);//parse

        if (act == 'D')//departure
        {
            garage_act.departure(license);
            std::cout << std::endl;
        }
        else if (act == 'A')//arrival
        {
            garage_act.arrival(license);
            std::cout << std::endl;
        }
        else
        {
            std::cout << "'" << act << "': "<< "invalid action!" << std::endl;
            std::cout << std::endl;
        }
    }


    infile.close();
    return 0;
}
