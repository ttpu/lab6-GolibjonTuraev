[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/4J8mXtke)
# Lab 6 - IoT 2024

## Participants:

### Team N: 

* Student 1: name,surname,id
* Student 2: name,surname,id
* etc...

![image](https://github.com/user-attachments/assets/9f94b187-9fac-4146-b95c-6dae9a4684d9)

* In this lab, you have to build following circuit and use it for working with MQTT protocol

### Task 1:
- Connect this device to the WiFi and set up MQTT protocol
  - MQTT host: mqtt.iotserver.uz
  - Port: 1883
  - Username: `provided in class`
  - Password: `provided in class`
    
- Then use this broker to subscribe to certain topic to receive messages
- Messages should indicate the command that this board must do (for example: control LEDS)
- Format of messages should be simple text
- Each team must choose different topic:
- 
* However, topic name should start with “ttpu/….”
- Once you finish, test it with your mobile phone (app: MyMQTT)
-
### Task 2:
- Now change the code to send the command to your neighbor team from your Serial monitor and control
their boards


### Task 3:
- Add the functionality of button
- Each button press must send (publish) the count number to certain topic in mqtt.
- Receiver of that message must show it in Serial monitor and control the led accordingly
o 0-off
o 1-red on
o 2-red off
o 3-green on.
o ……
