
#Communicating with an Arduino via serial communication.

#run this command before and after connecting the Arduino:     ls /dev/tty*
#the new item on the list is the Arduino ID

#!/usr/bin/python
from os import system, remove
import math
import time
from time import sleep
import serial

#initialize serial communication with arduino9
ser = serial.Serial('/dev/ttyACM0', 9600) #plug in arduino ID here.
sleep(3) #wait for arduinio init

t0 = time.time()
while True:
    i = i + 1
    t = time.time() - t0 #relative time

    w = ser.write(bytearray('A1','ascii')) #read from arduino pin A1
    output = ser.readline() #read from arduino - ascii format
    outputf = output.decode('ascii') #convert ascii to string
    data_raw = int(outputf) #analog input in integer format

    data = "{} {} {} {} {}\n".format(i,t,t/60,t/3600,data_raw)

    print (data)
  
    sleep(2) #delay
