# Superellipsoid force & torque model
A model to estimate flow induced force and torque on a superellipsoid shaped particle in creeping flow conditions.

Details of the model are described in the following paper:

* Štrakl, M., Hriberšek, M., Wedel, J., Steinmann, P., Ravnik, J. (2022) A Model for Translation and Rotation Resistance Tensors for Superellipsoidal Particles in Stokes Flow. J. Mar. Sci. Eng. 2022, 10, 369. doi:[10.3390/jmse10030369](https://www.mdpi.com/2077-1312/10/3/369)

File list:

Main Model lib:
- supereForceTorque.cpp
- supereForceTorque.h

Tensor coefficient libs:
- coeffsK.cpp
- coeffsK.h
- coeffsOmega.cpp
- coeffsOmega.h
- coeffsPI.cpp
- coeffsPI.h

Use example:
- main.cpp

To check the validation results and see a simple use example, compile the test environment:
- g++ -o main main.cpp supereForceTorque.cpp coeffsK.cpp coeffsOmega.cpp coeffsPI.cpp


