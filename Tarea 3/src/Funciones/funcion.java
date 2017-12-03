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
    double result = 0.0;
    String noMinus = equation.replaceAll("([\\dA-Z])-", "$1+-");
    String[] byPluses = noMinus.split("\\+");
    Double[] sumArray = new Double[byPluses.length];
    int i = 0;
    for (String multipl : byPluses) {
      funcPattern = Pattern.compile(patronFunc);
      funcMatcher = funcPattern.matcher(multipl);
      boolean flag = false;
      ArrayList<Character> last = new ArrayList<Character>();
      while (funcMatcher.find()) {
        flag = true;
        if (!last.contains(funcMatcher.group().charAt(0))){
          pMult.add(new funcion(funcMatcher.group().charAt(0),i, funcMap, val));
          pMult.lastElement().start();
          sumArray[i] = 0.0;
          last.add(funcMatcher.group().charAt(0));
        }
      }
      if(!flag) {
        result += eval(multipl); //pasarlo a threads si tiene letras
      }
      i++;
    }
    //Unir threads que calculan Funciones
    double threadResult;
    i = 0;
    while (!pMult.isEmpty()){
      i = i % pMult.size();
      try {
        pMult.get(i).join();
        threadResult = pMult.get(i).getResult();
        byPluses[pMult.get(i).getPos()] = byPluses[pMult.get(i).getPos()].replace(Character.toString(pMult.get(i).getFunc()),Double.toString(threadResult));
        funcPattern = Pattern.compile("[A-Z]");
        funcMatcher = funcPattern.matcher(byPluses[pMult.get(i).getPos()]);

        if (!funcMatcher.find()){
          result += eval(byPluses[pMult.get(i).getPos()]);
        }
        pMult.removeElementAt(i);
      } catch(InterruptedException e) {};
      i++;
    }
    //Cuando todo esté listo..

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
    result = computeAnother(funcMap.get(func));
  }
}
