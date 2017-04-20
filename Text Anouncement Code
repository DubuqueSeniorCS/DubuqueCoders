import requests#used to get the info from website 
from sense_hat import SenseHat#used to talk to sense hat 
import time #link

from datetime import datetime,time#used to insure only runs on the specified times
print("hi")

#link = "http://raw.githubusercontent.com/DubuqueSeniorCS/DubuqueCoders/master/Announcement%20System.txt" 
#link = "http://seniormath.wikispaces.com/file/view/liam.txt/611094579/liam.txt"
link ="https://pastebin.com/raw/gUUa97wg"

f=requests.get(link)#reads the webpage

#print(f.text) 
sense=SenseHat()#makes sensehat

def fullblock(color): 
  red= color#need to be 3 numbers (,,#)

  rouge = [red,red,red,red,red,red,red,red,
         red,red,red,red,red,red,red,red,
         red,red,red,red,red,red,red,red,
         red,red,red,red,red,red,red,red,
         red,red,red,red,red,red,red,red,
         red,red,red,red,red,red,red,red,
         red,red,red,red,red,red,red,red,
         red,red,red,red,red,red,red,red]
  return rouge
count = 60 
wait = 2 
print("Iniating Code")

now = datetime.now()
now_time = now.time()
while(now_time >= time(7,30) and now_time <= time(14,20)):#only runs in school hours
  now = datetime.now()
  now_time = now.time()
  #print("Reading web\n") 
  f=requests.get(link)#reads the webpage

  while "RED" in f.text:#checks for red alert issue
    f=requests.get(link)#reads the webpage
    sense.set_pixels(fullblock((255,0,0)))
    time.sleep(wait)
    message = f.text.replace("RED"," ")
    sense.show_message(message, text_colour = [255,0,0])
    
  
  while "GREEN" in f.text:
    f=requests.get(link)#reads the webpage
    sense.set_pixels(fullblock((0,255,0)))
    time.sleep(wait)
    message = f.text.replace("GREEN"," ")
    sense.show_message(message, text_colour = [0,255,0])
  if(f.text=="Error with this ID!"):
    print("\n"*3,"Error Reading Web Page","\n"*3)
    break
  else:
    print(f.text)
    sense.show_message(f.text, text_colour = [0,0,255])
  time.sleep(2)
