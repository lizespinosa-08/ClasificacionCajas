public abstract class Elemento {

    protected String codigo;

    // Constructor superclase
    public Elemento(String codigo) {
        this.codigo = codigo;
    }

    public String getCodigo() {
        return codigo;
    }
    public abstract void mostrarInformacion();
}
