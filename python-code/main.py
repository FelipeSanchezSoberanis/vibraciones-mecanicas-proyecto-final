import serial
import matplotlib.animation as animation
import time
import matplotlib.pyplot as plt


ser = serial.Serial()
ser.port = "/dev/ttyUSB0"
ser.baudrate = 9600
ser.timeout = 10
ser.open()

fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

xs = []
ys = []

start_time = time.time()


def animate(_):
    line_as_bytes = ser.readline()
    line_as_string = bytes.decode(line_as_bytes)

    try:
        dist = float(line_as_string)

        ys.append(dist)
        xs.append(-start_time + time.time())

        ax.clear()
        ax.plot(xs, ys, label="Tiempo vs distancia")

        plt.axis([1, None, 10, 15])

    except ValueError:
        print("Error reading value from serial port")

        pass


ani = animation.FuncAnimation(fig, animate, interval=1)
plt.show()
