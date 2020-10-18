# R3-SoftwareTraining - Leslie Kocsis
## Intro:
This is my submission for Ryerson's 2020 R3 club Software training 1. The task is to use all the allowed circuit components with an arduino board to control two motors as the rover uses multiple motors to move. The control system uses the following components: 
- potentiometer
- arduino 
-dip switch
-L293D motor controller chip  
## Progress:
To implment the requirements I went through two designs. The first design implemented all of the features required including the dipswitch control. However, I misread the task pdf and thought that I needed to only use the dip switch to control the motors. I had read later on that it should not be switch controls the voltages for the chip, but the arduino should. For my first design, I had the PWM signal output go directly into the dip switch which went directly into the L293D chip. This did give the desired results of motor control, yet it was inadequte because the switches had to be switched on in a specific pattern depending on the wiring. Thus, I decided that the arduino should be programmed to control the state of the motors depending on which number on the dip switch is flicked. This would provide a more comprehensible and usable approach than relying on specific switch patterns due to the control being hard wired. Therefore, I placed the dipswitch pins as pullup inputs for the arduino. I put a conditional for all four pins to dictate the states of the motors depending if a specific switch is toggled which made the design a lot more usuable.  
![Test](./Images/R3TC1.png)
