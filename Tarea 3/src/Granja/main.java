import java.util.*;

public class  main {
  static Vector<Cultivo> cultivos;

  public static void main(String[] args) {
    //Leer archivo
    Cultivo clt = new Cultivo("Thomotes",5,1);
    //cultivos.add(new Cultivo("Thomotes",5,1));
    //cultivos.lastElement().start();
    clt.start();
    try {
      clt.join();
    } catch(InterruptedException e) {}
  }

}
