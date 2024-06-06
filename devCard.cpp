#include <iostream>
using namespace std;
class devCard {
public:
    // Pure virtual function making this class abstract
    virtual void somePureVirtualFunction() = 0;
    virtual ~devCard() = default;      // Virtual destructor
};
class knight : public devCard {
        virtual void somePureVirtualFunction(){
            cout << "Knight" << endl;
        }

};
class twoRoadBuilding : public devCard {
        virtual void somePureVirtualFunction(){
            cout << "Two Road Building" << endl;
        }

};
class yearOfPlenty : public devCard {
        virtual void somePureVirtualFunction(){
            cout << "Year Of Plenty" << endl;
        }

};
class monopoly : public devCard {
        virtual void somePureVirtualFunction(){
            cout << "Monopoly" << endl;
        }

};
class victoryPoint : public devCard {
        virtual void somePureVirtualFunction(){
            cout << "Victory Point" << endl;
        }

};