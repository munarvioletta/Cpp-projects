#!/bin/bash

# copy ino into cpp
cp kalman_arduino.ino kalman_arduino.cpp

# make cpp ready to compile on PC
sed -i 's/ s = /cout << /g' kalman_arduino.cpp
sed -i 's/ s += /cout << /g' kalman_arduino.cpp
sed -i 's/Serial\.print(s);//g' kalman_arduino.cpp
sed -i 's/Serial\.print/cout << /g' kalman_arduino.cpp
sed -i 's/String/string/g' kalman_arduino.cpp
sed -i 's/Serial\.begin/cout << "u e r y y_kal" << /g' kalman_arduino.cpp

echo "int main() { setup(); while(1) { loop(); } return 0; }" >> kalman_arduino.cpp


# compile cpp
g++ kalman_arduino.cpp -o kalman_arduino

# generate asm code
#g++ -S -masm=intel kalman_arduino.cpp

# remove cpp
rm kalman_arduino.cpp
