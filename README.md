## IOT-based-Fall-Detection-System
This project proposes an IoT based fall detection and rescue system. The main objective here is to alert the guardian/ doctor if there is a possibility of fall. Therefore, it is designed in such a way that if an obstacle is sensed by the ultrasonic sensor then it alerts the user via a buzzer and hence will be saved from any accident / falling.Further, The most life-threatening aspect of falling is lying on the floor for long periods of time without any medical aid. If the distance between the obstacle and the sensor further reduces, then an email is sent to a specified email addess. Thereby preventing fall.
<h1 align="center">
 <img src="https://user-images.githubusercontent.com/66554341/120069775-471aaf00-c0a5-11eb-9d6a-1b7d5184c57c.png" />
</h1>

## Software Requirements
1. Download and install the Proteus software.
2. Dowload and install Arduino IDE.
3. Download a virtual Serial Port Emmulator. [VSPE (64 BIT) is used for this project]

## Required devices on proteus
1. ARDUINO UNO
2. LCD 16X2
3. L293D [MOTORDRIVER]
4. DC MOTORS
5. ULTRASONIC SENSOR
6. POT-HG
7. BUZZER
8. COMPIM

## SETUP
1. Download the Blynk app on mobile from playstore.
2. Create an account and a new project by mentioning the device as Arduino instead of ESP module which is the default device.
3. After creating the project an email will be sent to the registered email address which contains the auth key. 
4. This auth key needs  to be copied and pasted in the Arduino code </br>
   char auth[] = "XXXXXXXXXXXXXXXXX"; </br>
   to establish a connection between the circuit and the Blynk app.
5. Open Virtual Serial Port Emmulator.
6.	Click on Add new device icon.
7.	Select the option pair from  dropdown under the device type. Click next.

    ![image](https://user-images.githubusercontent.com/66554341/120069226-6532e000-c0a2-11eb-86f4-7bfbee5aff9a.png)
8. Open the virtual serial port emulator and select device type as pair and click next which directs to select a pair of COMx and COMy. </br>
    Select COM1 from 1st list and COM2 from 2nd list and click Finish. This is done to establish a communication as shown below.
   
    ![image](https://user-images.githubusercontent.com/66554341/120069252-85fb3580-c0a2-11eb-9603-8091bb3c2b5d.png)
9. A window appears as shown below on successful connection

    ![image](https://user-images.githubusercontent.com/66554341/120069277-afb45c80-c0a2-11eb-9893-0569aa2d4947.png)
10. Edit the component - Ultrasonic Sensor
   * Download the ultrasonic sensor library for proteus via web search.
   * Three files can be found in the folder after extracting.
        >* UltrasonicTEP.IDX, 
        >* UltrasonicTEP.LIB, 
        >* UltrasonicTEP.HEX. 
   * Place these three files in the LIBRARY folder of your Proteus software folder. Sometimes LIBRARY folder can be found inside the DATA folder of the proteus as shown    below</br> 
     [...\Labcenter Electronics\Proteus 8 Professional\DATA\LIBRARY\UltraSonicSensor.HEX].
11. Download and Open the FALL DETECTION.pdsprj file on  Proteus software.
12. Now, double click on the ultrasonic sensor, edit component dialog box appears.
13. In the ultrasonic sensor field. There is an option to select file. Select UltraSonicSensor.HEX file from the LIBRARIES folder of proteus. Click OK.
14. Double click  on the COMPIM device and in the physical port select COM2 and set the Physical baud rate and virtual baud rate to 9600 from the dropdown. Then click okay.

    ![image](https://user-images.githubusercontent.com/66554341/120069395-72040380-c0a3-11eb-972e-cb9d0f6653e2.png)
15. Now, open command prompt and type the following 3 commands to communicate between the devices. </br>
    * To Specify the appropriate path of the scripts folder of Blynk </br>
    >cd C:\Users\HP\Documents\Arduino\libraries\Blynk\scripts. </br>
    * Copy the blynk-ser.bat from the directories displayed.</br>
    >dir </br>
    *  Now the device at COM1 is connected to Blynk cloud. </br>
    >blynk-ser.bat -c COM1 </br>
      
16. Now, Download and open the Fall detection arduino.ino file from repository.
17. Click on FILE > PREFERENCES </br>
    This opens a dialog box, if the verbose output during compilation check box is unchecked then check the text box and click okay.
18. Now,  run the Arduino file.</br>
    After compilation, the path of .hex file can be found as shown below
    
       ![image](https://user-images.githubusercontent.com/66554341/120069610-711fa180-c0a4-11eb-96ab-c1c157feedb0.png)
19. Copy the path of that file and go to proteus and double click on Arduino and paste the .hex file link in the program file section of arduino.  
20. Now simulate the circuit in proteus and use POT-HG (+ and -) to vary the distance.
21. Adjust the distance using potentiometer, If the distance (cm) becomes  < 390 then an email is sent to the email mentioned in the arduino code.

    




