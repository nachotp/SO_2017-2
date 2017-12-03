class Cultivo extends Thread {
  private String nombre;
  private int tasa;
  private int peso;
  private int costo;
  private int i;
  private boolean dead;
  public Cultivo(String name, int rate, int precio){
    this.nombre = name;
    this.tasa = rate;
    this.costo = precio;
    this.peso = 1;
    this.i = 0;
    this.dead = false;
  }

  public String getNombre() {
    return nombre;
  }

  public String getData(){
    return nombre + " ("+Integer.toString(peso)+" Kg, $"+Integer.toString(costo)+") ";
  }

  public int tLeft(){
    return tasa - i;
  }

  public boolean isDead(){
    return dead;
  }

  public int getPrecio(){
    return peso*costo;
  }

  public void run(){
    System.out.println(nombre + " ingresado con exito!");
    while (peso <= 20){
      for(i = 0; i < tasa; i++){
        try {
          Thread.sleep(1000);
        } catch(InterruptedException e) {}
      }
      peso++;
    }
    System.out.println(nombre + " ha muerto :(.");
    dead = true;
  }
}
