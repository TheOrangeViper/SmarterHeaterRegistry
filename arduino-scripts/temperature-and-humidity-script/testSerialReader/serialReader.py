import serial.tools.list_ports

serialInst = serial.Serial()

portVar = "COM4"
baudRate = 9600


serialInst.baudrate = baudRate
serialInst.port = portVar
serialInst.open()


while True:
    if serialInst.in_waiting:
        packet = serialInst.readline()
        print(packet.decode('utf'))
    