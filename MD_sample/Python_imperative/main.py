#!/usr/bin/python
from md         import Npt, box, Particle, mass
from verlet     import vverlet_1, vverlet_2
from force      import force
from print_snap import print_snap
import random

def data_read(q):
    for i in range (Npt):
        for k in range (3):
            q[i].xx[k] = (random.random() - 0.5)*box

def main():
    i  = 0
    dt = 0.1
    q = [ Particle () for i in range (Npt)]

    data_read(q)

    while (i < 1000):
        vverlet_1(q,dt)
        force(q)
        vverlet_2(q,dt)
        i = i + 1
        if (i%100 == 0):
            print_snap(i,q)

if __name__ == '__main__':
    main()
