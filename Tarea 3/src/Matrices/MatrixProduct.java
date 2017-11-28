class MatrixProduct extends Thread {
      private int[][] A;
      private int[][] B;
      private int[][] C;
      private int rig,col;
      private int dim;

      public MatrixProduct(int[][] A,int[][] B,int[][] C,int rig, int col,int dim_com)
      {
         this.A=A;
         this.B=B;
         this.C=C;
         this.rig=rig;
         this.col=col;
         this.dim=dim_com;
      }

     public void run()
     {
         for(int i=0;i<dim;i++){
               C[rig][col]+=A[rig][i]*B[i][col];
         }
          System.out.println("Thread "+rig+","+col+" complete.");
     }
 }
