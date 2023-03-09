package Ex_1;

public class Parabola {
    private int a, b, c;

    public Parabola(int a, int b, int c){
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public float getX(){
        return -((float)b/(2*a));
    }

    public float getY(){
        return (float)((-b*b)+(4*a*c))/(4*a);
    }

   public Punct middleSegment(Parabola par){
        return new Punct((this.getX() + par.getY())/2, (this.getY() + par.getY())/2);
   }

   public static Punct middleSegment2(Parabola par1, Parabola par2){
        return new Punct((par1.getX() + par2.getX())/2, (par1.getY() + par2.getY())/2);
   }

   public double lenghtSegment(Parabola par){
        return Math.hypot((par.getX() - this.getX()),(par.getY()) - this.getY());
   }

   public static double lenghtSegment2(Parabola par1, Parabola par2){
        return Math.hypot((par2.getX() - par1.getX()),(par2.getY()) - par1.getY());
   }
    @Override
    public String toString(){
        return "f(x)=" + a + "x^2+" + b + "x+" + c;
    }
}
