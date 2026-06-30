from math import cos, sin, pi, sqrt

def deg_to_rad(theta):
    return ((pi*theta)/180)

t = int(input())

while (t > 0):
    n = int(input())
    rotation = 0
    x, y = 0, 0
    while(n > 0):
        cmd, units = [i for i in input().split()]
        units = int(units)


        if cmd == "fd":
            x += units*cos(rotation)
            y += units*sin(rotation)
            pass
        elif cmd == "bk":
            x -= units*cos(rotation)
            y -= units*sin(rotation)
            pass
        elif cmd == "lt":
            theta = deg_to_rad(units)
            rotation += theta
            pass
        elif cmd == "rt":
            theta = deg_to_rad(units)
            rotation -= theta
            pass
        n -= 1
    print(round(sqrt(x**2 + y**2)))
    t -= 1