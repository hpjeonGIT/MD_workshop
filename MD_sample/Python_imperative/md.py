Npt   = 100
rcut  = 9.0
rcut2 = rcut*rcut
box   = 20.0
mass  = 10.0

class Particle():
    def __init__(self):
        self.xx = [0., 0., 0.]
        self.vv = [0., 0., 0.]
        self.ff = [0., 0., 0.]
        self.xm = mass;
