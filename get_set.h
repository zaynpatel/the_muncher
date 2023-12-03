#include <iostream>
using namespace std;

// Drill Control
#ifndef DRILL_CONTROL_H // checks if this class is not defined and defines it in next line if not
#define DRILL_CONTROL_H

class DrillControl {

// these are the variables we don't want to be accessed by members of the class unless called via get() and set() specifically.
private:
    unsigned int drillPWM;

public:
    static const unsigned int MIN_PWM = 51; // allows any part of code with DrillControl() to access these values
    static const unsigned int MAX_PWM = 204;
    DrillControl() : drillPWM(0) {} // Constructor to initialize drillPWM. Supposedly it's defined this way for init of member variables in one line.
    
    // Getter for drillPWM (what are the fundamentals of getters - what properties do we want this to have when we write it?)
    unsigned int getDrillPWM() const {
        return drillPWM;
    }
    // defining the minimum and maximum value(s) here in case we want to retrieve these later on
    static unsigned int getMinPWM() {return MIN_PWM; } 
    static unsigned int getMaxPWM() {return MAX_PWM; }

    
    void setDrillPWM(unsigned int pwmValue) {
        if (pwmValue < MIN_PWM) {
            drillPWM = MIN_PWM;
        } else if (pwmValue > MAX_PWM) {
            drillPWM = MAX_PWM;
        } else {
            drillPWM = pwmValue;
        }
    }
};

#endif 


// Limit Switches
#ifndef LIMIT_SWITCHES_H
#define LIMIT_SWITCHES_H

class LimitSwitches {
private:
    bool limitSwitch; // I want this limit switch to be value 0 or 1, corresponding to touched or not touched (This will sync with Arduino so would be good to figure out integration)

public:
    LimitSwitches() : limitSwitch(false) {} // can't forget this step! init the limitSwitch value to false meaning untouched
    
    // using the & to pass the string "by reference", right?
    void updateFromSerialData(const std::string& data) {
        if (data.find("UNTOUCHED") != std::string::npos) {
            limitSwitch = false;
            std::cout << "The limit switch is not touched." << std::endl;
        } else if (data.find("TOUCHED") != std::string::npos) {
            limitSwitch = true;
            std::cout << "The limit switch is touched." << std::endl;
        }
    }
    bool getLimitSwitch() const {return limitSwitch; } // using const here because this indicates I don't want to change the state of LimitSwitches object

};

#endif 

#ifndef SOLINOIDS_H
#define SOLINOIDS_H

class Solinoids {
private:
    bool solinoidState;

public:
    // modeled after the LimitSwitches class instance - init this state to false since it won't be activated when the drill arm starts
    Solinoids() : solinoidState(false) {}
   
   // call the limit switch function because we want to know if we're in the starting position or not
    limitSwitch.updateFromSerialData(&data)


    // we want to get the state after we parse it from the serial connection via Arduino
    bool getSolinoidState() const {return solinoidState; }

};
