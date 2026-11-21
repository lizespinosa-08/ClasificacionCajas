package Java;

public class Caja extends Elemento {

    // Atributos propios de la caja
    private double ancho;
    private double alto;
    private double profundidad;
    private double volumen;
    private String banda;

    // Constructor de la clase Caja
    public Caja(String codigo, double ancho,
                double alto, double profundidad) {

        super(codigo);

        this.ancho = ancho;
        this.alto = alto;
        this.profundidad = profundidad;
        this.volumen = 0;
        this.banda = "";
    }

    // calcular el volumen
    public void calcularVolumen() {
        volumen = ancho * alto * profundidad;
    }

    // clasificar la caja
    public void clasificar() {

        if (volumen > 500) {
            banda = "BANDA A";
        } else {
            banda = "BANDA B";
        }
    }

    @Override
    public void mostrarInformacion() {

        System.out.println("\nCodigo: " + getCodigo());
        System.out.println("Ancho: " + ancho + " cm");
        System.out.println("Alto: " + alto + " cm");
        System.out.println("Profundidad: " + profundidad + " cm");
        System.out.println("Volumen: " + volumen + " cm3");
        System.out.println("Destino: " + banda);
    }

    // banda asignada
    public String getBanda() {
        return banda;
    }

    // Consultar el volumen
    public double getVolumen() {
        return volumen;
    }
}
