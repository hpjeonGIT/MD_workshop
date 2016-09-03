from md import Npt

def print_snap(isnap,q):
    fname = "snapshot" + str(isnap).zfill(5) + ".xyz"
    out = open(fname,'w')
    print >> out, Npt
    print >> out, "######"
    for i in range (Npt):
        print >> out, "C ",
        for k in range (3):
            print >> out, " ", q[i].xx[k],
        print >> out
    out.close()

    
