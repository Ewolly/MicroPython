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
t = 0
i=0
while True:
    cl, addr = s.accept()
    print('client connected from', addr)
    for _ in range(1000000):
        cl.send("{}\n".format(t))
        t = time.time()
    cl.close()
