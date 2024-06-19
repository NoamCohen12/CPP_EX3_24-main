
#include <iostream>
#include <string>
using namespace std;

class devCard {
public:
    // Pure virtual function making this class abstract
    virtual string type() const = 0;
    virtual void use_card() = 0;
    virtual ~devCard() = default;      // Virtual destructor
};
class knight : public devCard {
    public:
        virtual void use_card(){
            cout << "used Knight decCard" << endl;
        }
        virtual string type() const {
            return "Knight";
        }

};
class road_building : public devCard {
       public: 
        virtual void use_card(){
            cout << "Two Road Building" << endl;
        }
        virtual string type() const {
            return "Two Road Building";
        }

};
class year_of_plenty : public devCard {
    public:
        virtual void use_card(){
            cout << "Year Of Plenty" << endl;
        }
        virtual string type() const {
            return "Year Of Plenty";
        }

};
class monopoly : public devCard {
    public:
        virtual void use_card(){
            cout << "Monopoly" << endl;
        }
        virtual string type() const {
            return "Monopoly";
        }

};
class victory_point : public devCard {
    public:
        virtual void use_card(){
            cout << "Victory Point" << endl;
        }
        virtual string type() const {
            return "Victory Point";
        }

};