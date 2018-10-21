import os
from socket import *
import serial
import ast

host = ""
port = 6060
buf = 1024

addr = (host,port)
UDPSock = socket(AF_INET,SOCK_DGRAM)
UDPSock.bind(addr)
print("Waiting for Command")

ser = serial.Serial('/dev/ttyACM0',9600)

while True:
    #print("running loop")
    (data, addr) = UDPSock.recvfrom(buf)
    print("Recieved Message: " + data)
    if data == 'close':
        break

    if data != '[]':
        x = ast.literal_eval(data)
        ser.write(str.encode(str(x[0])))
        ser.write(str.encode(str(x[1])))
        ser.write(str.encode(str(x[2])))



UDPSock.close()
