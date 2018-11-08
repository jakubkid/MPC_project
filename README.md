[//]: # (Image References)

[Model]:  ./img/kinematicModel.PNG "Model"

# CarND-Controls-MPC
Self-Driving Car Engineer Nanodegree Program model predictive controller 

---

## Write up

* Model description
    * Global kinematic model is used to calculate future vehicle path. Path with lowest cost is selected and first step is executed.

    ![Kinematic model][Model]

    * The cost function
        * emphasizes track and direction error so it gets weight of 20, next velocity error is added with weight 1.
        * Control signal is also added to the cost wheel control with weight 2 and speed control with weight 1
        * Rate of change in control signal is added with weights of 100
* Time step and number of samples
    * Time step was empirically to 0.05s next number of samples was adjusted so predicted track is never longer than reference track. This guarantees that reference track doesn't do weird curve at the end. 
* Polynomial fitting
    * 3rd order polynomial was fitted because it can estimate turns well enought and oscillations are less probable than with higher order polynomials.
* Latency handling
    * Latency is handled in main.cpp current car position is shifted with assumption that turn rate and speed won't change in that time. 

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
  * Run either `install-mac.sh` or `install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.

* **Ipopt and CppAD:** Please refer to [this document](https://github.com/udacity/CarND-MPC-Project/blob/master/install_Ipopt_CppAD.md) for installation instructions.
* [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page). This is already part of the repo so you shouldn't have to worry about it.
* Simulator. You can download these from the [releases tab](https://github.com/udacity/self-driving-car-sim/releases).
* Not a dependency but read the [DATA.md](./DATA.md) for a description of the data sent back from the simulator.


## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./mpc`.
