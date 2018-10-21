import os
from socket import *

host = "Dragon"
port = 6060
buf = 1024

addr = (host,port)
UDPSock = socket(AF_INET,SOCK_DGRAM)
UDPSock.bind(addr)
print("Waiting for Command")

while True:
    (data, addr) = UDPSock.recvfrom(buf)
    print("Recieved Message: " + data)
    if data == 'close':
        break

UDPSock.close()
