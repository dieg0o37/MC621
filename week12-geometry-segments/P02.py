from math import cos, pi, sin, sqrt


try :
    while(True):
        n, T = [int(i) for i in input().split()]
        dx = []
        dy = []
        r, t = [int(i) for i in input().split()]
        theta = (2*pi*T)/t
        dx.append(r*cos(theta))
        dy.append(r*sin(theta))
        d = []
        d.append(f"{sqrt(dx[0]**2 + dy[0]**2):.4f}")
        for i in range(1, n):
            r, t = [int(i) for i in input().split()]
            theta = (2*pi*T)/t
            dx.append(dx[i - 1] + r*cos(theta))
            dy.append(dy[i - 1] + r*sin(theta))
            d.append(f"{sqrt(dx[i]**2 + dy[i]**2):.4f}")
        
        print(" ".join(d))
except EOFError:
    exit
