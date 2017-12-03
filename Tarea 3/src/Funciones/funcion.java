import java.util.regex.*;
import java.util.*;

public class funcion extends Thread {
  char func;
  static int val;
  int pos;
  double result;
  static HashMap<Character,String> funcMap;

  funcion(char func, int posi, HashMap<Character,String> funMap, int vali){
    this.func = func;
    pos = posi;
    val = vali;
    funcMap = funMap;
  }

  funcion(char func, int posi, HashMap<Character,String> funMap){
    this.func = func;
    pos = posi;
    funcMap = funMap;
  }

  double computeAnother(String equation) {
    Vector<funcion> pMult = new Vector<funcion>();
    // Patron para encontrar funciones tipo A
    String patronFunc = "([A-Z])";
    Pattern funcPattern = Pattern.compile(patronFunc);
    Matcher funcMatcher;
    // Todos los X solitos reemplazados por el valor a evaluar
    equation = equation.replace("x", Integer.toString(val));
    System.out.println(equation);
    double result = 0.0;
    String noMinus = equation.replace("-",  "+-");
    String[] byPluses = noMinus.split("\\+");
    Double[] sumArray = new Double[byPluses.length];
    int i = 0;
    for (String multipl : byPluses) {
      System.out.println("multiplo " + multipl);
      funcPattern = Pattern.compile(patronFunc);
      funcMatcher = funcPattern.matcher(multipl);
      boolean flag = false;
      while (funcMatcher.find()) {
        flag = true;
        System.out.println("Creando thread");
        pMult.add(new funcion(funcMatcher.group().charAt(0),i, funcMap, val));
        pMult.lastElement().start();
        sumArray[i] = 0.0;
      }
      if(!flag) {
        result += eval(multipl); //pasarlo a threads si tiene letras
      }
      i++;
    }
    //Unir threads que calculan Funciones
    double threadResult;
    i = 0;
    System.out.println("Esperando threads");
    while (!pMult.isEmpty()){
      i = i % pMult.size();
      try {
        pMult.get(i).join();
        System.out.println("Thread unido con valor "+pMult.get(i).getFunc()+" = "+Double.toString(pMult.get(i).getResult()));
        threadResult = pMult.get(i).getResult();
        byPluses[pMult.get(i).getPos()] = byPluses[pMult.get(i).getPos()].replace(Character.toString(pMult.get(i).getFunc()),Double.toString(threadResult));
        funcPattern = Pattern.compile("[A-Z]");
        funcMatcher = funcPattern.matcher(byPluses[pMult.get(i).getPos()]);
        System.out.println("Después: "+byPluses[pMult.get(i).getPos()]);

        if (!funcMatcher.find()){
          result += eval(byPluses[pMult.get(i).getPos()]);
          System.out.println("Se agrego " + " al array" );
        }
        pMult.removeElementAt(i);
      } catch(InterruptedException e) {};
      i++;
    }
    System.out.println("Threads unidos");
    //Cuando todo esté listo..

    System.out.println("Suma final de "+equation+" es "+Double.toString(result));
    return result;
  }

  public static double eval(String multipl){
    String[] byMultipl = multipl.split("\\*");
    double multiplResult = 1.0;
    for (String operand : byMultipl) {
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

  public int getPos(){
    return pos;
  }

  public char getFunc(){
    return func;
  }

  public String getStrVal(){
    return Integer.toString(val);
  }

  public void run() {
    System.out.println("Thread iniciado con funcion "+ func +" en pos "+Integer.toString(pos));
    result = computeAnother(funcMap.get(func));
  }
}
