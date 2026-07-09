# About

i was particulary inspired by instagram reels that showed robots demonstrating PID

i have some new members for my VEX Robotics team who are going to be learning about PID soon for their robots, so I wanted a nice way to demonstrate the concept since there are a lot of other variables when tuning a VEX robot.

![image](https://cdn.hackclub.com/019f45f0-fe00-7498-b544-27af4fe70314/paste-1783584848591.png)

### Assembly
The following includes which each component in the BOM.csv correlates to the reference on the PCB:

| Reference        | Component                  |
| ---------------- | -------------------------- |
| C1               | Aluminum Capacitor (100µF) |
| C2               | Aluminum Capacitor (330µF) |
| C3, C5           | Ceramic Capacitor (22µF)   |
| C4, C6, C8, C10  | Ceramic Capacitor (0.1µF)  |
| C7               | Ceramic Capacitor (10nF)   |
| C9               | Ceramic Capacitor (2.2nF)  |
| R1               | Resistor (330Ω)            |
| R4, R7           | Resistor (4.7kΩ)           |
| R5, R6           | Resistor (5.1kΩ)           |
| L1               | Power Inductor             |
| D1, D4           | Schottky Diode             |
| D2               | General Purpose Diode      |
| D3               | LED                        |
| D5               | Schottky Diode (Silicon)   |
| U1               | ESP32-S3-MINI-1-N8         |
| U2               | Buck Regulator             |
| U3               | LDO Regulator              |
| U4               | MPU-6050 (IMU)             |
| F1               | Fuse                       |
| SW1              | Switch                     |
| J1               | Battery Connector (XT30)   |
| J3               | USB-C                      |
| A1               | Motor Driver               |


![image](https://cdn.hackclub.com/019f45db-50b8-78f9-b011-60c9e52bca06/paste-1783583428059.png)
[![View PCB on KiCanvas](https://hack.club/pcb-badge)](https://kicanvas.org/?github=https://github.com/Daxz0/unicycle/tree/main/pcb)

### Resources
thanks to all these incredible resources that allowed me to put the cad together
- https://grabcad.com/library/nema-17-bracket-1
- https://grabcad.com/library/2s-7-4v-li-po-battery-1
- https://grabcad.com/library/pololu-scooter-skate-wheel-70x25mm-1
- https://a.pololu-files.com/picture/0J5557.600.jpg?7958d675b1fec8d1f6bb65c62e140bbe

note: the adapter for the wheel shaft i made myself as i could not find an existing CAD for it, linked instead is a reference sheet i used to make my own

![image](https://cdn.hackclub.com/019f45df-66b4-7c27-9996-b56375e271c8/paste-1783583695808.png)