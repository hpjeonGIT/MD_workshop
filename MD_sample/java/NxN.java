import java.lang.Math;
import java.util.*;
import java.io.*;
import java.lang.Double;
// ref: http://www.nbabel.org/codes/10
// javac NxN.java
// time java NxN
public class NxN{
    public static void main(String[] args) {
	int iter = 0;
	MD sim = new MD();
	sim.data_read();
	while(iter < sim.Nmax){
	    sim.vverlet_1();
	    sim.force();
	    sim.vverlet_2();
	    if (iter % 100 ==0) {
		sim.xyz_export(iter);
	    }
	    iter++;
	}
    }
}


class MD{
    int Npt, Nmax;
    double dt, box, rcut2;
    Particle[] q;
    public MD(){
	this.Npt   = 1000;
	this.Nmax  = 1000;
	this.dt    = 0.1;
	this.box   = 10.0;
	this.rcut2 = 3.0*3.0;
	this.q     = new Particle[this.Npt];
	for (int i=0; i<this.Npt; i++) {
	    this.q[i] = new Particle();
	}
	    
    }; // constructor
    public double dnint(double x) {
	int y;
	if (x > 0.0){
	    y = (int)(x +0.5);
	} else {
	    y = (int)(x - 0.5);
	}
	return (double) y;
    }
    public void data_read(){
 	for (int i=0;i< this.Npt; i++){
	    for (int k=0;k< 3; k++) {
		this.q[i].xx[k] = Math.random()*this.box;
		this.q[i].vv[k] = 0.0;
		this.q[i].ff[k] = 0.0;
		this.q[i].xm    = 1.0;
	    }
	}
    }
    public void vverlet_1(){
	for (int i=0;i< this.Npt; i++){
	    for (int k=0;k< 3; k++) {
		this.q[i].xx[k] += this.dt*this.q[i].vv[k] +
		    0.5*this.dt*this.dt*this.q[i].ff[k]/this.q[i].xm;
		this.q[i].xx[k] -= this.box * dnint(this.q[i].xx[k]/this.box);
		this.q[i].vv[k] += 0.5*this.dt*this.q[i].ff[k]/this.q[i].xm;
	    }
	}
    }
    public void vverlet_2(){
	for (int i=0;i< this.Npt; i++){
	    for (int k=0;k< 3; k++) {
		this.q[i].vv[k] += 0.5*this.dt*this.q[i].ff[k]/this.q[i].xm;
	    }
	}
    }
    public void force() {
	double[] dx = new double[3];
	// initialize
	for (int i=0; i< this.Npt; i++) {
	    for (int k=0;k<3;k++) {
		this.q[i].ff[k] = 0.0;
	    }
	}
	// Pair interaction
	for (int i=0;i< this.Npt-1; i++){
	    for (int j=i+1; j< this.Npt; j++){
		double r2 = 0.0;
		for (int k=0;k< 3; k++) {
		    double x = this.q[i].xx[k] - this.q[j].xx[k];
		    dx[k] = x - this.box * dnint(x/this.box);
		    r2 += dx[k]*dx[k];
		}
		if (r2 < this.rcut2) {
		    double coef = 1./(r2*Math.sqrt(r2));
		    for (int k=0; k<3; k++) {
			this.q[i].ff[k] += coef * dx[k];
			this.q[j].ff[k] -= coef * dx[k];
		    }
		}
	    }
	}
    }
    public void xyz_export(int iter) {
	String fname = "snapshot"+Integer.toString(iter) + ".xyz";
	PrintWriter f = null;
	try {
	    f = new PrintWriter(new File(fname));
	} catch (FileNotFoundException fnfError) {
	    fnfError.printStackTrace();
	}
	StringBuilder builder = new StringBuilder();
	builder.append(Integer.toString(this.Npt) + "\n");
	builder.append("## header \n");
	for(int i=0; i< this.Npt;i++) {
	    builder.append(Integer.toString(i) + " " +
			   Double.toString(this.q[i].xx[0])  + " " +
			   Double.toString(this.q[i].xx[1])  + " " +
			   Double.toString(this.q[i].xx[2])  + "\n");
	}
	f.write(builder.toString());
	f.close();
    }
}

class Particle{
    double xm;
    double[] xx, vv, ff;
    public Particle(){  //constructor
	xx = new double[3];
	vv = new double[3];
	ff = new double[3];
	//System.out.println("constructing particles");
    }
}
