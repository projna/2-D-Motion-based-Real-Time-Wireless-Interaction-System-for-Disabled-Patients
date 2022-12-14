# 2-D-Motion-based-Real-Time-Wireless-Interaction-System-for-Disabled-Patients

With the increasing number of disabled patients in
hospital, diversified needs of patients at certain times are to be
fulfilled. To provide with eminent healthcare and service, a full
time caretaker or 24 hour monitoring system may be needed,
requiring a huge amount of manpower and cost. In this paper
a low cost real time implementable system in hospital to establish
communication between multiple patients and nurse is proposed.
A small wireless transmitter consisting of Arduino Nano, NRF
24L01 and Accelerometer ADXL 335 is attached to a movable
body part of the patient working as message (8 messages) conveyer.
Device of every patient will be centrally linked to the
receiver point at nurse’s end by wireless medium using SPI transmission.
The central receiver can convey the message from all
patients in a screen and trigger and alarm for notifying new message.
In case of distant wards from the central receiver (>40 m),
repeaters are used to convey the message to the central receiver.
Via this system the issue of 24 hour monitoring can be solved
with a very affordable cost and less manpower, improving healthcare
facilities and patient satisfaction in hospitals to manifold.
|![image](https://user-images.githubusercontent.com/35718781/191404527-aea0911e-8740-4061-a450-8b2fb6eb5a91.png) |
|:--:| 
|Fig. 1. Block Diagram of the Sender Unit showing direction of flow of power and transmission of signal.|
|![image](https://user-images.githubusercontent.com/35718781/191404613-185f3a7d-1d13-4437-b17d-fef41ce3b469.png)|
|Fig. 2. Block diagram of Receiver Unit with direction of flow of information.|
|![image](https://user-images.githubusercontent.com/35718781/191404629-51d09ac6-31bd-4cea-8e07-5a3041bb6455.png)|
|Fig. 3. Portable transmitting unit consisting of Arduino Nano, ADXL 335 and NRF24L01 powered by two 3.3v batteries.|
| ![image](https://user-images.githubusercontent.com/35718781/191404650-017de9e2-787c-488a-8743-ee677079da2d.png) | 
|Fig. 4. Eight positions for hand that conveys eight different messages. (a) Normal Position (b) Right 45 degree bent (c) Right 90 degree bent (d) Back
more than 45 degree bent (e) Left 45 degree bent (f) Left 90 degree bent (g) Front bent more than 45 degree bent (h) Fully overturned.|






