import java.util.regex.*;
import java.util.*;

public class funcion implements Runnable {
  String expresion;
  static int pos, val;
  double result;
  HashMap<String,String> funcMap;

  funcion(String expresion, int posi, HashMap<String,String> funcMap, int vali){
    this.expresion = expresion;
    pos = posi;
    val = vali;
    this.funcMap = funcMap;
  }

  static double computeAnother(String equation) {
    Vector<Thread> pendingMultipl;
    // Patron para encontrar funciones tipo A(x)
    String patronFunc = "[A-Z]\\(x\\)";
    Pattern funcPattern = Pattern.compile(patronFunc);
    Matcher funcMatcher;
    // Todos los X solitos reemplazados por el valor a evaluar
    equation = equation.replaceAll("(?<=[^\\(\\)])(x)", Integer.toString(val));
    System.out.println(equation);
    double result = 0.0;
    String noMinus = equation.replace("-", "+-");
    String[] byPluses = noMinus.split("\\+");
    Double[] sumArray = new Double[byPluses.length];
    int i = 0;
    for (String multipl : byPluses) {
      funcMatcher = funcPattern.matcher(multipl);
      if (funcMatcher.matches()){
        while (funcMatcher.find()) {
          System.out.println(funcMatcher.group(1));
        }
      }else {
      sumArray[i] = eval(multipl); //pasarlo a threads si tiene letras
      i++;
    }
    }
    //Cuando todo esté listo..
    for(double res : sumArray) result += res;
    return result;
  }

  public static double eval(String multipl){
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
  public double getResult(){
    return result;
  }
  public void run() {
    System.out.println("Soy un thread");
    result = computeAnother(expresion);
  }
}
