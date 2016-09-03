#!/usr/bin/python
from md import MD

def main():
    i  = 0
    dt = 0.1
    sim = MD()

    sim.data_read()

    while (i < 1000):
        sim.vverlet_1(dt)
        sim.force()
        sim.vverlet_2(dt)
        i = i + 1
        if (i%100 == 0):
            sim.print_snap(i)

if __name__ == '__main__':
    main()
