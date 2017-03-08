import machine
import time

pin = machine.Pin(1, machine.Pin.OUT)
pin.high()
pin_on = False

import socket
addr = socket.getaddrinfo('0.0.0.0', 80)[0][-1]

s = socket.socket()
s.bind(addr)
s.listen(1)

print('listening on', addr)

while True:
    cl, addr = s.accept()
    print('client connected from', addr)
    go = time.time()
    for i in range(10000):
        cl.send("0")
    stop = time.time()
    print (stop - go)
    cl.close()