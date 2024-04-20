import serial.tools.list_ports

arduino = serial.Serial()

portVar = "COM4"
baudRate = 9600

arduino.baudrate = baudRate
arduino.port = portVar
arduino.open()

idle = True


def write_read(command_arduino):
    try:
        arduino.write(bytes(command_arduino,'utf-8'))
        data = arduino.readline().decode('utf-8')
        return data
    except:
        return "failed"

while idle == True:
    myCommand = input("Command: ")
    print(write_read(myCommand))

# while True:
#     if arduino.in_waiting:
#         packet = arduino.readline()
#         print(packet.decode('utf'))
    