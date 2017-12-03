import java.util.regex.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class  main {

  private static final String FILENAME = "funciones.txt";

  // MENOS EL MAIN
  public static void main(String[] args) {
    HashMap<Character,String> funcMap = new HashMap<Character,String>();
    String[] lineSplitter;

    //Leer archivo
    try (BufferedReader br = new BufferedReader(new FileReader(FILENAME))) {
			String sCurrentLine;
      int cantFunc = Integer.parseInt(br.readLine());
      br.readLine();
			while (cantFunc > 0) {
        sCurrentLine = br.readLine();
				lineSplitter = sCurrentLine.split("=");
        //Cargar funciones al map
        funcMap.put(lineSplitter[0].charAt(0), lineSplitter[1].replace("(x)",""));
        cantFunc--;
			}
		} catch (IOException e) {
			e.printStackTrace();
		}

    System.out.println("Funciones Ingresadas!");

    //Comienza el programa
    funcion mainFunc;
    Scanner scanner = new Scanner(System.in);
    String patronFunc = "([A-Z])\\((\\d+)\\)";
    Pattern funcPattern = Pattern.compile(patronFunc);
    Matcher funcMatcher;

    System.out.println("Ingrese una operación o escriba salir:");
    System.out.print("> ");
    String op = scanner.nextLine();

    while (!op.equals("salir")){
      funcMatcher = funcPattern.matcher(op);
      if(funcMatcher.find()){
        funcion test = new funcion(funcMatcher.group(1).charAt(0),-1, funcMap, Integer.parseInt(funcMatcher.group(2)));
        test.start();
        try {
          test.join();
          System.out.println("El resultado de "+funcMatcher.group(1)+"("+funcMatcher.group(2)+") es "+Double.toString(test.getResult()));
          System.out.println();
        } catch(InterruptedException e) {};
      }
      System.out.println("Ingrese una operación o escriba salir:");
      System.out.print("> ");
      op = scanner.nextLine().trim();
    }

  }

}
