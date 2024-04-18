// MultiStepper.pde
// -*- mode: C++ -*-
//
// Shows how to multiple simultaneous steppers
// Runs one stepper forwards and backwards, accelerating and decelerating
// at the limits. Runs other steppers at the same time
//
// Copyright (C) 2009 Mike McCauley
// $Id: MultiStepper.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <AccelStepper.h>

#define MOTOR1_STEP 26 // E0
#define MOTOR1_DIR 28
#define MOTOR1_EN 24

#define MOTOR2_STEP 36 // E1
#define MOTOR2_DIR 34
#define MOTOR2_EN 30

#define MOTOR3_STEP A0 // X
#define MOTOR3_DIR A1
#define MOTOR3_EN 38

#define MOTOR4_STEP A6 // Y
#define MOTOR4_DIR A7
#define MOTOR4_EN A2
// Define some steppers and the pins the will use
AccelStepper stepper1(AccelStepper::DRIVER, MOTOR1_STEP, MOTOR1_DIR);
AccelStepper stepper2(AccelStepper::DRIVER, MOTOR2_STEP, MOTOR2_DIR);
AccelStepper stepper3(AccelStepper::DRIVER, MOTOR3_STEP, MOTOR3_DIR);
AccelStepper stepper4(AccelStepper::DRIVER, MOTOR4_STEP, MOTOR4_DIR);

void setup()
{
    stepper1.setEnablePin(MOTOR1_EN);
    stepper1.setPinsInverted(false, false, true);
    stepper1.enableOutputs();
    stepper1.setMaxSpeed(200.0);
    stepper1.setAcceleration(100.0);
    stepper1.moveTo(240);

    stepper2.setEnablePin(MOTOR2_EN);
    stepper2.setPinsInverted(false, false, true);
    stepper2.enableOutputs();
    stepper2.setMaxSpeed(200.0);
    stepper2.setAcceleration(100.0);
    stepper2.moveTo(240000);

    stepper3.setEnablePin(MOTOR3_EN);
    stepper3.setPinsInverted(false, false, true);
    stepper3.enableOutputs();
    stepper3.setMaxSpeed(200.0);
    stepper3.setAcceleration(100.0);
    stepper3.moveTo(240000);

    stepper4.setEnablePin(MOTOR4_EN);
    stepper4.setPinsInverted(false, false, true);
    stepper4.enableOutputs();
    stepper4.setMaxSpeed(200.0);
    stepper4.setAcceleration(100.0);
    stepper4.moveTo(240000);
}

void loop()
{
    // Change direction at the limits
    if (stepper1.distanceToGo() == 0)
        stepper1.moveTo(-stepper1.currentPosition());
    stepper1.run();
    stepper2.run();
    stepper3.run();
    stepper4.run();
}