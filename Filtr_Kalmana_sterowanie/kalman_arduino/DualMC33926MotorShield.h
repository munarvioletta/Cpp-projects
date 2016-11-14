#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <math.h>



using namespace std;

char A0 = 0;
char A1 = 0;

void delay(int d) {
    usleep(d*1000);

}
void serial_begin(int d) {}

int _numerprobki = 0;

int analogRead(int pin) {
    return (int) (512*( 1 + sin(_numerprobki++ * 3.14/180.0)));
}


class DualMC33926MotorShield {
public:
    DualMC33926MotorShield(char& M1DIR, char& M1PWM, char& M1FB, char& M2DIR, char& M2PWM, char& M2FB, char& nD2, char& nSF) {

    }

    void init() {}

    void setM2Speed(int speed) {

    }

};

class Serial {
public:
    static void begin(int b) {

    }
    static void print(char& ch) {

    }
    static void print(int i) {

    }
    static void print(float f) {

    }
    static void print(string s) {

    }

};
