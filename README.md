# Video #251 8-bit Shift Register for 7-segment LEDs
Drive unlimited 7-segment LEDs, controlled by an 8-bit Shift-Register

![Thumbnail (Phone)](https://user-images.githubusercontent.com/20911308/192530717-416bf61f-fe7d-488c-8204-51025c3b3e80.jpg)  
#### See YouTube Video #250 

[![PCBWayPrototype the easy way](https://user-images.githubusercontent.com/20911308/185422574-52a4e7db-c680-4dd2-87be-1f1dd1db6a65.gif "PCBWay - up to 20% Discount on 4 & 6-layer PCBs")](https://pcbway.com/)  

► shiftOut Arduino Command
https://www.arduino.cc/reference/en/language/functions/advanced-io/shiftout/

► Useful Shift Register tutorial by Akarsh Agarwal
https://create.arduino.cc/projecthub/355990/74hc595-shift-register-tutorial-arduino-with-7-segment-42a6cc

► 74HC595 Datasheet
https://www.sparkfun.com/datasheets/IC/SN74HC595.pdf
https://www.ti.com/document-viewer/SN74HCT595/datasheet/GUID-E9AD5C26-A5E0-4091-B6CB-0B630A9C7E07

► The Kingsbright SC56-11EWA I used for prototyping
https://www.kingbrightusa.com/images/catalog/SPEC/SC56-11EWA.pdf

► The 5.1mm ~0.21" SMD Kingsbright KCSC02-106 I used in the final project £1 each (in a pack of 5):
https://uk.rs-online.com/web/p/led-displays/6165428/
PDF for above
https://docs.rs-online.com/f9af/0900766b807e3cf6.pdf

### Worked example:

Display "4" on first digit. No decimal point (dp).

"4" requires segments b,c,f,g

Bit pattern  
abcdefgh  
01100110  

Only seven bits so terminate with "0" (or "1" if using the decimal point on pin 7 of the 74HC595).

01100110 is in decimal 102 so that is what we send to the device using shiftOut().  
01100111 is in decimal 103 (decimal point) if required.  

"6." requires segments a,c,d,e,f,g,h(dp)  
So 10111111 is 6 with a decimal point = 191  
Subtract one to remove the decimal point, ie 190.  

Demo sketches right here in the GitHub!  





► You can now support me by buying me a coffee!
https://buymeacoffee.com/ralphbacon 

► List of all my videos  
(Special thanks to Michael Kurt Vogel for compiling this)  
http://bit.ly/YouTubeVideoList-RalphBacon  

► If you like this video please give it a thumbs up, share it and if you're not already subscribed please consider doing so and joining me on my Arduinite (and other μControllers) journey  

My channel, GitHub and blog are here:    
\------------------------------------------------------------------  
• https://www.youtube.com/RalphBacon  
• https://ralphbacon.blog  
• https://github.com/RalphBacon  
• https://buymeacoffee.com/ralphbacon  
\------------------------------------------------------------------  

My ABOUT page with email address:  
https://www.youtube.com/c/RalphBacon/about  
