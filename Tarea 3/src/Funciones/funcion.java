import java.util.regex.*;
import java.util.*;

public class funcion implements Runnable {
  String func;
  static int val;
  int pos;
  double result;
  static HashMap<String,String> funcMap;

  funcion(String func, int posi, HashMap<String,String> funMap, int vali){
    this.func = func;
    pos = posi;
    val = vali;
    funcMap = funMap;
  }

  funcion(String func, int posi, HashMap<String,String> funMap){
    this.func = func;
    pos = posi;
    funcMap = funMap;
  }

  static double computeAnother(String equation) {
    System.out.println(equation);
    Vector<Thread> pendingMultipl = new Vector<Thread>();
    Vector<funcion> funcList = new Vector<funcion>();
    // Patron para encontrar funciones tipo A(x)
    String patronFunc = "[A-Z]\\(\\d+\\)";
    Pattern funcPattern = Pattern.compile(patronFunc);
    Matcher funcMatcher;
    // Todos los X solitos reemplazados por el valor a evaluar
    equation = equation.replaceAll("x", Integer.toString(val));
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
        funcList.add(new funcion(funcMatcher.group().charAt(0)+"(x)",i, funcMap, val));
        pendingMultipl.add(new Thread(funcList.lastElement()));
        pendingMultipl.lastElement().start();
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
    while (!pendingMultipl.isEmpty()){
      i = i % funcList.size();
      try {
        pendingMultipl.get(i).join();
        System.out.println("Thread unido con valor "+funcList.get(i).getFunc()+" = "+Double.toString(funcList.get(i).getResult()));
        threadResult = funcList.get(i).getResult();
        System.out.println("Antes " + byPluses[funcList.get(i).getPos()]);
        byPluses[funcList.get(i).getPos()] = byPluses[funcList.get(i).getPos()].replace(funcList.get(i).getFunc().charAt(0)+"("+funcList.get(i).getStrVal()+")",Double.toString(threadResult));
        funcPattern = Pattern.compile("[A-Z]");
        funcMatcher = funcPattern.matcher(byPluses[funcList.get(i).getPos()]);
        System.out.println("Después: "+byPluses[funcList.get(i).getPos()]);

        if (!funcMatcher.find()){
          result += eval(byPluses[funcList.get(i).getPos()]);
          System.out.println("Se agrego " + " al array" );
        }
        pendingMultipl.removeElementAt(i);
        funcList.removeElementAt(i);
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

  public String getFunc(){
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
