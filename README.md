# PID-controller-project
This Project is the ninth task (Project 4 of Term 2) of the Udacity Self-Driving Car Nanodegree program. The main goal of the project is to implement PID controller in C++ to steer the self driving car around the track in a Simulator.

The project was created with the Udacity Starter Code.

# PID controller details
The PID controller is often utilized as a control loop feedback controller and is very commonly used for many forms of control systems. The letters making up the acronym PID correspond to Proportional (P), Integral (I), and Derivative (D), which represents the three control settings of a PID controller. The purpose of the PID controller is to hold the system at a steady set point value for long durations of time. This is done by generating an error signal that is essentially the difference between the set point value(desired state) and current value(actual state). 

The three control elements can be thought of as follows:
* Proportional is dependent upon the present error
* Integral is dependent upon the accumulation of past error. It is used to reduce systematic bias
* Derivative is the prediction of future error based on the current rate of change of error

The results of each of the controls are then fed into a weighted sum, which then adjusts the output of the system. One or more of these controls can be utilized in a controller. It is necessary to tune these three control parameters so that the system behaves appropriately.

# Tuning
In general, the gain values of P, I, and D will need to be adjusted by the user in order to get the best performance of the controller.

Based on the experience with simulator, it is observed that:
Proportional gain results is larger changes in response to the error, and thus affects the speed at which the controller can respond to changes in the system. While a high proportional gain can cause a system to respond swiftly, too high a value can cause oscillations about the desired value. Too low a value and the circuit cannot efficiently respond to changes in the system.

Integral control is highly effective at increasing the response time of the system along with eliminating the steady-state error associated with purely proportional control.

Derivative control keeps track of the rate at which the error value changes and accordingly varies the response time of the system. Basically it determines how quickly the system is changing over time. Unlike proportional and integral control, derivative control will slow the response of the circuit. In doing so, it is able to partially compensate for the overshoot as well as damp out any oscillations caused by integral and proportional control.

These properties are used to tune the gain values for optimum system behaviour. While there is no specific rule set on how the values should be tuned, it is possible to tune the parameters either manually or programatically using one of the algorithms for e.g., twiddle that was introduced in the lessons.

For this project, I have tuned the parameters manually by trial and error method.
Initially all the three parameters are set to 0 and P value is increased in small steps. At each step, the behaviour is observed in the simulator. With increasing proportional gain, the system response is much quicker and the car is able to go around the curves easily but at the same time, oscillations about centerline also increases. The value at which the car is able to drive farthest is frozen at this point.

Next, differential gain value, D is increased slowly starting from 0. With increasing D, oscillations reduce and also response time of the car reduces. A suitable value at which oscillations are minimum yet response is good enough to negotiate the entire track is chosen. 
With only these 2 parameters tuned, car is able to go around the track without overshooting. Further, integral gain value is adjusted in very small steps (as suggested in the forum) to further fine tune controller output.
The values that I have came up with for gain parameters are:
**P: 0.16, I: 00006, D: 2.1**

Also, throttle value is increased and set at 0.4.

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

