Total time spent:

## 7/1/2026 

i saw a cool reel on instagram about pid tuning, and since i already tune my robots pid for VEX, i wanted to just get better at it by using a more extreme example!

im also trying to learn on how to make a pcb, especially since i want to make one later down the road for my battlebot (so its not a jumble of wires)


#### researching the components.
im honestly just going to jump into it, and when the time calls for a specific component, i'll research it as it comes lmao.
i know that i need at least:

- wheel: to ya know be a unicycle
- motor: power that wheel
- IMU: detect when the robot is tilting
- accelerometer: measure which way the robot is tilting
- motor encoder: so i know how much to move the motor
- some sort of microcontroller
- something to control the motors

#### the power portion:
i downloaded kicad, and started just learning some basics of the software, the schematics, and to update the pcb, all that fun stuff

i think the most confusing stuff for me was honestly looking at all the datasheets and stuff since i knew what NOTHING was and where to find say a footprint of something, so that was a challenge in itself.

honestly i feel after finding the datasheet its not that bad!!

i couldnt figure out how to import footprints into kicad so i just tried to find components that didnt require it

anyways here the schematic portion of my power portion before i begin working on anything else
![image](https://cdn.hackclub.com/019f21a5-00e9-72e8-a3da-18b64a35f519/paste-1782975887579.png)

#### the esp!

i managed to import the esp from the library, and setup the EN pin as well as my power/gnd pins.
i also needed the usbc port to flash the esp, so i put that in as well
![image](https://cdn.hackclub.com/019f2204-4903-7f1d-a60d-50d192ce9693/paste-1782982132334.png)


then i spent some time trying to figure out how to connect the usbc connector and esp together, only the realize that i kinda have to shift everything around to not overlap wires.
![image](https://cdn.hackclub.com/019f2205-6288-7dda-b56c-75cd1b40ae89/paste-1782982204418.png)

hours spent: 7.5hrs

## 7/2/2026

tomorrow came, i slapped on the esc today

![image](https://cdn.hackclub.com/019f2c31-6d68-7625-bd55-5e423d8901ea/paste-1783152865035.png)
read some datasheets and somehow managed to get hopefully the right things wired up, and ERC is telling me no errors so far!!

exciting stuff.

begun to start connecting up the usbc connector so that I can actually flash this said esc
![image](https://cdn.hackclub.com/019f2c32-4d7b-7d99-bbf2-26e06771a077/paste-1783152922526.png)

i lowkey like thought that the wires couldnt cross and had a massive crashout about trying to route wires around, but silly me

wired up the usbc connector to the rest of my power source on the 5v channel
![image](https://cdn.hackclub.com/019f2c33-637b-716a-9b4e-5fbad5ae2f1b/paste-1783152993607.png)


lastly to end the night, i wanted to also get in my accelometer, which is going to be the main thing actually letting me know when to correct the PID
![image](https://cdn.hackclub.com/019f2c34-6839-7e8f-bb67-53fcf17a3a84/paste-1783153059733.png)

hours spent: 5hrs

## 7/4/2026

hi next evening it is.

added onto my drive module for the step motor

![image](https://cdn.hackclub.com/019f2c35-9d21-7365-98e8-6b6da6d51fbd/paste-1783153139503.png)


i learned about global flags for the first time here, which wouldve really helped earlier but makes it so that theres not a massive wire run all the way from one side to the other (uh yeah you can tell for sure this is my first pcb by how messy my traces are, i know to use flags & power symbols instead in the future)

yayyy i finished up the PCB design, although i ran into a few errors on the way

> Error: J2 pad B11 not found in Connector_USB:USB_C_Receptacle_GCT_USB4085.

this was due to me having like the wrong kind of symbol or something, i swapped it out for a smaller version as per a kicad forum post and no errors! hope it works

-- before
![image](https://cdn.hackclub.com/019f2c2e-b765-7703-9684-7702a044ff6e/paste-1783152687612.png)

-- after!
![image](https://cdn.hackclub.com/019f2c2c-dafb-7719-ac0f-403d0629d710/paste-1783152565383.png)

i also finally figured out that importing libraries is actually super easy, i just didnt know the right menu for it (which is in the main menu)
i finally imported the ESP32's library and got rid of an error that bugged me:

> Error: Cannot add U1 (footprint 'Espressif:ESP32-S3-MINI-1' not found).

its time to actually take it away from the scheamtic :sob:



hours spent: 5.5hrs