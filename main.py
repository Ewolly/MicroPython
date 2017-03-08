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
    for _ in range(10000):
        cl.send("{}\n".format(0))
    stop = time.time()
    cl.send ("{}\n".format(go))
    cl.send ("{}\n".format(stop))
    cl.close()