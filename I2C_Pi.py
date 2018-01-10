#Raspberry Pi I2C master.

import smbus as smbus

bus = smbus.SMBus(1)

address = 0x08

if (1==0):
    #SEND POWER   (Sends command: "P2600")
    powerset = 2600
    bus.write_i2c_block_data(address,ord("P"),[ord(x) for x in str(powerset)])   #set power command

if (1==1):
    #READ ANALOG VOLTAGE
    bus.write_byte(address,0)
    block = bus.read_i2c_block_data(address, 0x32, 5) # Returned value is a list 5 characters long
    strippedblock = ['' if x==0 else chr(x) for x in block]
    outputstring = ''.join(i for i in strippedblock)
    outputinteger = int(outputstring)
    
#SEND -DAC- voltage (Pending)
    
    
    
    


