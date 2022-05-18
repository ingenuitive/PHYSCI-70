  #include <AccelStepper.h>

  const int stepPin = 13;
  const int dirPin = 12;
  
  AccelStepper stepper (1, stepPin, dirPin);
  void setup()
  {  
    stepper.setMaxSpeed(700);
    stepper.setAcceleration(200);
    stepper.moveTo(700);
  }
  void loop()
  {
      if (stepper.distanceToGo() == 0)
        stepper.moveTo(-stepper.currentPosition());
      stepper.run();
  }
