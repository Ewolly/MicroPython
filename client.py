import socket
from datetime import datetime

addr = socket.getaddrinfo("192.168.43.50", 80)[0][-1]
s = socket.socket()
s.connect(addr)
s.send(bytes('0'))

byte_count = 0
go = datetime.now()
while True:
    try:
        data = s.recv(100)
    except Exception as e:
        break 
    if data:
        byte_count += len(bytes(data))
    else:
        break
stop = datetime.now()
print (stop-go).total_seconds()
s.close()
print byte_count
print (8*byte_count/(stop-go).total_seconds())/1000