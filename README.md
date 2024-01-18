# IR controller for lights
 IR controller to turn on lights when door open

## Goal
 I have a blind storage room without power sockets. To light it up I installed three battery powered LED lights controlled using IR remote. This is inconvenient because every time I enter or leave this room I need to pick up the remote from it's holder, push button and place it back. I want to replicate the experience of using the fridge: light turns on when you open the door, turn off when you close it.

## Hardware
 To decode and transmit IR signals TCRT5000 reflective optical sensor was used. This sensor consists of two elements: phototransistor and an infrared emitter. Sensor was connected to the Arduino Pro Mini board. For a power surce I used two 18650 LiPo battery cells connected in series.

## TODO
* Complete Hardware section
* Add connection diagram
* Add Software section
* Add code to dump remote commands
