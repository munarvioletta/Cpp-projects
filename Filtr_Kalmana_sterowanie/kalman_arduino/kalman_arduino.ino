#include "DualMC33926MotorShield.h"

// Matrixx class
class Matrixx {
public:
    float** mat;
    int rowNum;
    int colNum;

    // constructor with 3 params
    Matrixx(int nRows, int nCols, float fill) {
        rowNum = nRows;
        colNum = nCols;

        mat = new float*[rowNum];

        for(int r = 0; r < rowNum; r++) {
            mat[r] = new float[colNum];
            for(int c = 0; c < colNum; c++) {
                mat[r][c] = fill;
            }
        }
    }

    // constructor with 2 params redirected to const. with 3 params, one specified
    Matrixx(int nRows, int nCols) : Matrixx(nRows, nCols, 0.0) {}

    // empty constructor
    Matrixx() {}

    // destructor
     ~Matrixx() {
         for(int r = 0; r < rowNum; r++) {
             delete[] mat[r];
         }

         delete[] mat;
     }


    // print this Matrixx
    void print() {
        for (int r = 0; r < rowNum; r++) {
            for (int c = 0; c < colNum; c++) {
                //printf("%f\n", mat[r][c]);
                Serial.print(mat[r][c]); Serial.print("\t");
            }
            Serial.print("\n");
        }
        Serial.print("\n");
    }

    Matrixx* copy() {
        Matrixx* copy = new Matrixx(rowNum, colNum);

        for (int r = 0; r < rowNum; r++) {
            for (int c = 0; c < colNum; c++) {
                copy->mat[c][r] = mat[c][r];
            }
        }

        return copy;
    }


    // multiply this Matrixx by Matrixx B
    Matrixx* multiply(Matrixx* matB) { // C = A*B
        Matrixx* matC = new Matrixx(rowNum, matB->colNum);

        for (int r = 0; r < rowNum; r++) {
            for (int c = 0; c < matB->colNum; c++) {
                for (int i = 0; i < colNum; i++) {
                    matC->mat[r][c] += mat[r][i]*matB->mat[i][c];
                }
            }
        }

        return matC;
    }

    // multiply this Matrixx by float/integer
    // template<typename T> // not needed anymore
    Matrixx* multiply(float k) {
        Matrixx* matC = new Matrixx(rowNum, colNum);

        for (int r = 0; r < rowNum; r++) {
            for (int c = 0; c < colNum; c++) {
                matC->mat[r][c] = mat[r][c] * k;
            }
        }

        return matC;
    }

    // transpose this Matrixx
    Matrixx* transpose() {
        Matrixx* matC = new Matrixx(colNum, rowNum);

        for (int r = 0; r < rowNum; r++) {
            for (int c = 0; c < colNum; c++) {
                matC->mat[c][r] = mat[r][c];
            }
        }

        return matC;
    }

    // add
    Matrixx* add(Matrixx* matB) {
        Matrixx* matC = new Matrixx(rowNum, colNum);

        for (int r = 0; r < rowNum; r++) {
            for (int c = 0; c < colNum; c++) {
                matC->mat[c][r] = mat[c][r] + matB->mat[c][r];
            }
        }

        return matC;
    }

    // subtract Matrixx B from this Matrixx
    Matrixx* subtract(Matrixx* matB) {
        Matrixx* matC = new Matrixx(rowNum, colNum);

        for (int r = 0; r < rowNum; r++) {
            for (int c = 0; c < colNum; c++) {
                matC->mat[c][r] = mat[c][r] - matB->mat[c][r];
            }
        }

        return matC;
    }

    // inverse of this Matrixx
    Matrixx* inverse() { // this handles 1x1 matricies only
        Matrixx* matC = new Matrixx(rowNum, colNum, 0);

        if ( rowNum == 1 && colNum == 1 )
            matC->mat[0][0] = 1/mat[0][0]; // simple inv for 1x1 Matrixx
        else if ( (rowNum == 2) && (colNum = 2) )
            Serial.print("Matrixx.inv() not implemented for given Matrixx size: 2x2"); // TODO: implement for size 2x2
        else
            Serial.print("Matrixx.inv() not implemented for given Matrixx size: nxn"); // TODO: implement for size nxn, n>2

        return matC;
    }
};


class Kalman {
public:
    Matrixx* A;
    Matrixx* B;
    Matrixx* H;
    Matrixx* current_state_estimate;
    Matrixx* current_prob_estimate;
    Matrixx* Q;
    Matrixx* R;

    Matrixx* predicted_state_estimate;
    Matrixx* predicted_prob_estimate;
    Matrixx* innovation;
    Matrixx* innovation_covariance;
    Matrixx* kalman_gain;


    Kalman(Matrixx* AA, Matrixx* BB, Matrixx* HH, Matrixx* xx, Matrixx* PP, Matrixx* QQ, Matrixx* RR) {
        A = AA;
        B = BB;
        H = HH;
        current_state_estimate = xx;
        current_prob_estimate = PP;
        Q = QQ;
        R = RR;
    }

    float getCurrentState() {
        return current_state_estimate->mat[0][0];
    }

    void step(Matrixx* control_vector, Matrixx* measurement_vector) {

        Matrixx* A_CSE = A->multiply(current_state_estimate);  Matrixx* B_CV = B->multiply(control_vector);
        delete predicted_state_estimate; predicted_state_estimate = A_CSE->add(B_CV);
        delete A_CSE; delete B_CV;

        Matrixx* A_CPE = A->multiply(current_prob_estimate); Matrixx* AT = A->transpose(); Matrixx* ACPE_AT = A_CPE->multiply(AT);
        delete predicted_prob_estimate; predicted_prob_estimate = ACPE_AT->add(Q);
        delete A_CPE; delete AT; delete ACPE_AT;

        //     #--------------------------Observation step-----------------------------
        Matrixx* H_PSE = H->multiply(predicted_state_estimate);
        delete innovation; innovation = measurement_vector->subtract(H_PSE);
        delete H_PSE;

        Matrixx* HT = H->transpose(); Matrixx* H_PPE = H->multiply(predicted_prob_estimate); Matrixx* HPPE_HT = H_PPE->multiply(HT);
        delete innovation_covariance; innovation_covariance = HPPE_HT->add(R);
        delete HT; delete H_PPE; delete HPPE_HT;

        //     #-----------------------------Update step-------------------------------
        HT = H->transpose(); Matrixx* ICI = innovation_covariance->inverse(); Matrixx* PPE_HT = predicted_prob_estimate->multiply(HT);
        delete kalman_gain; kalman_gain = PPE_HT->multiply(ICI);
        delete HT; delete ICI; delete PPE_HT;

        Matrixx* KG_I = kalman_gain->multiply(innovation);
        delete current_state_estimate; current_state_estimate = predicted_state_estimate->add(KG_I);
        delete KG_I;

        //     # We need the size of the Matrixx so we can make an identity Matrixx.
        int size = current_prob_estimate->rowNum;
        //     # eye(n) = nxn identity Matrixx.,
        Matrixx* eye = new Matrixx(size, size, 0); for (int i = 0; i < size; i++) eye->mat[i][i] = 1;
        Matrixx* KG_H = kalman_gain->multiply(H); Matrixx* E_KGH = eye->subtract(KG_H);
        delete current_prob_estimate; current_prob_estimate = (E_KGH)->multiply(predicted_prob_estimate);
        delete eye; delete KG_H; delete E_KGH;

    }
};


class Pid {
public:
    float Kp;
    float Ki;
    float Kd;
    float Ts;
    float e_old;

    float pVal;
    float iVal;
    float dVal;

    float pidOutVal;

    Pid(float _kp, float _ki, float _kd, float _ts) {
        Kp = _kp;
        Ki = _ki;
        Kd = _kd;
        Ts = _ts;

        e_old = 0;

        pVal = 0;
        iVal = 0;
        dVal = 0;

        pidOutVal = 0;
    }

    void init (float e0) {
        e_old = e0;
    }

    void step(float e) { // e - error; (u(t) - kalman(t)) -> e(t) -> [PID] -> r(t) -> [DC motor] -> y(t) -> [kalman] -> kalman(t)
        // computing and updating state, returning control signal value to controlled system

        pVal = e*Kp;
        iVal += e*Ki*Ts;
        dVal = (e - e_old)*Kd/Ts;

        e_old = e;
    }

    float getValue() { // optional
        // return current control signal value to controlled system

        pidOutVal = pVal + iVal + dVal;

        return pidOutVal;
    }

};


class Sensor {
public:
    int adcPin;

    Sensor(int adc_pin) { // constructor
        adcPin = adc_pin;
    }

    float getValue() {
        float read_v = analogRead(adcPin)*3.3/1024.0; // mapping from adc value to voltage: 0..1023 -> 0V..3,3V
        if (read_v < 0.4) read_v = 0.4; if (read_v > 2.75) read_v = 2.75; // voltage range normalization
        float read_mm = 200/(read_v - 0.25); // mapping from voltage to distance in mm

        return read_mm;

    }
};




// creating objects to use
// KALMAN
// creating initial matricies
Matrixx* A = new Matrixx(1, 1, 1);
Matrixx* H = new Matrixx(1, 1, 1);
Matrixx* B = new Matrixx(1, 1, 0);
Matrixx* Q = new Matrixx(1, 1, 0.00001);
Matrixx* R = new Matrixx(1, 1, 0.1);
Matrixx* xhat = new Matrixx(1, 1, 3);
Matrixx* P = new Matrixx(1, 1, 1);
Matrixx* controlVec = new Matrixx(1, 1, 0);
Matrixx* measuredValVec = new Matrixx(1, 1, 0);

Kalman kalman(A, B, H, xhat, P, Q, R);

// SENSOR
Sensor sensor(A1); // ADC pin

// PID
float u = 240; // in mm
float e = 0;
float r = 0;
float y = 0;
float y_kal = 0;
int Tp = 10; // in ms

Pid pid(1.0, 0.25, 0.25, (float) Tp/1000.0); // Kp, Ki, Kd, Tp

// MOTOR
char nD2 = 4; //4
char M1DIR = 7; //faza A
char M2DIR = 8; //faza B
char nSF = 12;//error
char M1FB = A0; // Return motor 1 current value in milliamps.
char M2FB = A1; /// Return motor 2 current value in milliamps.
char M1PWM = 9; //AENABLE/AIN2
char M2PWM = 10; //BENABLE/BIN2

DualMC33926MotorShield motor( M1DIR, M1PWM, M1FB, M2DIR, M2PWM,  M2FB, nD2, nSF);


String s;


void setup() {
    Serial.begin(9600);

    motor.init();

    pid.init(u);

    s = "\n";
    s += u; s += "\t"; s += e; s += "\t"; s += r; s += "\t"; s += y; s += "\t"; s += y_kal; s += "\r\n";
    s += "u\te\tr\ty\ty_kal \r\n";
    Serial.print(s);
}

void loop() {

    y_kal = kalman.getCurrentState(); // computing kalman filter output value

    y = sensor.getValue(); // get value from sensor in [mm]
    measuredValVec->mat[0][0] = y; kalman.step(controlVec, measuredValVec); // computing kalman state for next step

    r = pid.getValue(); // get value of controol signam from PID controller

    motor.setM2Speed(5*r); // passing control value from PID to DC motor

    e = u - y_kal; // computing new error signal value
    pid.step(e); // computing PID state for next step

    s = ""; s += u; s += "\t"; s += e; s += "\t"; s += r; s += "\t"; s += y; s += "\t"; s += y_kal; s += "\r\n"; // printing values to serial output
    Serial.print(s);  // printing values to serial output

    delay(Tp); // delay between loops
}
