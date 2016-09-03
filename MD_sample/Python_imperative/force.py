import math
from md import Npt, box, rcut2

def dnint(x):
    if (x>0.0):
        return math.floor(x+0.5)
    else:
        return math.ceil(x-0.5)

def force(q):
    dx = [0., 0., 0.]
    for i in range (Npt):
        for k in range (3):
            q[i].ff[k] = 0.

    for i in range (Npt-1):
        for j in range (i+1, Npt):
            r2 = 0.0
            for k in range(3):
                x = q[i].xx[k] - q[j].xx[k]
                dx[k] = x - box * dnint(x/box)
                r2 = r2 + dx[k]*dx[k]
            if (r2 < rcut2):
                coef = 1./(r2*math.sqrt(r2))
                for k in range(3):
                    q[i].ff[k] = q[i].ff[k] + coef * dx[k]
                    q[j].ff[k] = q[j].ff[k] - coef * dx[k]
