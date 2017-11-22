import java.util.regex.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class  main {

  private static final String FILENAME = "funciones.txt";
  //TODO ESTO SE VA A THREADS

  // MENOS EL MAIN
  public static void main(String[] args) {
    HashMap<String,String> funcMap = new HashMap<String,String>();
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
        funcMap.put(lineSplitter[0], lineSplitter[1]);
        cantFunc--;
			}

		} catch (IOException e) {
			e.printStackTrace();
		}

    funcion test = new funcion("1*x*4+8*9+16/8-9",-1, funcMap, 5);
    System.out.println("Hello World from main!");
    Thread t = new Thread(test);
    t.start();
    try {
      t.join();
    } catch(InterruptedException e) {};

    System.out.println(test.getResult());
  }

}
