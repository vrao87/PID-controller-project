
#include <numeric>
#include <string>
#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

#define TUNE_PARAMS FALSE

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Kd, double Ki) {
	this->Kp = Kp;
	this->Kd = Kd;
	this->Ki = Ki;

	p_error = 0.0;
	d_error = 0.0;
	i_error = 0.0;
}

void PID::UpdateError(double cte) {

	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;

}

double PID::TotalError() {
	double Err;
	Err = -(Kp * p_error) - (Kd * d_error) - (Ki * i_error);
	return Err;
}

double PID::Twiddle(){
	double best_err = 0.0;

#if TUNE_PARAMS	
	if(twiddle_params == 1){
       /* tune proportional parameter */
	}

	if(twiddle_params == 2){
		/* tune differential parameter */
	}

	if(twiddle_params == 3){
		/* tune all three parameters */
	}
#endif
return best_err;
}

