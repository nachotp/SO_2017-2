import java.util.regex.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class  main {
  // MENOS EL MAIN
  public static void main(String[] args) {
    int m1 = 0, n1 = 0, m2 = 0, n2 = 0;
    int[][] MatA, MatB, MatC;
    MatrixProduct[][] thrd;
    //Leer archivo
    try {
      Scanner input = new Scanner (new File("matrices.txt"));
      String dimensions = input.nextLine();
      String[] dimMatrix = dimensions.split(" ");
      m1 = Character.getNumericValue(dimMatrix[0].charAt(0));
      n1 = Character.getNumericValue(dimMatrix[0].charAt(2));
      m2 = Character.getNumericValue(dimMatrix[1].charAt(0));
      n2 = Character.getNumericValue(dimMatrix[1].charAt(2));
      MatA = new int [m1][n1];
      MatB = new int [m2][n2];
      MatC = new int [m1][n2];
      thrd = new MatrixProduct[m1][n2];
      input.nextLine();
      for (int i=0;i<m1;i++){
          for (int j=0;j<n1;j++)
              MatA[i][j]= input.nextInt();
      }

      input.nextLine();

      for (int i=0;i<m2;i++){
          for (int j=0;j<n2;j++)
              MatB[i][j]= input.nextInt();
      }

      for(int i=0;i<m1;i++){
       for(int j=0;j<n2;j++){
          thrd[i][j]= new MatrixProduct(MatA,MatB,MatC,i,j,n1);
          thrd[i][j].start();
        }
      }

      for(int i=0;i<m1;i++){
       for(int j=0;j<n2;j++){
        try{
            thrd[i][j].join();
          } catch(InterruptedException e){}
        }
      }
      PrintWriter writer = new PrintWriter("resultado.txt");

      writer.print(m1);
      writer.print('x');
      writer.print(n2);
      writer.println();
      for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            writer.print(MatC[i][j] + " ");
        }
        writer.println();
      }
    writer.close();
    } catch (FileNotFoundException e) {
          e.printStackTrace();
    }

  }
}
