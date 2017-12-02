class Cultivo extends Thread {
  private String nombre;
  private int tasa;
  private int peso;
  private int costo;
  private int i;
  public Cultivo(String name, int rate, int precio){
    this.nombre = name;
    this.tasa = rate;
    this.costo = precio;
    this.peso = 0;
    this.i = 0;
  }

  public String getNombre() {
    return nombre;
  }

  public String getData(){
    return nombre + " ("+Integer.toString(peso)+" Kg, $"+Integer.toString(costo)+") ";
  }

  public int tLeft(){
    return i;
  }

  public void run(){
    System.out.println(nombre + " plantado!");
    while (peso < 20){
      for(i = 0; i < tasa; i++){
        try {
          Thread.sleep(1000);
        } catch(InterruptedException e) {}
      }
      System.out.println(nombre+": "+Integer.toString(peso));
      peso++;
    }
  }
}
