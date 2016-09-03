import math
import random

Npt   = 100
rcut  = 9.0
rcut2 = rcut*rcut
box   = 20.0
mass  = 10.0

def dnint(x):
    if (x>0.0):
        return math.floor(x+0.5)
    else:
        return math.ceil(x-0.5)
    
class Particle():
    def __init__(self):
        self.xx = [0., 0., 0.]
        self.vv = [0., 0., 0.]
        self.ff = [0., 0., 0.]
        self.xm = mass;

class MD():
    def __init__(self):
        self.q = [ Particle() for i in range (Npt)]

    def data_read(self):
        for i in range (Npt):
            for k in range (3):
                self.q[i].xx[k] = (random.random() - 0.5)*box

    def vverlet_1(self,dt):
        for i in range (Npt):
            for k in range (3):
                self.q[i].xx[k] = self.q[i].xx[k] + \
                                  0.5 * dt * dt * self.q[i].ff[k]/self.q[i].xm
                self.q[i].xx[k] = self.q[i].xx[k] - \
                                  box * dnint(self.q[i].xx[k]/box)
                self.q[i].vv[k] = self.q[i].vv[k] + \
                                  0.5 * dt * self.q[i].ff[k]/self.q[i].xm
            
    def vverlet_2(self,dt):
        for i in range (Npt):
            for k in range (3):
                self.q[i].vv[k] = self.q[i].vv[k] + \
                                  0.5 * dt * self.q[i].ff[k]/self.q[i].xm
            
    def force(self):
        dx = [0., 0., 0.]
        for i in range (Npt):
            for k in range (3):
                self.q[i].ff[k] = 0.

        for i in range (Npt-1):
            for j in range (i+1, Npt):
                r2 = 0.0
                for k in range(3):
                    x = self.q[i].xx[k] - self.q[j].xx[k]
                    dx[k] = x - box * dnint(x/box)
                    r2 = r2 + dx[k]*dx[k]
                if (r2 < rcut2):
                    coef = 1./(r2*math.sqrt(r2))
                    for k in range(3):
                        self.q[i].ff[k] = self.q[i].ff[k] + coef * dx[k]
                        self.q[j].ff[k] = self.q[j].ff[k] - coef * dx[k]

    def print_snap(self, isnap):
        fname = "snapshot" + str(isnap).zfill(5) + ".xyz"
        out = open(fname,'w')
        print >> out, Npt
        print >> out, "######"
        for i in range (Npt):
            print >> out, "C ",
            for k in range (3):
                print >> out, " ", self.q[i].xx[k],
            print >> out
        out.close()

    
