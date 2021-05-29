## IOT-based-Fall-Detection-System

## Software Requirements
1. Download and install the Proteus software.
2. Dowload and install Arduino IDE.
3. Download a virtual Serial Port Emmulator. [VSPE (64 BIT) is used for this project]

## SETUP
1. Download the FALL DETECTION.pdsprj file from the repository.
2. Open the file on proteus.	
3. Edit the component - Ultrasonic Sensor
   * Download the ultrasonic sensor library for proteus via web search.
   * Three files can be found in the folder after extracting.
        * UltrasonicTEP.IDX, 
        * UltrasonicTEP.LIB, 
        * UltrasonicTEP.HEX. 
   * Place these three files in the LIBRARY folder of your Proteus software folder. Sometimes LIBRARY folder can be found insite the DATA folder of the proteus as shown below</br> 
     [...\Labcenter Electronics\Proteus 8 Professional\DATA\LIBRARY\UltraSonicSensor.HEX].
   * Now, double click on the ultrasonic sensor, edit component dialog box appears.
   * In the ultrasonic sensor field. There is an option to select file. Select UltraSonicSensor.HEX file from the LIBRARIES folder of proteus. Click OK.
4. Download the Blynk app from playstore.
5. Create an account and a new project by mentioning the device as Arduino instead of ESP module which is the default device.
6. After creating the project an email will be sent to the registered email address which contains the auth key. 
7. This auth key needs  to be copied and pasted in the Arduino code </br>
   char auth[] = "XXXXXXXXXXXXXXXXX"; </br>
   to establish a connection between the circuit and the Blynk app.
8. Open Virtual Serial Port Emmulator.
9.	Click on Add new device icon.
11.	Select the option pair from  dropdown under the device type. Click next.
    ![image](https://user-images.githubusercontent.com/66554341/120069226-6532e000-c0a2-11eb-86f4-7bfbee5aff9a.png)
12. Open the virtual serial port emulator and select device type as pair and click next which directs to select a pair of COMx and COMy. </br>
    Select COM1 from 1st list and COM2 from 2nd list and click Finish. This is done to establish a communication as shown below.
    ![image](https://user-images.githubusercontent.com/66554341/120069252-85fb3580-c0a2-11eb-9603-8091bb3c2b5d.png)
13. A window appears as shown below on successful connection
    ![image](https://user-images.githubusercontent.com/66554341/120069277-afb45c80-c0a2-11eb-9893-0569aa2d4947.png)
14. 
    




