<h1 align="center">Mobile-Bluetooth-RC-CAR</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Platform-MIT%20App%20Inventor-brightgreen">
  <img src="https://img.shields.io/badge/IDE-Arduino%20IDE-blue">
  <img src="https://img.shields.io/badge/Bluetooth-Arduino%20Nano-blueviolet">
</p>

<p align="center">
  <img src="https://github.com/username/repository-name/blob/main/demo.gif" alt="demo">
</p>

## Introduction

We are planning to create a robot that can be maneuvered using a mobile application connected through Bluetooth. To develop the app, we will be utilizing the MIT App inventor platform to design and construct it according to our preferences.

## Designing

Take the card bricks from your Junkbot kit and build a base for your robot. Or, you can make your own design using whatever you want.

## Connecting

Connect the two DC Motors to Junkbot board as shown below. Remember that the pins’ numbers are 2, 3 & 4, 5.

## Building Mobile App (Design)

In this step we are going to build our own android mobile app using a free web application called MIT App Inventor. It allows us to build apps easily with drag-n-drop similar to Junkbot software. In order to build our app that controls the robot follow these steps:

1. Go to [http://ai2.appinventor.mit.edu](http://ai2.appinventor.mit.edu) and sign up for MIT App Inventor using your Google account.

2. Click on “Start new project” and name your project.

3. The designer window should open. MIT App Inventor has 2 main sections: designer and blocks. The designer is where you can add buttons, text, screens, and design the overall app look. On the other hand, the blocks sections is where you can program your app to do what you want.

4. On designer window, we need to add 4 buttons to control the four directions, (forward, backward, right, and left), a list picker to choose the Bluetooth device, indication button for the Bluetooth status and three non-visible  components which are Bluetooth client, clock and Notifier. To do that follow these steps:

- From “Layout” drag one “Horizontal Arrangement” and one “Table Arrangement”. To put them in the middle of the screen, click on “Screen1” from the components window, then from “Align horizontal” on the properties window choose “center”.
- For the “Table Arrangement” change the number of rows and columns to 

- Add the Non-visible components. From “User Interface” add the “Notifier”, From “Sensors” add “clock” , and from “Connectivity” add “Bluetooth Client”

- Change the components name from the “Component” window and edit their properties. You can add images instead of text for the buttons. You should have a layout similar to this: ![design](https://github.com/username/repository-name/blob/main/design.png)

## Building Mobile App (Blocks)

Now it’s time to program the components we have added.

1. Go to “Blocks” editor 

2. The first thing we want our app to do is to connect to the Bluetooth device which is Arduino Nano (with Bluetooth module ) or JunkBot board. To do that, we want our “list picker”, which we added in “designer” editor to show us a list of Bluetooth devices paired
Building Mobile App (Blocks):

Now it’s time to program the components we have added.

- Go to “Blocks” editor 

- The first thing we want our app to do is to connect to the Bluetooth device which is Arduino Nano (with Bluetooth module ) or JunkBot board. To do that, we want our “list picker”, which we added in “designer” editor to show us a list of Bluetooth devices paired with our phone. So add the ‘BeforePicking’ block form the list picker and attach to it the ‘set Bluetooth Elements’ block. Then from the BluetoothClient blocks we will add the ‘Bluetooth-client AddressesAndNames’ block

- Next we want our phone to connect to the Bluetooth device that we have previously picked. So, from your list picker add “When AfterPicking” and set the Selection to ‘call BluetoothClient from the BluetoothClient block. Then Connect address’ block and add the block ‘List picker Selection’ to it.

- But, what if we forget to turn on the Bluetooth ON from our settings! Therefore it’s better if our app shows up a notification to remind us. In order to do that, from “Screen1” add “when initialize”. Then, add the condition if the Bluetooth is not enabled call the notifier and add your message.

- It’s a good thing if we have an indication button that continuously shows us our connection state. Do you remember that red button we added next to our list picker “Connect”? Let’s change its color to green if we are connected by adding the following code.

- After we are done with the connection lets control our robot. We want it to move forward when I press the forward button “Touch Down” and stop whenever I stop pressing “Touch up”. But how our Junkbot Board will know that! We should call our “Bluetooth Client” to send a specific text for each direction. So, whenever our board receive this text it will control the motors accordingly.

- Your final code should be as following: (Images will be added)

##Programming: (Code is Provided in this GitHub Repo)

We are done now with our mobile app :D let’s start programing our junkbot Board. Note: you can copy the full program from the code part.

- If you have Arduino IDE installed in your computer you can use it to write the code. Otherwise, go to junkbot software drag “Arduino program” from “Robot”, click on it then click on “Edit with Arduino IDE”.

- Now let’s start writing the code. First, we set four integer variables for the motors pin number and one more for the data received from the mobile app via Bluetooth.

- Then, in void setup we set these pins as output pins. And we initialize serial communication at 115200 bits per second which is the default rate for Junkbot board Bluetooth model

- After that, in void loop we check if we are receiving data from Bluetooth, and assigning these data to the variable “state” which we initialized earlier.

- Then the last part on our code is to control the motion of the motors according to the letter received from the app via Bluetooth.   

##Uploading the Code:

After we have finished writing the code, we have to upload it to Junkbot board. Go to tools--> board -->  “Arduino Nano” and then change the “port” to the Available one.

"Upload the code"

##Connecting The App With The Board:

We are done now with the app and the code lets connect them together!

- Put the board switch on the Bluetooth mode 

-  Open the Bluetooth from your mobile settings

- Scan for the Available devices. The name of junkbot board Bluetooth model is “HMSoft”. Find it and pair your phone with it.  

- Install “MIT AI2 Companion” app from your play store

- Go to the app you have built on the web, then from The menu bar  go to -->Connect --> AI Companion 

- You will get a code, scan it from your mobile app  

- The same screen that we have designed earlies will show up. Connect, select “HMSoft”, control your Robot!! 

Features

The Bluetooth Controlled Robot will have the following features:

    Control the movement of the robot using the mobile application
    Intuitive user interface for easy control
    The robot can be programmed to perform various tasks
    Can be controlled from a distance using Bluetooth technology

##Contributions
I welcome contributions to this project. If you have any suggestions, bug reports, or feature requests, please feel free to open an issue or submit a pull request. I will be happy to review your contributions.
License

##This project is licensed under the MIT License. See the LICENSE file for more information.
