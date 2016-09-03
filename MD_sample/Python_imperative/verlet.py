from md    import Npt, box, Particle
from force import dnint

def vverlet_1(q,dt):
    for i in range (Npt):
        for k in range (3):
            q[i].xx[k] = q[i].xx[k] + 0.5 * dt * dt * q[i].ff[k]/q[i].xm
            q[i].xx[k] = q[i].xx[k] - box * dnint(q[i].xx[k]/box)
            q[i].vv[k] = q[i].vv[k] + 0.5 * dt * q[i].ff[k]/q[i].xm
            
def vverlet_2(q,dt):
    for i in range (Npt):
        for k in range (3):
            q[i].vv[k] = q[i].vv[k] + 0.5 * dt * q[i].ff[k]/q[i].xm
            
