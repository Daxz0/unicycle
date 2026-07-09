Total time spent: 33hrs

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

![image](https://cdn.hackclub.com/019f2c7d-c2a2-781b-aa22-8cd8d2d46b23/paste-1783157867817.png)

tried my best here but i kind of missed things and failed where I didnt fully think about each trace properly, ill look at this with a clearer mind tmr.


hours spent: 6.5hrs

## 7/5/2026

i was lowkey locked in so i missed some images, but i didnt realize a MASSIVE mistake from yesterday

![image](https://cdn.hackclub.com/019f35e9-3fa1-73f4-b75e-af714aab58bd/paste-1783315905460.png)

if you compare from yesterday, i was completely missing the ESP32  (the footprint never updated after i imported it i guess)

originally i didnt realize that i could just follow my schematic (yeah kinda dumb i know) but following the actual schematic is so much easier than me trying to figure things out by seeing pad highlights and the rat nests.

![image](https://cdn.hackclub.com/019f35ec-6226-7382-be3c-a2f20a86a411/paste-1783316110853.png)

i also had to figure out the ground vias and the layers which was pretty straightforward if anything.
the most annoying part i had with DRC is just how when i click the error the highlight is so tiny and i cant see!!

i saved some room on the edges for future holes in the CAD mounting point, which speaking of is time to start up on that.
theres some spoke errors and stuff but googles telling me its a simple fix so i will ignore ignore.

hours spent: 6 hrs

## 7/7/2026

today is the day for CAD!

found grabcad files for the things I need, imported them onto onshape:
![image](https://cdn.hackclub.com/019f3e2d-70f9-7690-8945-63fe16689009/paste-1783454593385.png)

trying to figure out battery placements and where to put the PCB, the battery should likely be on the other side of the motor to balance the COG, and the PCB shouldnt matter that much in terms of weight.

hours spent: 2 hrs

## 7/8/2026

i decided to tack on the holes onto the pcb
![image](https://cdn.hackclub.com/019f4539-ee50-7ca6-b506-40dfe2d178fe/paste-1783572850355.png)

then got then got the a mounting spot for the battery
![image](https://cdn.hackclub.com/019f453a-2893-7b11-a420-80e153ce2810/paste-1783572865721.png)

i couldnt fing a right mounting spot that matches the holes, so i think ill just hot glue the PCB onto the plastic if it comes to that instead. now the problem is trying to find a suitable spot for the actual pcb since I didnt expect it to be so massive

![image](https://cdn.hackclub.com/019f4543-24d1-78ae-ae76-7c8764cec322/paste-1783573454089.png)

i mean i could just make it thicker to accomodate the PCB properly
![image](https://cdn.hackclub.com/019f4545-caf0-78b1-a5c3-396a28e7b102/paste-1783573627705.png)

and of course some chamfers + fillets to make everything look good :)
![image](https://cdn.hackclub.com/019f4548-89b3-7c09-a340-bec75974f8dc/paste-1783573807880.png)
![image](https://cdn.hackclub.com/019f4548-b568-717e-913a-a439cb1ad510/paste-1783573819244.png)

after taking a further look actually, i realized that since i expanded the original platform to allow the PCB to sit properly, i could actually move the battery to be sideways to have even better weight distribution. adding a slit at the top would allow the battery cables to go in properly, i then also need to think of a way to allow myself to put in and take out the battery easily.

![image](https://cdn.hackclub.com/019f45e4-d7ef-784d-a508-561fceba5bfa/paste-1783584052226.png)

actually, in theory the battery shouldnt fall out since the wires up top will be holding it in place and prevent it from pulling out. the other part playing into this is having the exit hole for the battery be higher than the natural sitting position of the battery, since typically the battery should be down due to gravity, making it so that youd have to manually pull up the battery first to take it out.

![image](https://cdn.hackclub.com/019f45f0-9bcd-718e-9791-00291e7acc68/paste-1783584823701.png)

wrote some preliminary code for the PID controller, well the PID controller doesnt exist yet but i added a foundation to be able to read the IMU and some safety features for when I can begin that.

![image](https://cdn.hackclub.com/019f4606-bf84-7a04-bc5e-c11b42910ccf/paste-1783586274349.png)
![image](https://cdn.hackclub.com/019f4607-815c-71df-89f1-bd68963c3339/paste-1783586324228.png)

we have to use the sensitivity from the datasheet (for both the accelerometer and gyroscope) in order to convert the sensor readings into actual units to be usable.

total hours: 7 hrs