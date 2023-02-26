package Ex_1;
public class Dreptunghi {
    private float latime;
    private float lungime;

    public Dreptunghi(float latime, float lungime) {
        this.latime = latime;
        this.lungime = lungime;
    }

    public float perimetru(float latime, float lungime){
        float perimetru = (2*latime) + (2*lungime);
        return perimetru;
    }

    public float aria(float latime, float lungime){
        return (latime * lungime);
    }

}
