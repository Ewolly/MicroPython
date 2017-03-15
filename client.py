import socket
import csv
from datetime import datetime
packetfile = open("64onwrds.csv", 'wb')
writer = csv.writer(packetfile)

addr = socket.getaddrinfo("192.168.43.50", 80)[0][-1]
for x in range(64, 256):
    sent_bytes = bytes("u"*x + '\r')
    for i in range(3):
        s = socket.socket()
        s.connect(addr)
        s.send(sent_bytes)
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
        writer.writerow(
            (len(sent_bytes) - 1, 
            (stop-go).total_seconds(),
            byte_count,
            (8*byte_count/(stop-go).total_seconds())/1000))
        #print (stop-go).total_seconds()
        s.close()
        #print byte_count
        #print (8*byte_count/(stop-go).total_seconds())/1000
        print "test " + str(i+1) + " is done"
    print "Group test " + str(x) + " completed"
packetfile.close()
