import java.util.regex.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class  main {

  private static final String FILENAME = "funciones.txt";
  //TODO ESTO SE VA A THREADS
  static double computeAnother(int val, HashMap<String,String> funcMap, String equation) {
    equation.replaceAll("[^\\(\\)](x)", Integer.toString(val));
    double result = 0.0;
    String noMinus = equation.replace("-", "+-");
    String[] byPluses = noMinus.split("\\+");
    Double[] sumArray = new Double[byPluses.length];
    int i = 0;
    for (String multipl : byPluses) {
      sumArray[i] = eval(funcMap, multipl); //pasarlo a threads si tiene letras
      i++;
    }
    //Cuando todo esté listo..
    for(double res : sumArray) result += res;
    return result;
  }

  public static double eval(HashMap<String,String> funcMap, String multipl){
    String[] byMultipl = multipl.split("\\*");
    double multiplResult = 1.0;
    for (String operand : byMultipl) {
        System.out.println(operand);
        if (operand.contains("/")) {
            String[] division = operand.split("\\/");
            double divident = Double.parseDouble(division[0]);
            for (int i = 1; i < division.length; i++) {
                divident /= Double.parseDouble(division[i]);
            }
            multiplResult *= divident;
        } else {
            multiplResult *= Double.parseDouble(operand);
        }
    }
    return multiplResult;
  }
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

    System.out.println("Hello World from main!");
    new Thread(new funcion()).start();
    System.out.println(computeAnother(5,funcMap, "1*x*4+8*9+16/8-9"));
  }

}
