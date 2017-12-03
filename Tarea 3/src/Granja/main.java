import java.util.*;

public class  main {
  static Vector<Cultivo> cultivos;

  public static int menu(){
    Scanner scanner = new Scanner(System.in);
    System.out.println("Ingrese alguna de las siguientes opciones:");
    System.out.println("1.- Cultivar");
    System.out.println("2.- Ver Cultivos");
    System.out.println("3.- Comprar Cultivos");
    System.out.println("4.- Salir");
    int i = scanner.nextInt();
    return i;
  }

  public static Cultivo nuevoCultivo(){
    Scanner scanner = new Scanner(System.in);
    String nombre;
    int rate, ck;
    System.out.println("Ingresar Nombre del Cultivo:");
    System.out.print("> ");
    nombre = scanner.nextLine();
    System.out.println("Ingresar Tiempo de Crecimiento (Segundos):");
    System.out.print("> ");
    rate = scanner.nextInt();
    System.out.println("Ingresar Costo por Kilo:");
    System.out.print("> ");
    ck = scanner.nextInt();

    return new Cultivo(nombre, rate, ck);
  }

  public static void clean(){
    List<Cultivo> remover = new ArrayList<>();;
    if (cultivos.size() > 0){
      for (Cultivo cl : cultivos){
        if(cl.isDead()){
          cl.stop();
          remover.add(cl);
        }
      }
      cultivos.removeAll(remover);
    }
  }

  public static void main(String[] args) {
    //Leer archivo
    int i, id, pago, opt = 0;
    Scanner scanner = new Scanner(System.in);
    cultivos = new Vector<Cultivo>();
    Cultivo tmpClt;
    System.out.println("Bienvenido a la Granja Radioactiva!");
    while (opt != 4){
      opt = menu();
      if (opt == 1){
        cultivos.add(nuevoCultivo());
        cultivos.lastElement().start();
      } else if (opt == 2){
        clean();
        System.out.println();
        i = 1;
        if
        System.out.println("Los cultivos que hay son:");
        for (Cultivo cl : cultivos){
          System.out.print(Integer.toString(i)+".- ");
          System.out.println(cl.getData()+" que crecerá en "+Integer.toString(cl.tLeft())+" segundos.");
          i++;
        }
        System.out.println();
      } else if (opt == 3){
        System.out.println("Ingrese ID del cultivo a comprar:");
        System.out.print("> ");
        id = scanner.nextInt();
        System.out.println("Ingrese el dinero a pagar:");
        System.out.print("> ");
        pago = scanner.nextInt();
        tmpClt = cultivos.get(id-1);
        if (tmpClt.getPrecio() <= pago){
          System.out.println("Compra de "+tmpClt.getNombre()+" exitosa!");
          tmpClt.stop();
          cultivos.remove(id-1);
        } else {
          System.out.println("Monto insuficiente para comprar "+tmpClt.getNombre()+" :(");
          System.out.println();
        }
      }
    }

    for (Cultivo cl : cultivos){
      cl.stop();
    }
  }

}
